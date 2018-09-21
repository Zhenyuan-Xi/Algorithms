#include <bits/stdc++.h>
/*
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<string.h>
*/
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef vector<char> VC;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define REP(i,s,t) for(int i=(s);i<(t);++i)
#define RREP(i,s,t) for(int i=(s);i>=(t);--i)
#define ALL(x) (x).begin(),(x).end()
#define FILL(x,v) memset(x,v,sizeof(x))
#define LEN(x) sizeof(x)/sizeof(x[0])
#define MP(x,y) make_pair(x,y)
const int INF=0x3f3f3f3f;
const int dx[]={-1,0,1,0},dy[]={0,-1,0,1}; //i=3-i
/*----------------------------------------------*/
template <class T>
class MaxHeap{
private: 
    T *maxHeap;
    int capacity,size;
    void sink(int start,int end);
    void swim(int start);
public:
    MaxHeap();
    MaxHeap(int capacity);
    ~MaxHeap();
    int getIndex(T ele);
    int insert(T ele);
    int remove(T ele);
    void print();
};

template <class T>
MaxHeap<T>::MaxHeap(){
    new (this)MaxHeap(100);
}

template <class T>
MaxHeap<T>::MaxHeap(int capacity){
    capacity=capacity;
    size=0;
    maxHeap=new T[capacity+1]; //index从1开始
}

template <class T>
MaxHeap<T>::~MaxHeap(){
    capacity=0;
    size=0;
    delete[] maxHeap;
}

template <class T>
int MaxHeap<T>::getIndex(T ele){ //找到元素的index
    REP(i,1,size+1){
        if(ele==maxHeap[i]) return i;
    }
    return -1;
}

template <class T>
void MaxHeap<T>::swim(int start){ //向上调整最大堆
    int p=start>>1;
    T temp=maxHeap[start];
    while(start>1){
        if(maxHeap[p]>=temp) break;
        else{
            maxHeap[start]=maxHeap[p];
            start=p;
            p=p>>1;
        }
    }
    maxHeap[start]=temp;
}

template <class T>
int MaxHeap<T>::insert(T ele){ //将元素插在队尾后向上调整最大堆
    if(size==capacity) return -1;
    maxHeap[++size]=ele;
    swim(size);
    return 0;
}

template <class T>
void MaxHeap<T>::sink(int start,int end){ //向下调整最大堆
    int l=2*start,r=2*start+1;
    T temp=maxHeap[start];
    while(l<=end){
        if(l<end&&maxHeap[l]<maxHeap[r]) l++;
        if(temp>=maxHeap[l]) break;
        else{
            maxHeap[start]=maxHeap[l];
            start=l;
            l=2*l;
        }
    }
    maxHeap[start]=temp;
}

template <class T>
int MaxHeap<T>::remove(T ele){ //将队尾元素移至当前位置后向下调整最大堆
    if(size==0) return -1;
    int idx=getIndex(ele);
    if(idx==-1) return -1;
    maxHeap[idx]=maxHeap[size];
    sink(idx,--size);
    return 0;
}

template <class T>
void MaxHeap<T>::print(){
    REP(i,1,size+1){
        cout<<maxHeap[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int a[]={10,40,30};
    MaxHeap<int>* maxHeap=new MaxHeap<int>();
    REP(i,0,LEN(a)) maxHeap->insert(a[i]);
    maxHeap->print();
    maxHeap->remove(40);
    maxHeap->print();
}
