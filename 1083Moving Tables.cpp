#define USEFILEIO
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int getcorri(int room)
{
    return (room / 2) + (room % 2);
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
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    int testNum, moveNum;
    int cnt[201];
    cin >> testNum;
    for (int t = 0; t < testNum; t++)
    {
        int maxim = 0;
        cin >> moveNum;
        memset(cnt, 0, sizeof(cnt));
        for (int m = 0; m < moveNum; m++)
        {
            int a, b;
            cin >> a >> b;
            int l, h;
            l = a < b ? a : b;
            h = a > b ? a : b;
            l = getcorri(l);
            h = getcorri(h);
            for (int i = l; i <= h; i++)
                if(++cnt[i] > maxim)
                    maxim = cnt[i];
        }
        cout << maxim * 10 << endl;
    }

    return 0;
}