#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    map<char, Node *> children;
    bool isaWord;   
};

class Trie
{

private:

    Node root;
    map<Node *, int> level;
    vector < vector<char> > lv;
    int max_level;

    void display()
    {
        queue<Node *> Q;
        
        Q.push(&root);
        level[&root] = 0;       
        
        while(!Q.empty())
        {

            Node *current = Q.front();
            Q.pop();

            map<char, Node *> &smap = current->children;
            map<char, Node *>::iterator it; 
            
    
            for (it = smap.begin(); it != smap.end(); it++)
            {
                //cout << it->first << " ";
                Q.push(it->second);
                level[it->second] = level[current] + 1;
            }

        }
    }

    void print_levels()
    {
        map<Node *, int>::iterator it;
         
        for (it = level.begin(); it != level.end(); it++)
        {
            int where; // what ever :(

            where = it->second;

            if (where > max_level)
                max_level = where;

            map<char, Node *> &smap = it->first->children;
            map<char, Node *>::iterator it; 
            
            for (it = smap.begin(); it != smap.end(); it++)
            {
                lv[where].push_back(it->first);
            }
        }
    }


public:
    Trie()
    {
        max_level = 0;
        lv.resize(100);
    }

    void insert(string s)
    {
        Node *current = &root;
        const int len = s.length();

        for (int i=0; i < len; i++) {
            char ins = s[i];
            map<char, Node *> &smap = current->children;

            if (smap.find(ins) == smap.end()) {
                smap[ins] = new Node;
                current = smap[ins];
                current->isaWord = false;  
            } else {
                current = smap[ins];
            }
        } // end this fucking for

        current->isaWord = true;
    }

    void print_all(void)
    {
        display();
        print_levels();

        for (int i = 0; i <= max_level; i++)
        {
            cout << "level " << i << " : ";
            
            for (int j = 0; j < lv[i].size(); j++)
            {
                    cout << lv[i].at(j) << " ";
            }

            cout << endl;
        }
    }

    bool search_word(string word)
    {
        Node *current;
        bool ispresent;
        map<char, Node *> *children;

        current = &root;

        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            children = &current->children;

            if (children->find(c) == children->end()) {
                return false;
            }
            
            current = current->children[c];    
        }
           
        ispresent = current->isaWord;

        return ispresent;        
    }

};

int main()
{
    Trie tr;
    string str;
    
    int i = 9;

    while (i--) {        
        cin >> str;
        tr.insert(str);
    }

    
    tr.print_all();
    cout << "is akhnaton a word " << tr.search_word("akhnaton") << endl;
    cout << "is pagal a word " << tr.search_word("pagal") << endl;
    cout << "is xterm a word " << tr.search_word("xterm") << endl;
 
    cout << "is intercommunication a word " << tr.search_word("intercommunication") << endl;
    string st = "thisispagalpanbehanchodmadarchodd";

    cout << "is " << st << " a word " << tr.search_word(st) << endl;
    return 0;
}
