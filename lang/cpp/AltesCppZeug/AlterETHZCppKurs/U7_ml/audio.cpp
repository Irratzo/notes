/********************************************************************
	purpose:	A simple PCM Wave File Editing TOOL

	created:	2010/11/08
	filename: 	audio_tmpl.cpp
	author:		

*********************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <limits.h>
#include <stdlib.h>

using namespace std;

struct WAVEHEADER {
	char	ChunkID[4];	//          Contains the letters "RIFF" in ASCII form
	int		ChunkSize;
	int		Format;
	char	Subchunk1ID[4];
	int		Subchunk1Size;
	short	AudioFormat;
	short	NumChannels;
	int		SampleRate;
	int		ByteRate;
	short	BlockAlign;
	short	BitsPerSample;
	char	Subchunk2ID[4];
	int		Subchunk2Size;
};

//---------------------------------------------------------
// helper functions
//---------------------------------------------------------


/*
* Gibt wave file header Informationen in der Console aus;
* \param hdr: wavefile hdr
*/
void printWaveHeaderInfos( WAVEHEADER *hdr) {
	if(NULL == hdr) {
		cerr << "Keine Waveheaderinformationen gefunden" << endl;
	}

	// outpout
	// codec, sampling rate, sampling precision, channels, length

	string codec;
	
	switch (hdr->AudioFormat) {
		case 1: codec = "PCM"; break;
		case 2: codec = "unknown compression"; break;
	}

	cout << "Codec: " << codec;
	cout << ", sampling rate: " << hdr->SampleRate;
	cout << ", sampling precision: " << hdr->BitsPerSample;
	cout << ", channels: " << hdr->NumChannels;
	cout << ", lengths: " << hdr->Subchunk2Size * 8.0 / hdr->BitsPerSample / hdr->NumChannels / hdr->SampleRate << "sec." ;
	cout << endl;
}

/*
 * Liest den Waveheader und checked ob das Format unterstuetzt wird;
 * \param fin: ifstream.
 * \return: NULL in case of error, waveheader else
 */
WAVEHEADER *readWaveHeader(ifstream *fin) {
	WAVEHEADER *hdr = NULL;

	//benutze die read Funktion um binaere Daten zu lesen
	hdr = new WAVEHEADER;

	fin->read((char*)hdr, sizeof(WAVEHEADER));

	if(fin->eof() || fin->fail() || fin->bad() ) {
		delete hdr;
		hdr = NULL;
	}

	printWaveHeaderInfos(hdr);

	// check if compatible
	if( hdr->AudioFormat != 1 ||
		hdr->SampleRate != 44100 ||
		hdr->BitsPerSample != 16 ||
		hdr->NumChannels != 1 ) {
			cerr << "This WAV File is not supported by this tool!" << endl;
			delete hdr;
			return NULL;
	}

	return hdr;
}

/*
 * Schreibt den Waveheader
 * \param fin: ifstream.
 * \param hdr: wavefile hdr
 * \return: false in case of an write error
 */
bool writeWaveHeader(ofstream *fout, WAVEHEADER *hdr) {

	if(NULL == hdr)
		return false;

	//benutze die write Funktion um binaere Daten zu schreiben
	fout->write((char*)hdr, sizeof(WAVEHEADER));

	if(fout->eof() || fout->fail() || fout->bad() ) {
		return false;
	}

	return true;
}


//---------------------------------------------------------
// Commands
//---------------------------------------------------------

/*
 * Fuer den Commando -info
 * \param fin: ifstream.
 */
void waveFileInfo( char * filename ) {

	//oeffne die Datei filename als binaere Datei (fin)
	ifstream fin(filename, ios::in | ios::binary);

	if( !fin.is_open() ) {
		cerr << filename << "not found." << endl;	
	} else {
		WAVEHEADER *hdr = readWaveHeader(&fin);
		delete hdr;
	}
} 


void convertWaveFile( char infile[], char outfile[] )  
{
	cout << "Try to convert wavefile to text:" << endl;

	ifstream fin(infile, ios::in | ios::binary);
	ofstream fout(outfile);

	if( !fin.is_open() ||  !fout.is_open() ) {
		cerr << "input or output FILE could not be found." << endl;	
	} else {
		WAVEHEADER *hdr = readWaveHeader(&fin);
		if(NULL == hdr) {
			cerr << "Fileformat not supported";
			return;
		}

		unsigned int nbrSamples = hdr->Subchunk2Size * 8 / hdr->BitsPerSample / hdr->NumChannels;
		
		for (unsigned int i = 0; i < nbrSamples; i++) {
			short s;
			fin.read((char*)&s, sizeof(s));
			fout << s << endl;
		}
		
		delete hdr;
	}

	cout << "done" << endl;

}



void volumeWaveFile( char infile[], char outfile[], double gain )  
{
	cout << "Change Volume:" << endl;

	ifstream fin(infile, ios::in | ios::binary);
	ofstream fout(outfile, ios::out | ios::binary);

	if( !fin.is_open() ||  !fout.is_open() ) {
		cerr << "input or output FILE could not be found." << endl;	
	} else {
		WAVEHEADER *hdr = readWaveHeader(&fin);
		if(NULL == hdr) {
			cerr << "Fileformat not supported";
			return;
		}

		writeWaveHeader(&fout, hdr);

		unsigned int nbrSamples = hdr->Subchunk2Size * 8 / hdr->BitsPerSample / hdr->NumChannels;

		for (unsigned int i = 0; i < nbrSamples; i++) {
			short s;
			fin.read((char*)&s, sizeof(s));
			double d = s * gain;

			if( d > SHRT_MAX )
				d = SHRT_MAX;
			if (d < SHRT_MIN )
				d = SHRT_MIN;

			s  = (short) (d);

			fout.write((char*)&s, sizeof(s));
		}

		delete hdr;
	}

	cout << "done" << endl;
}

void mixWaveFiles( char infile1[], char infile2[], char outfile[] )  
{
	cout << "Mix 2 audio files:" << endl;

	ifstream fin1(infile1, ios::in | ios::binary);
	ifstream fin2(infile2, ios::in | ios::binary);
	ofstream fout(outfile, ios::out | ios::binary);

	if( !fin1.is_open() ||  !fin2.is_open() || !fout.is_open() ) {
		cerr << "input or output FILE could not be found." << endl;	
	} else {
		WAVEHEADER *hdr1 = readWaveHeader(&fin1);
		WAVEHEADER *hdr2 = readWaveHeader(&fin2);
		
		if(NULL == hdr1 || NULL == hdr2) {
			cerr << "Fileformat not supported";
			return;
		}

		unsigned int nbrSamples1 = hdr1->Subchunk2Size * 8 / hdr1->BitsPerSample / hdr1->NumChannels;
		unsigned int nbrSamples2 = hdr2->Subchunk2Size * 8 / hdr2->BitsPerSample / hdr2->NumChannels;

		unsigned int samplesmax;

		if(nbrSamples1 > nbrSamples2) {
			writeWaveHeader(&fout, hdr1);
			samplesmax = nbrSamples1;
		} else {
			writeWaveHeader(&fout, hdr2);
			samplesmax = nbrSamples2;
		}

		unsigned int i = 0;
		unsigned int n = 0,k = 0;

		while(i < samplesmax) {
			short s1, s2;
			fin1.read((char*)&s1, sizeof(short));
			fin2.read((char*)&s2, sizeof(short));

			double d = s1 + s2;

			if( d > SHRT_MAX )
				d = SHRT_MAX;
			if (d < SHRT_MIN )
				d = SHRT_MIN;

			s1  = (short) (d);

			fout.write((char*)&s1, sizeof(short));

			i++;
			n++;k++;

			// Testen ob eine Datei am Ende ist,
			// wenn ja den Filecursor wieder
			// an den Anfang der Samples setzen
			if(k >= nbrSamples1) {
				fin1.clear();
				fin1.seekg(sizeof(WAVEHEADER), ios::beg);
				k = 0;
			}
			if(n >= nbrSamples2) {
				fin2.clear();
				fin2.seekg(sizeof(WAVEHEADER), ios::beg);
				n = 0;
			}

		}
		delete hdr1;
		delete hdr2;

	}

	cout << "done" << endl;
}


void echoWaveFile( char infile[], char outfile[], double delay, double gain )  
{
	cout << "Add echo:" << endl;

	ifstream fin(infile, ios::in | ios::binary);
	ofstream fout(outfile, ios::out | ios::binary);

	if( !fin.is_open()|| !fout.is_open() ) {
		cerr << "input or output FILE could not be found." << endl;	
	} else {
		WAVEHEADER *hdr = readWaveHeader(&fin);

		if(NULL == hdr) {
			cerr << "Fileformat not supported";
			return;
		}

		unsigned int nbrSamples = hdr->Subchunk2Size * 8 / hdr->BitsPerSample / hdr->NumChannels;
		unsigned int bsize = delay * hdr->SampleRate;

		if(bsize >= nbrSamples) {
			cerr << "Error: Delay is longer than input file duartion" << endl;
			return;
		}

		// die Groesse des Buffers ist genau delay viele samples
		short *ringbuffer = new short[bsize];

		//initialize ringbuffer mit 0
		for(unsigned int i = 0; i < bsize; i++)
			ringbuffer[i] = 0;

		writeWaveHeader(&fout, hdr);
		
		for (unsigned int i = 0; i < nbrSamples; i++) {
			short s;
			fin.read((char*)&s, sizeof(s));

			//put
			ringbuffer[i % bsize] = s;

			// Anmerkung: das naechste Element im Buffer
			// ist das Element das schon am laengsten drinn
			// ist. Da der buffer genau so gross ist wie unser delay
			// ist das genau jenes welches wir wollen.
			double d = s + ringbuffer[(i+1) % bsize] * gain;

			if( d > SHRT_MAX )
				d = SHRT_MAX;
			if (d < SHRT_MIN )
				d = SHRT_MIN;

			s  = (short) (d);

			fout.write((char*)&s, sizeof(s));

		}

		delete hdr;
		delete [] ringbuffer;
	}
}

//---------------------------------------------------------
// main
//---------------------------------------------------------
int main(int argc, char *argv[])
{
	
	const char *command = "-info";
	char **parms = &argv[1];
	int parms_count = argc - 1;

	if(argc > 1 && argv[1][0] == '-') {
		command = argv[1];
		parms = &argv[2];
		parms_count--;
	}


	// -info command standard case prints info of the given file
	if(!strcmp(command, "-info")) {
		if(parms_count >= 1) {
			waveFileInfo(parms[0]);
			return 0;
		} else {
			cerr << "Call " << endl;
			cerr << argv[0] << " [-info] wavefile" << endl;
			cerr << argv[0] << " -help : \tfor more help" << endl;
			return 1;
		}
	}

	// -help command
	if(!strcmp(command, "-help")) {
		cout << "Help:" << endl;
		cout << argv[0] << " -totext wavfile_in  textfile_out" << endl;
		cout << argv[0] << " -volume gain wavfile_in  wavfile_out" << endl;
		cout << argv[0] << " -mix    wavfile1_in wavfile2_in  wavfile_out" << endl;
		cout << argv[0] << " -echo   delay strength wavfile_in wavfile_out" << endl;

		return 0;
	}

	/* TODO other commands */
	
	// -totext command
	if(!strcmp(command, "-totext")) {
		if(parms_count >= 2) {
			convertWaveFile( parms[0], parms[1]);
			return 0;
		} else {
			cerr << "Not enough paramters" << endl;
			return 1;
		}
	
	}

	// -vol command
	if(!strcmp(command, "-volume")) {
		if(parms_count >= 3) {
			volumeWaveFile( parms[1], parms[2], atof(parms[0]));
			return 0;
		} else {
			cerr << "Not enough paramters" << endl;
			return 1;
		}

	}

	// -mix command
	if(!strcmp(command, "-mix")) {
		if(parms_count >= 3) {
			mixWaveFiles( parms[0], parms[1], parms[2]);
			return 0;
		} else {
			cerr << "Not enough paramters" << endl;
			return 1;
		}

	}

	// -echo command
	if(!strcmp(command, "-echo")) {
		if(parms_count >= 4) {
			echoWaveFile( parms[2], parms[3], atof(parms[0]), atof(parms[1]));
			return 0;
		} else {
			cerr << "Not enough paramters" << endl;
			return 1;
		}

	}


	return 0;
}
