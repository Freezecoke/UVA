#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b);
void heap_sort(vector<int> &A);
void BuildMaxHeap(vector<int> &A);
void MaxHeapify(vector<int> &A, int root, int length);

int main(){
 int a[9] = {9, 4, 1, 6, 7, 3, 8, 2, 5};
 vector<int> A(a, a+sizeof(a)/sizeof(int));

 heap_sort(A);
 for(int i=0; i<A.size(); i++)
   cout << A[i] << " ";
 cout << endl;

}

void swap(int &a, int &b){
  int tmp = a;
  a = b;
  b = tmp;
}

void heap_sort(vector<int> &A){
  A.insert(A.begin(), 0);//heap start from 1
  //A.push_back(0);
  BuildMaxHeap(A);

  int size = A.size()-1;
  for(int i = A.size()-1; i>1; i--){
    swap(A[1], A[i]);
    size--;
    MaxHeapify(A, 1, size);
  }
  
  A.erase(A.begin());
}

void BuildMaxHeap(vector<int> &A){
  for(int i=A.size()/2; i>=1; i--)
    MaxHeapify(A, i, A.size()-1);  
}

void MaxHeapify(vector<int> &A, int root, int length){
 int left = root*2;
 int right = root*2+1;
 int largest;

 if(A[left]>A[root] && left<=length)//left<=length stop, it's MaxHeap now ! largest==root
   largest = left; 
 else
   largest = root;
 
 if(A[right]>A[largest] && right<=length)
   largest = right; 

 if(largest != root){
   swap(A[largest], A[root]);
   MaxHeapify(A, largest, length);
 }
 
  
}
