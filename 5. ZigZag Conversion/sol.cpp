#include <iostream>
#include <vector>
using namespace std;

void printZigzag(string s, int numRows)
{
    if (numRows == 1 || numRows >= s.size())
    {
        cout << s << endl;
        return;
    }

    vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s)
    {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1)
            goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    for (string row : rows)
    {
        cout << row << endl;
    }
}

int main()
{
    string s = "PAYPALISHIRING4546456";
    int numRows = 4;
    printZigzag(s, numRows);
    return 0;
}
