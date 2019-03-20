#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string input_path = "/Users/jason/Desktop/UVA/input_1205.txt";


void read(){

  bool check = false;
  //ifstream input(input_path);
  string storage; 

  //while(!check){
  //  getline(input, storage);
  //  check = true;
  //}
  
  char type1[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  char type2[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  
  for(int k=0; k<26; k++){
    check = false;
    ifstream input(input_path);
    while(!check){
      getline(input, storage);
      check = true;
    }
    input.close();

    //cout << "type1= " << type1[k] << endl;
    for(int j=0; j<storage.length(); j++){
        if(storage[j] == type1[k] || storage[j] == type2[k]){
          storage.erase(storage.begin()+j, storage.begin()+j+1);
          j--;
      }
    }
   
  //}

  check = false;
  int reactions=0;
  while(!check){
    for(int i=0; i<storage.length(); i++){
      if( isupper(storage[i]) && islower(storage[i+1]) && (tolower(storage[i]) == storage[i+1]) ){
        storage.erase( storage.begin()+i, storage.begin()+i+2 );
        i--;
        reactions++;
      }
      else if( islower(storage[i]) && isupper(storage[i+1]) && (toupper(storage[i]) == storage[i+1]) ){
        storage.erase( storage.begin()+i, storage.begin()+i+2 );
        i--;
        reactions++;
      }  
    }
   
   if(reactions>0){
     reactions=0;
   }
   else{
     check = true;
     cout << "Elements= " << storage.length() << endl;
   }
 }
} 
}


int main(){

  read();
/*
  char type1[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  char type2[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'k', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  for(int i=0; i<26; i++){
    
    char box2[num];
    int  type_cnt=0;
    char box3[num];
    for(int j=0; j<num; j++){
      box2[j] = box[j];
      if(box2[j]==type1[i] || box2[j]==type2[i]){
        box2[j] = '0'; 
        type_cnt++;
      }
    }
   
    int box3_cnt=0; 
    for(int j=0; j<num; j++){
      if(box2[j]!='0'){
        box3[box3_cnt] = box2[j];
        box3_cnt++;
      }
    }
   
    cout << endl;
    cout << type1[i] << endl;
    cout << "box3_cnt= " << box3_cnt << endl;  
    calculate(box3, box3_cnt, type_cnt);
  }
*/
}

