#define USEFILEIO
#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool judge(int b, int e, char *v){
    if(b >= e)
        return true;
    if(v[b] == v[e]) return judge(b + 1, e-1, v);
    else return v[b] < v[e];
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
    int N;
    char v[2002];
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> v[i];
    }
    int b = 0;
    int e = N-1;
    int count = 0;
    while(b <= e){
        if(judge(b, e, v)){
            printf("%c", v[b]);
            b++;
            count++;
        }else{
            printf("%c", v[e]);
            e--;
            count++;
        }
        if(count >= 80){
            printf("\n");
            count = 0;
        }
    }
    return 0;
}