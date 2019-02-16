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
  char	Subchunk1ID[4];             //contains the letters "WAVE" in ASCII form
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

  /* TODO */
  if (hdr->AudioFormat == 1) {

    //determine length in seconds
    float seconds = 0;
    seconds = 1.0 * hdr->Subchunk2Size / hdr->ByteRate;

    cout << "Codec: " << "PCM" << ", " << hdr->SampleRate << " Hz, " << hdr->BitsPerSample << "bit, " << hdr->NumChannels <<  " channel: Length " << seconds << " sec" << endl;
  } else {
    cout << "Codec not PCM but compressed; no further output" << endl;
  }
}

/*
 * Liest den Waveheader und checkt ob das Format unterstuetzt wird;
 * \param fin: ifstream.
 * \return: NULL in case of error, waveheader else
 */
WAVEHEADER *readWaveHeader(ifstream *fin) {
  WAVEHEADER *hdr = NULL;

  //benutze die read Funktion um binaere Daten zu lesen
  hdr = new WAVEHEADER;

  /* TODO */
  //lese datenblock von groesse sizeof, speichere in array pointed by hdr
  fin->read((char *) hdr, sizeof *hdr);

  if (hdr->AudioFormat !=1 || hdr->SampleRate != 44100 || hdr->BitsPerSample != 16 || hdr->NumChannels != 1) {
    cout << "Only this format accepted: Code: PCM, 44100 Hz, 16bit, 1 channel" << endl; 
    delete hdr;
  }
  else {
    printWaveHeaderInfos(hdr);
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

  /* TODO */
  // save hdr into file

  //From Reference: ostream& write ( const char* s , streamsize n );
  fout->write((const char*)hdr, 44);
  //The header is 44 bytes long for the accepted format
  //fout->write((const char*)hdr->Format, sizeof(int)); produces segfault

  //If something goes wrong
  if (fout->eof() || fout->fail() || fout->bad())
    return false;
  else
    return true;
}


//---------------------------------------------------------
// Commands
//---------------------------------------------------------

/*
 * Fuer den Commando -info
 * \param fin: ifstream.
 */
void waveFileInfo( char * filename) {

  //oeffne die Datei filename als binaere Datei (fin)
  ifstream fin(filename, ios::in | ios::binary);

  if( !fin.is_open() ) {
    cerr << filename << " not found." << endl;	
  } else {
    WAVEHEADER *hdr = readWaveHeader(&fin);
    delete hdr;
  }
} 


void convertWaveFile( char infile[], char outfile[] )  
{
  cout << "Trying to convert wavefile to text:" << endl;

  //open streams, with postconditions
  ifstream fin(infile,ios::in);
  ofstream fout(outfile,ios::out);
  if( !fin.is_open() ) {
    cerr << "Problem with reading the file.";
  } else {
    //read in the WAVEHEADER to get file info, with postconditions
    //this also sets the read pointer to the end of the header
    WAVEHEADER *hdr = readWaveHeader(&fin);
    if(NULL == hdr) {
      cerr << "No Waveheader found." << endl;
    }

    //Determine NumSamples (see also documentation)
    int NumSamples = 0;
    short s = 0;
    NumSamples = (hdr->Subchunk2Size * 8) / (hdr->NumChannels * hdr->BitsPerSample);

    //read from stream, one sample (2 bits) at a time
    for (int i = 0; i < NumSamples; i++) {
      //    istream& seekg(44, ios::seekdir dir);
      fin.read((char*)&s,sizeof(short));
      // output unformatted, i.e. char (istream & (const char,...
      fout << s << endl;
    }
    //free memory
    delete hdr;
  }

  /* TODO */
  cout << "done" << endl;
}



void volumeWaveFile( char infile[], char outfile[], double gain )  
{
  cout << "Changing Volume:" << endl;

  //open streams in binary , with postconditions
  ifstream fin(infile,ios::in|ios::binary);
  ofstream fout(outfile,ios::out|ios::binary);
  if( !fin.is_open() ) {
    cerr << "Problem with reading the file.";
  } else {
    //read in the WAVEHEADER to get file info, with postconditions
    //this also sets the read pointer to the end of the header
    //Q: does this have problems with ios::binary? Apparently not.
    WAVEHEADER *hdr = readWaveHeader(&fin);
    if(NULL == hdr) {
      cerr << "No Waveheader found." << endl;
    }

    //Determine NumSamples (see also documentation)
    int NumSamples = 0;
    short s = 0;
    double sd = 0.0;
    NumSamples = (hdr->Subchunk2Size * 8) / (hdr->NumChannels * hdr->BitsPerSample);


    //write WaveHeader first, with postcondition
    bool written = 0; 
    written = writeWaveHeader(&fout,hdr);
    if (!written)
      cerr << "Error: WaveHeader not written." << endl;	

    //read from stream and write, one sample (2 bytes) at a time
    for (int i = 0; i < NumSamples; i++) {

      fin.read((char*)&s,sizeof(short));
      sd = (double)s;
      sd *= gain;
      s = (short)sd;

      // output unformatted, i.e. char (istream & (const char,...
      //      fout << s << endl;
      fout.write((char*)&s,sizeof(short));
    }
    //free memory
    delete hdr;
  }

  /* TODO */
  cout << "done" << endl;
}

void mixWaveFiles( char infile1[], char infile2[], char outfile[] )  
{
  cout << "Mixing 2 audio files:" << endl;
 
  //open streams in binary , with postconditions
  ifstream fin1(infile1,ios::in|ios::binary);
  ifstream fin2(infile2,ios::in|ios::binary);
  ofstream fout(outfile,ios::out|ios::binary);
  if( !fin1.is_open() ) {
    cerr << "Problem with reading the first file.";
  } else {
    if( !fin2.is_open() ) {
      cerr << "Problem with reading the second file.";
    } else {

      //read in the WAVEHEADER to get file info, with postconditions
      //this also sets the read pointer to the end of the header
      //Q: does this have problems with ios::binary? Apparently not.
      WAVEHEADER *hdr1 = readWaveHeader(&fin1);
      if(NULL == hdr1) {
	cerr << "No Waveheader of first file found." << endl;
      }

      WAVEHEADER *hdr2 = readWaveHeader(&fin2);
      if(NULL == hdr2) {
	cerr << "No Waveheader ob second file found." << endl;
      }

      //Determine NumSamples to see which file is longer
      int NumSamples1 = 0;
      NumSamples1 = (hdr1->Subchunk2Size * 8) / (hdr1->NumChannels * hdr1->BitsPerSample);
      int NumSamples2 = 0;
      NumSamples2 = (hdr2->Subchunk2Size * 8) / (hdr2->NumChannels * hdr2->BitsPerSample);
      int NumSamples = NumSamples1 > NumSamples2 ? NumSamples1 : NumSamples2;

      //check if wav files have same format already happened in readWaveHeader();

      //instead of making new Waveheader, write hdr1 and change if necessary
      hdr1->ChunkSize = NumSamples1 > NumSamples2 ? hdr1->ChunkSize : hdr2->ChunkSize;
      hdr1->Subchunk2Size = NumSamples1 > NumSamples2 ? hdr1->Subchunk2Size : hdr2->Subchunk2Size;


      short s1 = 0;
      short s2 = 0;
      double otest = 0.0;

      //write WaveHeader first, with postcondition
      bool written = 0; 
      written = writeWaveHeader(&fout,hdr1);
      if (!written)
	cerr << "Error: WaveHeader not written." << endl;	

      //read from stream and write, one sample (2 bytes) at a time
      for (int i = 0; i < NumSamples; i++) {

	//read from file1 and if it is too small begin anew, skipping hdr
	fin1.read((char*)&s1,sizeof(short));
	if (fin1.eof()) {
	  fin1.clear();
	  fin1.seekg(sizeof(WAVEHEADER), ios::beg);
	  WAVEHEADER *hdr1 = readWaveHeader(&fin1);
	}

	//read from file2 and if it is too small begin anew, skipping hdr
	fin2.read((char*)&s2,sizeof(short));
	if (fin2.eof()) {
	  fin2.clear();
	  fin2.seekg(sizeof(WAVEHEADER), ios::beg);
	  WAVEHEADER *hdr2 = readWaveHeader(&fin2);
	}

	s1 += s2;
	//check for overflow
	otest = (double)s1+(double)s2;
	s1 = otest > SHRT_MAX ? SHRT_MAX : s1;
	s1 = otest < SHRT_MIN ? SHRT_MIN : s1;

	// output unformatted, i.e. char (istream & (const char,...
	//      fout << s << endl;
	fout.write((char*)&s1,sizeof(short));
      }
      //free memory
      delete hdr1;
      delete hdr2;
    }
  }

  /* TODO */
  cout << "done" << endl;
}


void echoWaveFile( char infile[], char outfile[], double delay, double echo_gain )  
{
  cout << "Adding echo:" << endl;

  //open streams in binary , with postconditions
  ifstream fin(infile,ios::in|ios::binary);
  ofstream fout(outfile,ios::out|ios::binary);
  if( !fin.is_open() ) {
    cerr << "Problem with reading the file.";
  } else {
    //read in the WAVEHEADER to get file info, with postconditions
    //this also sets the read pointer to the end of the header
    //Q: does this have problems with ios::binary? Apparently not.
    WAVEHEADER *hdr = readWaveHeader(&fin);
    if(NULL == hdr) {
      cerr << "No Waveheader found." << endl;
    }

    //Determine NumSamples (see also documentation)
    int NumSamples = 0;
    short s = 0;
    short b = 0;
    double sd = 0.0;
    NumSamples = (hdr->Subchunk2Size * 8) / (hdr->NumChannels * hdr->BitsPerSample);

    //create buffer with length of delay
    int NumSamplesBuffer = int(delay*(double)hdr->SampleRate);
    //int NumSamplesBuffer = int(NumSamples*(delay/(1.0 * hdr->Subchunk2Size / hdr->ByteRate)));
    short * buffer;
    buffer = new short[NumSamplesBuffer];
    //initialize buffer with 0
    for (int i=0; i< NumSamplesBuffer; i++) {
      buffer[i] = 0;
    }

    //write WaveHeader first, with postcondition
    bool written = 0; 
    written = writeWaveHeader(&fout,hdr);
    if (!written)
      cerr << "Error: WaveHeader not written." << endl;	

    //read from stream and write, one sample (2 bytes) at a time
    for (int i = 0; i < NumSamples; i++) {

      fin.read((char*)&s,sizeof(short));

      //write to buffer
      buffer[i % NumSamplesBuffer] = s;

      //read in oldest entry from buffer which is at i+1 because of modulo
      sd = (double)s + (double)buffer[(i+1) % NumSamplesBuffer];
      sd *= echo_gain;
      s = (short)sd;

      // output unformatted, i.e. char (istream & (const char,...
      //      fout << s << endl;
      fout.write((char*)&s,sizeof(short));
    }
    //free memory
    delete hdr;
  }

  /* TODO */
  cout << "done" << endl;
}

//---------------------------------------------------------
// main
//---------------------------------------------------------
int main(int argc, char *argv[])
{
	
  char *command = "-info";
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
	
  // -totext command
  if(!strcmp(command, "-totext")) {
    if(parms_count >= 2) {
      convertWaveFile( parms[0], parms[1]);
      return 0;
    } else {
      cerr << "Not enough parameters" << endl;
      return 1;
    }
	
  }

  // -vol command
  if(!strcmp(command, "-volume")) {
    if(parms_count >= 3) {
      volumeWaveFile( parms[1], parms[2], atof(parms[0]));
      return 0;
    } else {
      cerr << "Not enough parameters" << endl;
      return 1;
    }

  }

  // -mix command
  if(!strcmp(command, "-mix")) {
    if(parms_count >= 3) {
      mixWaveFiles( parms[0], parms[1], parms[2]);
      return 0;
    } else {
      cerr << "Not enough parameters" << endl;
      return 1;
    }

  }

  // -echo command
  if(!strcmp(command, "-echo")) {
    if(parms_count >= 4) {
      echoWaveFile( parms[2], parms[3], atof(parms[0]), atof(parms[1]));
      return 0;
    } else {
      cerr << "Not enough parameters" << endl;
      return 1;
    }

  }

  return 0;
}
