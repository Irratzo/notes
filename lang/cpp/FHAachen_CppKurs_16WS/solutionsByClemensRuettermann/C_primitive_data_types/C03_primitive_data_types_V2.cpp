/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Weitere primitive Datentypen und ihre jeweilige Groesse.
 * 
 *  Stichworte:
 *      - printf, Formatstring fuer ganzzahlige Daten
 *      - Datentypen, char, short, int, long, long long
 *      - (u)int8_t, (u)int16_t, (u)int32_t, (u)int64_t
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

int main()
{   
    // ganzzahlige Typen
    
    // boolean type ... gibt es nicht in C, aber in C++
    bool b = true;
    tools_log(); cout << "b=" << b << endl;
    b = false;
    tools_log(); cout << "b=" << b << endl;

    cout << endl;
    
    char c = 'A';
    tools_log(); cout << "c=" << c << endl;

    cout << endl;

    // alle integer Datentypen gibt es in signed und unsigned
    // sizeof int, long, long long haengen an der Architektur
    // sizeof int8_t, int16_t, ... ist unabhaengig

    unsigned char uc = 33;
    signed char sc = -34;

    unsigned short us = 1;
    signed short ss = -2;

    unsigned int ui = 3;
    signed int si = -4;

    unsigned long ul = 5;
    signed long sl = -6;

    unsigned long long ull = 7;
    signed long long sll = -8;
    
    uint8_t u8 = 9;
    int8_t s8 = -10;
    
    uint16_t u16 = 11;
    int16_t s16 = -12;
    
    uint32_t u32 = 13;
    int32_t s32 = -14;
    
    uint64_t u64 = 15;
    int64_t s64 = -16;

    // um den jeweiligen Formatstring zu zeigen, hier nur printf aufgerufen
    // der Formatstring fuer eine Groesse ist '%zu'
    
    tools_log(); printf("b  =%3d, sizeof(b)=%zu\n",b,sizeof(bool));
    tools_log(); printf("uc ='%c', sizeof(unsigned char)=%zu\n",uc,sizeof(unsigned char));
    tools_log(); printf("sc ='%c', sizeof(signed char)=%zu\n",sc,sizeof(signed char));
    tools_log(); printf("us =%3d, sizeof(unsigned short)=%zu\n",us,sizeof(unsigned short));
    tools_log(); printf("ss =%3d, sizeof(signed short)=%zu\n",ss,sizeof(signed short));
    tools_log(); printf("ui =%3d, sizeof(unsigned int)=%zu\n",ui,sizeof(unsigned int));
    tools_log(); printf("si =%3d, sizeof(signed int)=%zu\n",si,sizeof(signed int));
    tools_log(); printf("ul =%3ld, sizeof(unsigned long)=%zu\n",ul,sizeof(unsigned long));
    tools_log(); printf("sl =%3ld, sizeof(signed long)=%zu\n",sl,sizeof(signed long));
    tools_log(); printf("ull=%3lld, sizeof(unsigned long long)=%zu\n",ull,sizeof(unsigned long long));
    tools_log(); printf("sll=%3lld, sizeof(signed long long)=%zu\n",sll,sizeof(signed long long));

    tools_log(); printf("u8 =%3d, sizeof(uint8_t)=%zu\n",u8,sizeof(uint8_t));
    tools_log(); printf("s8 =%3d, sizeof(int8_t)=%zu\n",s8,sizeof(int8_t));
    tools_log(); printf("u16=%3d, sizeof(uint16_t)=%zu\n",u16,sizeof(uint16_t));
    tools_log(); printf("s16=%3d, sizeof(int16_t)=%zu\n",s16,sizeof(int16_t));
    tools_log(); printf("u32=%3d, sizeof(uint32_t)=%zu\n",u32,sizeof(uint32_t));
    tools_log(); printf("s32=%3d, sizeof(int32_t)=%zu\n",s32,sizeof(int32_t));
    tools_log(); printf("u64=%3ld, sizeof(uint64_t)=%zu\n",u64,sizeof(uint64_t));
    tools_log(); printf("s64=%3ld, sizeof(int64_t)=%zu\n",s64,sizeof(int64_t));

    return EXIT_SUCCESS;
}

