#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

void prepare_map(map<char, int> &map_a, string a)
{
    for (int i=0; i < a.length(); i++) {
        if (map_a.find(a[i]) == map_a.end())
            map_a[a[i]] = 1;
        else
            map_a[a[i]]++;
    }
}

int number_needed(string a, string b) {
    map<char, int> map_a, map_b;
    map<char, int>::iterator it;

    prepare_map(map_a,a);
    prepare_map(map_b,b);
    
    for (it = map_a.begin(); it != map_a.end(); it++)
        cout << it->first<< " ";
    cout << endl; 
    for (it = map_b.begin(); it != map_b.end(); it++)
        cout << it->first<< " ";
    cout << endl; 
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
number_needed(a, b);
    //cout << number_needed(a, b) << endl;
    return 0;
}
