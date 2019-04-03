#define USEFILEIO
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

float calcE(float D)
{
    return 6.11 * pow(2.718281828f, 5417.7530f * ((1.0f / 273.16f) - (1.0f / (D + 273.16f))));
}

float calcH(float T, float D)
{
    return T + (0.5555f * (calcE(D) - 10.0f));
}

float calcT(float D, float H)
{
    return H - (0.5555f * (calcE(D) - 10.0f));
}

float calcD(float H, float T)
{
    float h = H - T;
    float e = h / 0.5555f + 10.0f;
    return 1.0f / ((1.0f / 273.16f) - log(e / 6.11f) / 5417.7530f) - 273.16f;
}

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
#endif
    char *outstr = "T %.1f D %.1f H %.1f\n";
    char c1, c2;
    float a, b, c;
    map<char, int> cValue;
    cValue['T'] = 1;
    cValue['D'] = 2;
    cValue['H'] = 4;
    while(cin >> c1)
    {
        int value = 0;
        if(c1 == 'E')
            break;
        cin >> a >> c2 >> b;
        value += cValue[c1];
        value += (8 * cValue[c2]);
        switch(value)
        {
            case 17:
                c = calcH(a, b);
                printf(outstr, a, b, c);
                break;
            case 10:
                c = calcH(b, a);
                printf(outstr, b, a, c);
                break;
            case 34:
                c = calcT(a, b);
                printf(outstr, c, a, b);
                break;
            case 20:
                c = calcT(b, a);
                printf(outstr, c, b, a);
                break;
            case 12:
                c = calcD(a, b);
                printf(outstr, b, c, a);
                break;
            case 33:
                c = calcD(b, a);
                printf(outstr, a, c, b);
        }
    }

    return 0;
}