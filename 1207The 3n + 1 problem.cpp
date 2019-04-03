#define USEFILEIO
#include <fstream>
#include <iostream>
using namespace std;

int computCycleLen(int p)
{
    int len = 1;
    while(p != 1)
    {
        if(p % 2 == 0)
            p = p / 2;
        else
            p = 3 * p + 1;
        len++;
    }
    return len;
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

    int a, b;
    while(cin >> a >> b)
    {
        int i = a < b ? a : b;
        int j = a > b ? a : b;
        int max = 0;
        for(int p = i; p <= j; p++)
        {
            int tem = computCycleLen(p);
            max = (tem > max) ? tem : max;
        }
        cout << a << " " << b << " " << max << endl;
    }

    return 0;
}