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


void inline prnt(int i)
{
    cout << i << endl;
}

int main(){
    vector<int> vec(7);

    vec[0]=1;
    vec[1]=2;
    vec[2]=3;
    vec[3]=4;
    vec[4]=5;

    memcpy(&vec[5], &vec[0], 2*sizeof(int));
    for_each(vec.begin(), vec.end(), prnt);
    cout << endl;
    vec.erase(vec.begin(), vec.begin()+2);
    for_each(vec.begin(), vec.end(), prnt);

    return 0;
}
