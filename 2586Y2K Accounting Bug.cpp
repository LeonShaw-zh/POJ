#define USEFILEIO
#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;

void work(int s, int d){
    int res = 0;
    if(d > 4*s)
        res = 10 * s - 2 * d;
    else if(2*d > 3*s)
        res = 8 * s - 4 * d;
    else if(3*d > 2*s)
        res = 6 * s - 6 * d;
    else if(4*d > s)
        res = 3 * s - 9 * d;
    else
        res = -1;
    if(res < 0)
        printf("Deficit\n");
    else
        printf("%d\n", res);
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
    int s, d;
    while(scanf("%d %d", &s, &d) != EOF)
        work(s, d);
    return 0;
}