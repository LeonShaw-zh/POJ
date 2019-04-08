#define USEFILEIO
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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

    char ostr[101] = {'0'}, tstr[101] = {'0'};
    cin >> ostr >> tstr;
    int len = strlen(ostr);

    bool result = true;
    int cnt1[26] = {0}, cnt2[26] = {0};
    int a = (int)'A';
    for (int i = 0; i < len; i++)
    {
        cnt1[(int)ostr[i]-a]++;
        cnt2[(int)tstr[i]-a]++;
    }
    sort(cnt1, cnt1 + 26);
    sort(cnt2, cnt2 + 26);
    for (int i = 0; i < 26; i++)
        if(cnt1[i] != cnt2[i])
        {
            result = false;
            break;
        }
    cout << (result ? "YES" : "NO") << endl;
    return 0;
}