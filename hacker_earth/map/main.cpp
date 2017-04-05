#include <vector>
#include <iostream>
#include <map>

using namespace std;


int main()
{
    int size;
    map<int, int> my_map;
    
    my_map[-2000000] = 1;
    
    cin >> size;
    vector<int> num_vec(size);
    
    for (int crwlr = 0; crwlr < size; crwlr++)
            cin >> num_vec[crwlr];
            
    for (int crwlr = 0; crwlr < size; crwlr++) {  
            if (my_map.find(num_vec[crwlr]) == my_map.end())
                my_map[num_vec[crwlr]] = 1;
            else
                my_map[num_vec[crwlr]] += 1;
    }
    
    map<int,int>::iterator it = my_map.begin();
    map<int,int>::iterator it_max = it;
    int max = it->second;
    
    for (it = my_map.begin(); it != my_map.end(); it++) {
        if (max < it->second) {
            max = it->second;
            it_max = it;
        }
    }
    
    cout << it_max->first << endl;
    return 0;
}
