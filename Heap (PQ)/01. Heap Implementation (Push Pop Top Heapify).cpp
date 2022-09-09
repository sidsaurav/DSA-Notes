#include <bits/stdc++.h>
using namespace std;

// Implementation of Min-Heap-

/*
TC-
push() -> O(log(sz))
pop() -> O(log(sz))
top() -> O(1)
*/

vector<int> heap_array;
const int N = 1001000;
int sz = 0; // use sz variable carefully as we are starting from index 1. 

void push(int num){
    sz++;
    heap_array[sz] = num;
    int i = sz;
    while(i>1){
        if(heap_array[i/2] > heap_array[i]){ //in case of min heap..
            swap(heap_array[i/2], heap_array[i]);
            i /= 2;
        }
        else{
            break;
        }
    }
}

int top(){
    if(sz == 0) return -1;
    else return heap_array[1];
}

void heapify_min(int i){
    if(i>sz) return;

    int par = heap_array[i];
    int left = 2*i>sz ? 2e9 : heap_array[2*i];
    int right = 2*i+1>sz ? 2e9 : heap_array[2*i + 1];

    if(par <= left and par <= right) return; // if par itself is minimum then stop.
    if(left <= par and left <= right){
        swap(heap_array[i], heap_array[2*i]);
        heapify_min(2*i);
    }
    else{
        heapify_min(2*i + 1);
    }
}

void pop(){
    if(sz == 0) return;

    swap(heap_array[1], heap_array[sz]);
    sz--;
    heapify_min(1);
}


int main(){
    heap_array.resize(N);
    heap_array[0] = -1; // we have to avoid index 0. we can skip this step as well.
    push(5);
    push(2);
    push(8);
    push(1);
    push(3);
    pop();
    // pop();
    // push(3);
    cout << top(); // output : 2
}    