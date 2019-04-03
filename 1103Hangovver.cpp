#define USEFILEIO
#include <fstream>
#include <iostream>
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
#endif

    float len;
    while(cin >> len)
    {
        if(len == 0.00f)
            break;
        float l = 0.5f;
        int i = 2;
        while(l < len)
        {
            i++;
            l = l + (1.0f / i);
        }
        cout << i - 1 << " card(s)" << endl;
    }
    return 0;
}