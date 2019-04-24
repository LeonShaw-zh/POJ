#define USEFILEIO
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

typedef struct node{
    int type;  // 1=min , 2=max
    int num;
    double x;
} node;

node xaxis[2010];

bool compute(int x, int y, int d, int num){
    double min, max;
    if(y > d) return false;
    else if(y == d){
        min = x;
        max = x;
    }else{
        double tem = sqrt(d * d - y * y);
        min = x - tem;
        max = x + tem;
    }
    xaxis[2 * num].type = 1;
    xaxis[2 * num].x = min;
    xaxis[2 * num].num = num;
    xaxis[2 * num + 1].type = 2;
    xaxis[2 * num + 1].x = max;
    xaxis[2 * num + 1].num = num;
    return true;
}

// 遍历x轴，贪心算法
int getResult(int num){
    int result = 0;
    bool iscover[1010] = {false};
    stack<int> s;
    for (int i = 0; i < 2 * num; i++){
        node n = xaxis[i];
        if(!iscover[n.num]){
            if(n.type==1){
                s.push(n.num);
            }else{
                result++;
                while(!s.empty()){
                    iscover[s.top()] = true;
                    s.pop();
                }
            }
        }
    }
    return result;
}

bool compare(node n1, node n2){
    if(n1.x < n2.x - 1e-8)
        return true;
    else if(fabs(n1.x-n2.x) < 1e-8 && n1.type < n2.type) // 保证左相同x值的最小值小于最大值， 考虑到有多个相同的（最大值最小值相同的点）
        return true;                                     // 测试用例 6 2 1 2 1 2 1 2 -3 1 2 1 0 0
    else 
        return false;
}

void Merge(int r, int mid, int p){
    int len1 = mid - p;
    int len2 = r - mid;
    node* temAry1 = new node[len1];
    node* temAry2 = new node[len2];
    for(int i=0; i<len1; i++)
        temAry1[i] = xaxis[p+i];
    for(int i=0; i<len2; i++)
        temAry2[i] = xaxis[mid+i];

    int i = 0;
    int j = 0;
    int k = p;
    while(i < len1 && j < len2){
        if(compare(temAry1[i], temAry2[j])){
            xaxis[k] = temAry1[i];
            i = i + 1;
        }
        else{
            xaxis[k] = temAry2[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while(i < len1){
        xaxis[k] = temAry1[i];
        i = i + 1;
        k = k + 1;
    }
    while(j < len2){
        xaxis[k] = temAry2[j];
        j = j + 1;
        k = k + 1;
    }
}

void MergeSort(int r, int p=0){
    if(r - p > 1){
        int mid = floor((r + p) / 2);
        MergeSort(mid, p);
        MergeSort(r, mid);
        Merge(r, mid, p);
    }
}

void axissort(int num){
    MergeSort(2 * num);
}

void work(){
    int num, dis;
    int x, y;
    int result, turn = 0;
    while(true){
        turn++;
        result = 0;
        scanf("%d %d", &num, &dis);
        if(num == 0 && dis == 0)
            break;
        for(int i = 0; i < num; i++){
            scanf("%d %d", &x, &y);
            if(!compute(x, y, dis, i))
                result = -1;
        }
        if(result != -1){
            axissort(num);
            result = getResult(num);
        }
        printf("Case %d: %d\n", turn, result);
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