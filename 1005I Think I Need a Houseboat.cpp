#define USEFILEIO
#include <fstream>
#include <iostream>
#include <cmath>
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
#endif

    int numOfTurn;
    float x, y;
    cin >> numOfTurn;
    for (int turn = 1; turn <= numOfTurn; turn++)
    {
        cin >> x >> y;
        float s = (x * x + y * y) * 3.1415926f / 2.0f;
        int y = std::ceil(s / 50);
        cout << "Property " << turn
             << ": This property will begin eroding in year "
             << y << "." << endl;
    }
    cout << "END OF OUTPUT." << endl;
    return 0;
}