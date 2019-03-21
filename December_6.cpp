#include<iostream>
#include<fstream>
#include<string>

#include "math.h"
using namespace std;

string input_path = "/Users/jason/Desktop/UVA/input_1206.txt";

int main(){

  ifstream input(input_path);
  string storage;
  bool check = false;
  int x[50];
  int y[50];
  int x_length;
  int y_length;
  int cnt=0;
  while( getline(input, storage) ){
    cout << storage << endl;
    
    x_length = 0;
    y_length = 0;
    
    for(int i=0; i<storage.length(); i++){
      if(storage[i] != ',')
        x_length++;
      else{
        y_length = storage.length() - x_length -2;//, and space
	break;
      }    
    }

    //initialize
    x[cnt] = 0;
    y[cnt] = 0;
    for(int i=0; i<x_length; i++){
       x[cnt] += (storage[i]-48) * pow(10, x_length-i-1);
    }
    for(int i=0; i<y_length; i++){
       y[cnt] += (storage[i+x_length+2]-48) * pow(10, y_length-i-1);
    }
    //cout << "x[cnt]= " << x[cnt] << " y[cnt]=" << y[cnt] << endl;
    //cout << "x_length= " << x_length << " y_length= " << y_length << endl;
    cnt++;
  }


}
