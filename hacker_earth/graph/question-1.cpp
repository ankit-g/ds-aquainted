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

vector<int> all_keys;
int found_lock = false;


void construct_graph(const int key,
                     const int lock,
                     map< int, vector<int> > &graph)
{
    // while key = lock && key <= lock
    // keep creating the graph with key as the vertex
    if (graph.find(key) == graph.end()) {
        // enter all the new edges here
        // DO not enter the edge which is greater than the key
        // if any of the key is equal to the lock push it and leave
        for (unsigned int i=0; i < all_keys.size(); i++) {
            int new_key;
            new_key = (key * all_keys[i])%MAX;
            
            if (new_key <= lock)
            graph[key].push_back(new_key);
            
            if (new_key == lock) {
                found_lock = true;
                return;
            }
        }
        
        if (graph[key].empty())
            return;
            
        for (unsigned int i=0; i < graph[key].size(); i++) {
            int vegina = graph[key][i];
            construct_graph(vegina, lock, graph);
        } 
    } else {
        return;
    }
}

void print_graph(map < int, vector<int> > &graph)
{
    map < int, vector<int> >::iterator it;
    
    for (it = graph.begin(); it != graph.end(); it++) {
        cout << "vertex " << it->first << " ";
        vector<int> vertices = it->second;
        
        for (unsigned int i =0; i < vertices.size(); i++) {
            cout << vertices[i] << " ";
        }
        cout << endl;
    } 
}

void find_level(const int root, const int lock, map < int, vector<int> > &graph)
{
    vector<int> level(lock+1);
    vector<int> found(lock+1, false);
    queue<int>  Q;
    
    level[root] = 0;
    Q.push(root);
    
    while(!Q.empty())
    {
        int vertex = Q.front();
        Q.pop();
        
        if (found[vertex])
            continue;
        
        found[vertex] = true;
        
        for (unsigned int i =0; i < graph[vertex].size(); i++) {
            int node = graph[vertex][i];
            level[node] = level[vertex] + 1;
            Q.push(node);    
            
            if (lock == node) {
                cout << level[node];
                return;
            }    
        }
    }
}

int main()
{
    int key;
    int lock;
    int num_keys;

    map < int, vector<int> > graph;
    
    
    cin >> key;
    cin >> lock;
    cin >> num_keys;
    
    for (int i=0; i < num_keys; i++) {
        int x;
        cin >> x;
        
        all_keys.push_back(x);
    }    
    
    construct_graph(key, lock, graph);
    //print_graph(graph);
    
    find_level(key, lock, graph);
    return 0;
}
