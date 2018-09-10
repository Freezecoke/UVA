#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
  void BFS(int Start);
};

void Graph::AddEdgeList(int from, int to){
  AdjList[from].push_back(to);
}


void Graph::BFS(int Start){
  
  color = new int[num_vertex];
  distance = new int[num_vertex];
  predecessor = new int[num_vertex];

  //initialize
  for(int i=0; i<num_vertex; i++){
    color[i] = 0;
    distance[i] = num_vertex + 1;
    predecessor[i] = -1;
  }

  queue<int> q;
  int i = Start;

  for(int j=0; j<num_vertex; j++){
    if(color[i]==0){
      color[i] = 1;
      distance[i] = 0;
      predecessor[i] = -1;
      q.push(i);

      while(!q.empty()){
        int u = q.front();
        for(list<int>::iterator itr=AdjList[u].begin(); itr!=AdjList[u].end(); itr++){
          if(color[*itr] == 0){
            color[*itr] = 1;
            distance[*itr] = distance[u] + 1;
            predecessor[*itr] = u;
            q.push(*itr);
          }
        }
        q.pop();
        color[u] = 2;       
      }
    }
    i = j;
   cout << "j= "<< j << " distance=" << distance[i] << endl;
  } 
  
}

int main(){
  Graph g1(9);
  g1.AddEdgeList(0,1);g1.AddEdgeList(0,2);g1.AddEdgeList(0,3);
  g1.AddEdgeList(1,0);g1.AddEdgeList(1,2); 
  g1.AddEdgeList(2,0);g1.AddEdgeList(2,4);g1.AddEdgeList(2,5);g1.AddEdgeList(2,6);g1.AddEdgeList(2,7);
  g1.AddEdgeList(3,0);g1.AddEdgeList(3,2);
  g1.AddEdgeList(4,1);g1.AddEdgeList(4,5);g1.AddEdgeList(4,2);
  g1.AddEdgeList(5,4);g1.AddEdgeList(5,8);g1.AddEdgeList(5,2);
  g1.AddEdgeList(6,2);g1.AddEdgeList(6,8);g1.AddEdgeList(6,7);
  g1.AddEdgeList(7,3);g1.AddEdgeList(7,2);g1.AddEdgeList(7,6);
  g1.AddEdgeList(8,5);g1.AddEdgeList(8,6);
  
  g1.BFS(0);
}
