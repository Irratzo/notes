/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Als Union zusammengefasste Datentypen
 * 
 *  Stichworte:
 *      - union
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "../tools/tools.h"

int main()
{
    tools_log(); cout << "union byte_t:" << endl;

    // dieser Typ enthaelt genau ein (1) Byte, welches einmal als
    // signed char oder als unsigned char interpretiert wird
    union byte_t {
        unsigned char uc;
        signed char sc;
    };
    byte_t b;   // cf. def. of structs
    
    tools_log(); cout << "  sizeof(byte_t)=" << sizeof(byte_t) << endl;
    
    b.uc = 0x41;
    tools_log(); cout << "  b.uc=0x" << hex << setw(2) << (int)b.uc << ", b.uc=" 
                      << dec << (int)b.uc << ", b.sc=" << (int)b.sc << endl; 
    
    b.sc = -2;
    tools_log(); cout << "  b.uc=0x" << hex << setw(2) << (int)b.uc << ", b.uc=" 
                      << dec << (int)b.uc << ", b.sc=" << (int)b.sc << endl << endl; 
   
    tools_log(); cout << "union bytepair_t:" << endl;

    // dieser Typ enthaelt genau zwei (2) Bytes, interpretiert einzeln oder als Feld
    union bytepair_t {
        struct {
            unsigned char c1;
            unsigned char c2;
        } chars;
        unsigned char c[2];
    };
    
    bytepair_t bp;

    tools_log(); cout << "  sizeof(bytepair_t)=" << sizeof(bytepair_t) << endl;
    
    bp.chars.c1 = 'A'; bp.chars.c2 = 'B';
    tools_log(); cout << "  bp.chars.c1='" << bp.chars.c1 
                      << "', bp.chars.c2=" << bp.chars.c2 << "'" 
                      << ", bp.c[0]='" << bp.c[0] << "'"
                      << ", bp.c[1]='" << bp.c[1] << "'" << endl << endl;

    tools_log(); cout << "union bitfield_t:" << endl;
   
    // dieser Typ enthaelt genau ein 32-bit Datum, interpretiert entweder als
    // signed int oder als Bitfeld
    union bitfield_t {
        signed int n;
        struct {                    // bitfield 3*8+7+1 bit
            unsigned int nib4:8;
            unsigned int nib3:8;
            unsigned int nib2:8;
            unsigned int nib1:7;
            unsigned int sign:1;
        } bits;
    };
  
    bitfield_t bf;

    tools_log(); cout << "  sizeof(bitfield_t)=" << sizeof(bitfield_t) << endl;
        
    bf.bits.sign = 0;
    bf.bits.nib1 = 0x12;
    bf.bits.nib2 = 0x34;
    bf.bits.nib3 = 0;
    bf.bits.nib4 = 0;
    
    tools_log(); cout << "  bf.n=0x" << setw(4) << hex << bf.n 
                      << ", bf.bits.nib1=0x" << setw(2) << bf.bits.nib1 << dec 
                      << ", ..." << endl;

    return EXIT_SUCCESS;
}

