#include <iostream>
#include <string>
#include <vector>

using namespace std;

// LCS - Longest common subsequence

int main()
{
    string a, b;
    cin >> a >> b;

    int al = a.size() + 1, bl = b.size() + 1;

    vector<vector<int>> tab(al);
    for (int i = 0; i < al; i++)
        tab[i].resize(bl);

    for (int i = 1; i < al; i++) {
        for (int j = 1; j < bl; j++) {
            if (a[i - 1] == b[j - 1])
                tab[i][j] = 1 + tab[i - 1][j - 1];
            else
                tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
        }
    }
    cout << tab[al - 1][bl - 1] << endl;

    cout << "   ";

    for (int j = 0; j < bl; j++)
        cout << b[j - 1] << " ";
    cout << endl;
    for (int i = 0; i < al; i++) {
        if (i == 0)
            cout << "  ";
        else
            cout << a[i - 1] << " ";
        for (int j = 0; j < bl; j++) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}