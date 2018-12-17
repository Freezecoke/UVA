#include<iostream>
#include"math.h"
using namespace std;

int main(){

  string buffer;
  string input[1042];

  for(int i=0; i<1041; i++){
    while(cin >> buffer){
      input[i] = input[i] + buffer + ' ';
      if(buffer == "asleep" || buffer == "up" || buffer == "shift")
        break;
    }
    //cout << input[i] << endl;
  }


  char input2[1042][100];
  for(int i=0; i<1041; i++){
      strcpy(input2[i], input[i].c_str());
      //cout << input2[i] << endl;
  }
 
  char Buffer[100];
  for(int i=0; i<1041-1; i++){
    for(int j=0; j<1041-i-1; j++){
      int n1 = input2[j][6]*pow(10,7)+input2[j][7]*pow(10,6)+input2[j][9]*pow(10,5)+input2[j][10]*pow(10,4)
               +input2[j][12]*pow(10,3)+input2[j][13]*pow(10,2)+input2[j][15]*pow(10,1)+input2[j][16];
      int n2 = input2[j+1][6]*pow(10,7)+input2[j+1][7]*pow(10,6)+input2[j+1][9]*pow(10,5)+input2[j+1][10]*pow(10,4)
               +input2[j+1][12]*pow(10,3)+input2[j+1][13]*pow(10,2)+input2[j+1][15]*pow(10,1)+input2[j+1][16];
      if(n1 > n2){
        
        for(int k=0; k<100; k++)
          Buffer[k] = input2[j][k];
	
        for(int k=0; k<100; k++)
          input2[j][k]= input2[j+1][k];
        
        for(int k=0; k<100; k++)
          input2[j+1][k] = Buffer[k];
      }
    }
  }
  for(int i=0; i<10; i++)
    cout << input2[i] << endl;


  cout << "Date" << "   ID" << "     Minute" << endl;
  cout << "              000000000011111111112222222222333333333344444444445555555555" << endl;
  cout << "              012345678901234567890123456789012345678901234567890123456789" << endl;
  int asleep;
  int up;
  char minute[60];
  int flag=1;
  int ID[100]; 
  int ID_counts[100];
  //int most[60];//part 1
  int most[23][60];//part 2
  int id=0;
  for(int i=0; i<100; i++){
    ID[i] = 0;
    //most[i] = 0;
    ID_counts[i] = 0;
  }
  for(int i=0; i<23; i++){
    for(int j=0; j<60; j++){
      most[i][j] = 0;
    }
  }
  for(int i=0; i<1041; i++){
    if(input2[i][26]!='s' && input2[i][26]!='p'){
      
      if(flag != 1){
        cout << "  ";
        for(int j=0; j<60; j++)
          cout << minute[j];
        cout << endl;
      }
      flag = 0;// use for the first time
      cout << input2[i][6] << input2[i][7] << '-' << input2[i][9] << input2[i][10];
      
      for(int j=0; j<60; j++)
        minute[j] = '.';

      int len=26;
      while(input2[i][len] != 'b')
        len++;
      len = len - 26 - 1;
      id = 0;
      for(int j=0; j<len; j++)
        id = id + (input2[i][26+j]-48)*pow(10, len-j-1);
      cout << "  #" << id; 
      for(int j=2; j<(6-len); j++)
        cout << " ";
  
      bool flag2 = false;
      for(int j=0; j<100; j++){
        if(ID[j]==id){
          flag2 = true;
          break;
        }
      }
      if(flag2 == false){
        for(int j=0; j<100; j++){
          if(ID[j]==0){
            ID[j] = id;
            break;
          }
        }
      }
    }
    else if(input2[i][26]=='s'){
      asleep = (input2[i][15]-48)*10 + (input2[i][16]-48); 
    }
    else{

      up = (input2[i][15]-48)*10 + (input2[i][16]-48);
      int mem;
      for(int j=0; j<100; j++){
        if(ID[j]==id){
          mem = j;
          break;
        }
      }
      
      for(int j=asleep; j<up; j++){
        minute[j] = '#';
        //if(j==45) 
        ID_counts[mem]++;
        //if(id==2851)
        most[mem][j]++;
        //if(j==45)
          //cout << "id= " <<id << endl;     
      }
    } 
  }
        cout << "  ";
        for(int j=0; j<60; j++)
          cout << minute[j];
        cout << endl;

    for(int j=0; j<100; j++){
      cout << "ID= " << ID[j] << " ID_counts= " << ID_counts[j] << endl;
    } 
    
    //cout << "2851" << endl;
    //for(int j=0; j<60; j++)
    //  cout << j << " " << most[j] << endl;
    for(int i=0; i<23; i++){
      for(int j=0; j<60; j++){
        cout << ID[i] << " " << j << " =" << most[i][j] << endl;
      }
    }
}
