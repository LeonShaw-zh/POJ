#define USEFILEIO
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
#ifdef USEFILEIO
    fstream filein, fileout;
    filein.open("input.txt", ios::in);
    fileout.open("output.txt", ios::out);
    // streambuf *stream_buffer_cin = cin.rdbuf();
    // streambuf *stream_buffer_cout = cout.rdbuf();
    cin.rdbuf(filein.rdbuf());
    // cout.rdbuf(fileout.rdbuf());
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    int basenum = (int)'A' - 1;
    char instr[256];
    while(gets(instr))
    {
        if(instr[0] == '#')
            break;
        int len = strlen(instr);
        int checksum = 0;
        for (int i = 0; i < len; i++)
        {
            if(instr[i] != ' ')
                checksum += (((int)(instr[i]) - basenum) * (i+1)) ;
        }
        cout << checksum << endl;
    }

    return 0;
}