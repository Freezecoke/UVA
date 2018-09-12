#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph{
private:
  int num_vertex;
  vector< list<int> > AdjList;
  int *color;//0=white 1=gray 2=black
  int *distance;
  int *predecessor;

public:
  Graph():num_vertex(0){};//default constructor
  Graph(int N):num_vertex(N){
    AdjList.resize(num_vertex);
  };
  void AddEdgeList(int from, int to);
  void DFS(int Start);
  void DFSVisit(int vertex, int &time);
};

void Graph::AddEdgeList(int from, int to){
  AdjList[from].push_back(to);
}


void Graph::DFS(int Start){
  
  color = new int[num_vertex];
  distance = new int[num_vertex];
  predecessor = new int[num_vertex];

  //initialize
  for(int i=0; i<num_vertex; i++){
    color[i] = 0;
    distance[i] = num_vertex + 1;
    predecessor[i] = -1;
  }

  stack<int> s;
  int i = Start;
  int time = 0;
  for(int j=0; j<num_vertex; j++){
    if(color[i]==0){
	DFSVisit(i, time);
      }
      i = j;
      cout << "j= "<< j << " Time=" << distance[i] << endl;
    }
  
}

void Graph::DFSVisit(int vertex, int &time){
      time++;
      color[vertex] = 1;
      distance[vertex] = time;
      predecessor[vertex] = -1;
  

        for(list<int>::iterator itr=AdjList[vertex].begin(); itr!=AdjList[vertex].end(); itr++){
          if(color[*itr] == 0){
            predecessor[*itr] = vertex;
	    DFSVisit(*itr, time);
          }
        }
        color[vertex] = 2;       

}

int main(){
  Graph g1(9);
  g1.AddEdgeList(0,1);g1.AddEdgeList(0,2);g1.AddEdgeList(0,3);
  g1.AddEdgeList(1,4);
  g1.AddEdgeList(3,7);
  g1.AddEdgeList(4,5);
  g1.AddEdgeList(5,8);
  g1.AddEdgeList(8,6);
  
  g1.DFS(0);
}
