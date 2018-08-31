#include<iostream>
using namespace std;

void quick_sort(int a[], int left, int right);
int partition(int a[], int left, int right);

int main(){

    //int A[10]={5,4,9,6,7,2,4,3,5,1};
    int A[9]={6,5,1,3,8,4,7,9,2};
    quick_sort(A,0,8);
    for(int i=0;i<9;i++)
       cout<<A[i];
    cout <<endl;

}

void quick_sort(int a[], int left, int right){

  int pivot;

  if(left<right){
    pivot = partition(a, left, right);
    quick_sort(a, left, pivot-1);
    quick_sort(a, pivot+1, right);
  }

}

int partition(int a[], int left, int right){

  int i = left+1;
  int j;
  int tmp;

  for(j=left+1; j<=right; j++){
    if(a[left]>=a[j]){
       //cout << i << endl;
       //cout << j << endl;
       //cout << a[j] << endl;
       tmp = a[i];
       a[i] = a[j];
       a[j] = tmp;
       i++;
    }
  }
  tmp = a[i-1];
  a[i-1] = a[left];
  a[left] = tmp;
  //cout << i << endl;
  //cout << "left= " << left << endl;
  //cout << "right= " << right << endl;
  return i-1;
}
