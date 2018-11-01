#include <iostream>
using namespace std;

void CollectOil(int i, int j);
int m, n;
char Map[101][101];
bool collect[101][101];

int main(){

  cin >> m >> n;
  while(m!=0||n!=0){

    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        cin >> Map[i][j];
        collect[i][j] = false;
      }
    }

    int Num=0;
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
         if(Map[i][j]=='@' && collect[i][j]==false){
           Num++;
           CollectOil(i, j);
         }
      }
    }
    cout << Num << endl;
    cin >> m >> n;

  }
}


void CollectOil(int i, int j){
 
  if(i<0||j<0||i>m||j>n){
    return;
  }
  else if(Map[i][j] =='*' || collect[i][j]==true){
    return;
  }
  else{
    collect[i][j] = true;
    CollectOil(i-1,j-1);
    CollectOil(i-1,j);
    CollectOil(i-1,j+1);
    CollectOil(i,j-1);
    CollectOil(i,j+1);
    CollectOil(i+1,j-1);
    CollectOil(i+1,j);
    CollectOil(i+1,j+1);
  } 

}
