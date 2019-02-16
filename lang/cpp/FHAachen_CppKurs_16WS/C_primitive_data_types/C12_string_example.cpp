/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	String-Beispiel.
 * 
 *  Stichworte:
 *      - string
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "../tools/tools.h"

string doppelt(string s)
{
    return s+s;
}

int main()
{   

    tools_log(); cout << "Einfache String-Ops" << endl;
    
    // write and size
    string s1 = "Hallo";
    tools_log(); cout << "s1='" << s1 << "', len=" << s1.size() << endl << endl;

    // element access, strings are not immutable
    tools_log(); cout << "s1[0]='" << s1[0] << "'" << endl; // etc.
    s1[1] = 'A';
    tools_log(); cout << "s1[1]='" << s1[1] << "'" << endl << endl; // etc.
    tools_log(); cout << "s1='" << s1 << endl << endl;

    // for each
    tools_log(); cout << "s1 chars: { ";
    for (auto c : s1)
        cout << c << " ";
    cout << "}" << endl;
    
    // alternativ
    tools_log(); cout << "s1 chars: { ";
    for (size_t i=0; i<s1.size(); ++i)  // try int...
        cout << s1[i] << " ";
    cout << "}" << endl << endl;
    
    // what means copy?
    string s2=s1;
    s1[2]='L';
    string s3=s1;
    tools_log(); cout << "s1='" << s1 << "', s2='" << s2 << "'" << endl << endl;
    
    bool bEqual=(s1==s2);
    tools_log(); cout << "s1==s2? " << bEqual << endl;
    tools_log(); cout << "s1==s3? " << (s1==s3) << endl;
    tools_log(); cout << "&s1=" << &s1 << ", &s2=" << &s2 << ", &s3=" << &s3 << endl;
    s1=s2; bEqual=(s1==s2);
    tools_log(); cout << "s1==s2? " << bEqual << endl;
    tools_log(); cout << "&s1=" << &s1 << ", &s2=" << &s2 << endl << endl;

    // string ops
    s1 = "0123456789abcdefghij";
    tools_log(); cout << "s1='" << s1 << "'" << endl;
    tools_log(); cout << "  sub='" << s1.substr(10) << "'" << endl;
    tools_log(); cout << "  sub='" << s1.substr(5,3) << "'" << endl;
    tools_log(); cout << "  sub='" << s1.substr(12,100) << "'" << endl;
    tools_log(); cout << "  sub='" << s1.substr(s1.size()-3,50) << "'" << endl << endl;

    // insert and erase
    s2=s1;
    //for (int i=0; i<10000000; ++i)
    //    s2 += s2;
    s2.insert(2,"abc");
    tools_log(); cout << "s2='" << s2 << "'" << endl;
    s2.erase(2,3);
    tools_log(); cout << "s2='" << s2 << "'" << endl << endl;

    // append
    tools_log(); cout << "s2='" << s2 << "'" << endl;
    s2+='!';
    tools_log(); cout << "s2='" << s2 << "'" << endl << endl;

    for (size_t i=0; i<s2.size(); ++i)
        s2[i]='X';
    tools_log(); cout << "s2='" << s2 << "'" << endl;

    for (size_t i=0; i<s2.size()+10; ++i)   // bei +100: "Aborted (Speicherabzug geschrieben)"
        s2[i]='X';
    tools_log(); cout << "s2='" << s2 << "'" << endl;

    return EXIT_SUCCESS;
}

