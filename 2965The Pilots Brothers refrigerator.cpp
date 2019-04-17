#define USEFILEIO
#include <fstream>
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int field[6] = {0};
int pattern[][4] = {{8, 4, 2, 1}, {15, 15, 15, 15}};
stack<int> recordi;
stack<int> recordj;

void read(){
    int i = 1, j = 1;
    for (; i <= 4; i++){
        j = 1;
        for (; j <= 4; j++){
            field[i] <<= 1;
            if(getchar()=='+')
                field[i] |= 1;
        }
        getchar();
    }
}

bool check(){
    return field[1]==0
        && field[2]==0
        && field[3]==0
        && field[4]==0;
}

void flip(int i, int j){
    j -= 1;
    for (int r = 1; r <= 4; r++){
        if(r == i)
            field[r] ^= pattern[1][j];
        else
            field[r] ^= pattern[0][j];
    }
}

bool find(int n, int i, int j){
    if(n == 0) return check();
    j+=1; if(j>4) i+=1, j=1;
    if(i > 4) return false;
    for (; i <= 4; i++){
        for (; j <= 4; j++){
            recordi.push(i);
            recordj.push(j);
            flip(i, j);
            if(find(n-1, i, j))
                return true;
            recordi.pop();
            recordj.pop();
            flip(i, j);
        }
        j = 1;
    }
    return false;
}

void printStack(){
    stack<int> temi;
    stack<int> temj;
    while(!recordi.empty()){
        temi.push(recordi.top());
        temj.push(recordj.top());
        recordi.pop();
        recordj.pop();
    }
    while(!temi.empty()){
        printf("%d %d\n", temi.top(), temj.top());
        temi.pop();
        temj.pop();
    }
}

void work(){
    int n = 0;
    for (; n <= 16; n++){
        if (find(n, 1, 0)){
            printf("%d\n", n);
            printStack();
            return;
        }
    }
}

int main(){
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

    read();
    work();

    return 0;
}