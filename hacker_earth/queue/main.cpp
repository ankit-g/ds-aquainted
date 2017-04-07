#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int root_node;

void create_graph(vector< vector<int> > &graph)
{
    int once = true;
	vector< vector<int> >::iterator it;

	for (it = graph.begin(); it != graph.end(); it++) {
		int x, y; 		
        cin >> x >> y;
		if (once) {
            root_node = x;
            once = false;
        }

        graph[x].push_back(y);
	}
}

void bfs_graph(vector< vector<int> > &graph)
{
    queue<int> Q;
    vector < pair<bool, int> > visited(graph.size(), make_pair(false, -1));

    Q.push(root_node);
    
    while(!Q.empty())
    {
        int vertex;

        vertex =  Q.front();
        Q.pop();
        
        if (visited[vertex].first)
            continue;

        visited[vertex].first = true;
        visited[vertex].second++;
    
        // push all the connected nodes here

        for (int i = 0; i < graph[vertex].size(); i++) {
            Q.push(graph[vertex].at(i));    
        }       
    }

    
        for (int i = 0; i < visited.size(); i++) {
            cout << visited[i].first << " " << visited[i].second << endl;
        }
}

int main()
{
	int num_nodes;

	cin >> num_nodes;
	vector< vector<int> > graph(num_nodes);

	
    create_graph(graph);
    bfs_graph(graph);

	return 0;
}
