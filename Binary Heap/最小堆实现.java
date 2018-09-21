class MinHeap{
    public int[] minHeap;
    public int capacity,size;
    public MinHeap(){
        minHeap=new int[100];
    }
    public MinHeap(int cap){
        this.capacity=cap;
        this.size=0;
        minHeap=new int[cap+1];
    }
    
    public int getIndex(int ele){
        for(int i=1;i<size+1;i++){
            if(ele==minHeap[i]) return i;
        }
        return -1;
    }
    
    public int insert(int ele){
        if(size==capacity) return -1;
        minHeap[++size]=ele;
        swim(size);
        return 0;
    }
    
    public void swim(int start){
        int p=start>>1;
        int temp=minHeap[start];
        while(start>1){
            if(minHeap[p]<=temp) break;
            else{
                minHeap[start]=minHeap[p];
                start=p;
                p=p>>1;
            }
        }
        minHeap[start]=temp;
    }
    
    public int remove(int ele){
        if(size==0) return -1;
        int idx=getIndex(ele);
        if(idx==-1) return -1;
        minHeap[idx]=minHeap[size];
        sink(idx,--size);
        return 0;
    }
    
    public void sink(int start,int end){
        int l=2*start,r=2*start+1;
        int temp=minHeap[start];
        while(l<=end){
            if(l<end&&minHeap[l]>minHeap[r]) l++;
            if(temp<=minHeap[l]) break;
            else{
                minHeap[start]=minHeap[l];
                start=l;
                l=2*l;
            }
        }
        minHeap[start]=temp;
    }
    
    public void print(){
        for(int i=1;i<size+1;i++){
            System.out.print(minHeap[i]+" ");
        }
        System.out.println();
    }
}

class Main{
    public static void main(String[] args){
        int[] a=new int[]{40,10,30};
        MinHeap minHeap=new MinHeap(20);
        for(int i=0;i<a.length;i++) minHeap.insert(a[i]);
        minHeap.print();
        minHeap.remove(10);
        minHeap.print();
    }
}
