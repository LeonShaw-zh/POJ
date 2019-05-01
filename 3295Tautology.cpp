#define USEFILEIO
#include <fstream>
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

char str[100];

int enumturn = 0x1f;
int p_mask = 0x01;
int q_mask = 0x02;
int r_mask = 0x04;
int s_mask = 0x08;
int t_mask = 0x10;

bool pop_stack(stack<bool> & s){
    bool tem = s.top();
    s.pop();
    return tem;
}

char get_value(int code, char ch){
    char val;
    switch(ch){
        case 'p':
            val = (code & p_mask) == 0 ? '0' : '1';
            break;
        case 'q':
            val = (code & q_mask) == 0 ? '0' : '1';
            break;
        case 'r':
            val = (code & r_mask) == 0 ? '0' : '1';
            break;
        case 's':
            val = (code & s_mask) == 0 ? '0' : '1';
            break;
        case 't':
            val = (code & t_mask) == 0 ? '0' : '1';
            break;
        default:
            val = ch;
    }
    return val;
}


bool isTautology(int len){
    bool isTauto = true;
    stack<bool> value_stack;

    for(int code = 0; code <= enumturn; code++){
        for (int i = len-1; i >= 0; i--){
            char value = get_value(code, str[i]);
            bool a, b;
            switch(value){
                case '0':
                    value_stack.push(false);
                    break;
                case '1':
                    value_stack.push(true);
                    break;
                case 'N':
                    a = pop_stack(value_stack);
                    value_stack.push(!a);
                    break;
                case 'K':
                    a = pop_stack(value_stack);
                    b = pop_stack(value_stack);
                    value_stack.push(a && b);
                    break;
                case 'A':
                    a = pop_stack(value_stack);
                    b = pop_stack(value_stack);
                    value_stack.push(a || b);
                    break;
                case 'C':
                    a = pop_stack(value_stack);
                    b = pop_stack(value_stack);
                    value_stack.push((!a) || b);
                    break;
                case 'E':
                    a = pop_stack(value_stack);
                    b = pop_stack(value_stack);
                    value_stack.push(a == b);
            }
        }
        bool result = pop_stack(value_stack);
        if(!result){
            isTauto = false;
            break;
        }
    }
    return isTauto;
}

void work(){
    while(scanf("%s", str)){
        if(str[0] == '0') return;
        int len = 0;
        for(; str[len] != '\0'; len++){}
        if(isTautology(len)) printf("tautology\n");
        else printf("not\n");
    }
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
    work();
    return 0;
}