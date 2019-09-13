#define USEFILEIO
#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>
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

    auto R{0}, n{0};
    while(scanf("%d %d\n", &R, &n)){
        if(R == -1 && n == -1)
            break;
        auto x_list = vector<int>{};
        x_list.resize(n);
        for(auto& x: x_list){
            scanf("%d", &x);
        }
        sort(x_list.begin(), x_list.end());

        auto result{0};
        auto b = x_list.begin();
        while(b < x_list.end()){
            auto range = *b + R;
            auto select = b;
            while(*select <= range){
                select++;
                if(select == x_list.end())
                    break;
            }
            range = *(select - 1) + R;
            while(*select <= range){
                select++;
                if(select == x_list.end())
                    break;
            }
            result++;
            b = select;
        }
        printf("%d\n", result);
    }

    return 0;
}