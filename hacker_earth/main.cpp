#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string first, string second)
{
    return (first.length() < second.length());
}

int main()
{
    int num_strings;
    string str; 
    getline(cin,str);
    
    num_strings = atoi(&str[0]);
    
   // cout <<num_strings;
   for (int i = 0; i < num_strings; i++) {
        vector<string> str_vec;
        getline(cin, str);
        istringstream ss(str);
        
        while (ss)
        {
            string temp;
            ss >> temp;
            str_vec.push_back(temp);
        }
        
        stable_sort(str_vec.begin(), str_vec.end(), comp);
        vector<string>::iterator it;
        for (it = str_vec.begin(); it != str_vec.end(); it ++)
            cout << *it <<  " ";
        cout << endl;
    }
    return 0;
}
