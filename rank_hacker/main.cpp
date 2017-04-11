#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string ler;

    getline(cin, ler);

    int len = ler.length();
    for (int i = 0; i < len; i++)
    {
        string temp = ler;
        temp.erase(temp.begin()+i);
        cout << temp << endl;
    }

    return 0;
}
