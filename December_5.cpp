#include<iostream>
using namespace std;

int main(){

  /*int num=0;
  char input;
  while(cin>>input){
    if(input == '!')
      break;
    num++;
  }

  int *box = new int[num];  
  cout << num << endl;
  */

  int num = 16;
  char box[num];
  for(int i=0; i<num; i++){
    cin >> box[i];
  }

 // while(){
    int sec;
    int cnt=0;
    int n=1;
    while( cnt != num-1){
      sec = cnt+n;
      int n1 = box[cnt];
      int n2 = box[sec];
      if( (n1+32)==n2 || (n1-32)==n2 ){
        box[cnt] = '0';//ascii 48
        box[sec] = '0';
        if(cnt-1>=0){
          cnt--;
          n += 2;
        }
        else
          n=1;
      }
      else{
        cnt++;
        n=1;
      }
    }
  
  //}
  int result=0;
  for(int i=0; i<num; i++){
    //cout << box[i];
    if(box[i] != '0')
      result++;
  }
  cout << "result= " << result << endl;

}
