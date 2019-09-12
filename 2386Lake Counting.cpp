#define USEFILEIO
#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;

int N, M;

bool dfs(string *t, int i, int j){
    if(i < 1 || j < 0)
        return false;
    if(i > N || j >= M)
        return false;
    if(t[i][j] == 'c')
        return false;
    if(t[i][j] == '.')
        return false;
    t[i][j] = 'c';
    dfs(t, i + 1, j + 1);
    dfs(t, i + 1, j);
    dfs(t, i + 1, j - 1);
    dfs(t, i - 1, j + 1);
    dfs(t, i - 1, j);
    dfs(t, i - 1, j - 1);
    dfs(t, i, j + 1);
    dfs(t, i, j - 1);
    return true;
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

    string tem[105];
    cin >> N >> M;
    for (int i = 0; i <= N; i++){
        getline(cin, tem[i]);
    }
    int counter = 0;
    for (int i = 1; i <= N; i++){
        for (int j = 0; j < M; j++){
            if(dfs(tem, i, j))
                counter++;
        }
    }
    printf("%d", counter);
    return 0;
}