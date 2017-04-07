#include <iostream>
#include <list>
using namespace std;

void del_fnd(list<int> &lst)
{
    list<int>::iterator it;
    int deleted = false;
    
    for (it = lst.begin(); it != (lst.end()); it++) {
        if (*it < *(it+1)) {
            lst.erase(it);
            deleted = true;
            break;
        }    
    }
    
    if (false ==  deleted && (!lst.empty()))
        lst.erase(it.end()-1);
}

int main()
{
    int num_testcases;
    
    cin >> num_testcases;
    
    for (int i=0; i < num_testcases; i++) {
        int num_fnds;   // no of friends
        int num_todel;  // no of firends to delete 
        list<int> fnd_list;
        
        cin >> num_fnds;
        cin >> num_todel;
        
        for (int j = 0; j < num_fnds; j++) {
            int popularity;
            cin >> popularity;
            fnd_list.push_back(popularity);
        }
        
	cout << fnd_list[2] << endl;

       // for (int j = 0; j < num_todel; j++)
        //    del_fnd(fnd_list);

      //  list<int>::iterator it;
                    
      //  for (it = fnd_list.begin(); it != fnd_list.end(); it++) {
      //      cout << *it << " ";
      //  }
        cout << endl;
    }
    
    return 0;
}
