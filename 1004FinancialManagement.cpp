#define USEFILEIO
#include <fstream>
#include <iostream>
#include <iomanip>
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

    float sum = 0, month = 0;
    for (int i = 0; i < 12; i++)
    {
        cin >> month;
        sum += month;
    }
    cout.setf(ios_base::fixed);
    cout << "$" << setprecision(2) << sum / 12.0f;
    return 0;
}