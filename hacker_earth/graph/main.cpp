/*

Samarpit is the main hero of the Dhoom 4.He is trying to steal from the Code Bank Of Hackers.Samarpit has a key with an integer value printed on it. He also has N other keys with each key having its own specific value.Samarpit is trying to break the Lock for which he is supposed to get to the lock's key value. He can perform one type of operation.Take his own key and one of the other N keys and merge them.During merging Samarpit's Key value changes to product of both the keys modulus 100000.

For example if his key value was X and he took a key with value Y the his new key will be (X*Y)%100000.The other key that was used during the merging process remains along with other N-1 keys.

This entire process of merging takes 1 second.Now since he is in a hurry he asks to you to find the minimum time in which he could reach to the lock's key value.

Input:
The first line contains 2 integers they are Samarpit's Key value and the Lock's key value.
The second line contains N indicating the number of other keys Samarpit has. 
Third line contains N space separated integers indicating the value of N other keys.

Output: 
The minimum time required to get to the Lock's Key.If he is unable to reach that print -1.

Constraints:
1 ≤ N ≤ 1000 
1 ≤ Value of all the keys ≤ 100000

SAMPLE INPUT 
3 30
3
2 5 7

SAMPLE OUTPUT 
2

Explanation
In the first second he can take make his own key to value 6 by multiplying it by 2.Then in the next second he can multiply his new key with 5 to get to 30.

*/


#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100000

int main()
{
    int key;
    int lock;
    int num_keys;
    vector<int> all_keys;
    int found_lock = false;
    vector< vector<int> > level(MAX);

    cin >> key;
    cin >> lock;
    cin >> num_keys;
    
    for (int i=0; i < num_keys; i++) {
        int x;
        cin >> x;
        all_keys.push_back(x);
    }    
    
    level.at(0).push_back(key);
    cout << level[0][0] << endl;
    // i is the level index here
    for (int i = 1; i < MAX; i++) {
        const int prev_level = i-1;
        const int next_level = i;
        // for all items in the previous level
        for (unsigned j = 0; j < level[prev_level].size(); j++)
        {
            int item = level[prev_level][j];
            // get new keys for the next level from this key
            for (unsigned k = 0; k < all_keys.size(); k++) {
                int new_key = (all_keys[k]*item)%100000;
                if (lock == new_key) {
                    cout << i << endl;
                    return 0;
                }
                level[next_level].push_back(new_key);
            }
        }
        cout << endl;
    }
            
    cout << -1 << endl;
	    
    return 0;
}

