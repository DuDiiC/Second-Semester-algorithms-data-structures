/*
 *Implementation of the adjacency list for a graph of unknown size
 */

#include <iostream>
#include <vector>
#include <algorithm>

typedef int TYPE;

using namespace std;

class V {
    public:
        TYPE value;
        vector < TYPE > setNodes;
};

bool sorting(V first, V second) {
    return first.value < second.value;
}

void loadDataIntoTheGraph(vector < V >  &G, V v) {

    TYPE V1, V2;

    while(cin >> V1 >> V2 && V1 >0 && V2 > 0) {
        bool there = false;
        for(int i = 0; i < G.size(); ++i) {
            if(V1 == G[i].value) {
                there = true;
                bool there2 = false;
                for(int j = 0; j < G[i].setNodes.size(); ++j) {
                    if(G[i].setNodes[j] == V2) {
                        there2 = true;
                        break;
                    }
                }
                if(!there2) G[i].setNodes.push_back(V2);
                break;
            }
        }
        if(!there) {
            G.push_back(v);
            G[G.size()-1].value = V1;
            G[G.size()-1].setNodes.push_back(V2);
        }
    }
}


void writeSorted(vector < V > &G) {

    sort(G.begin(), G.end(), sorting);

    for(int i = 0; i < G.size(); ++i) {
        cout << "V = " << G[i].value << ": ";

        sort(G[i].setNodes.begin(), G[i].setNodes.end());

        for(int j = 0; j < G[i].setNodes.size(); ++j) {
            cout << G[i].setNodes[j] << " ";
        }

        cout << endl;
    }
}



int main() {

    vector < V > graph;
    V representant;

    loadDataIntoTheGraph(graph, representant);

    writeSorted(graph);

    return 0;
}
