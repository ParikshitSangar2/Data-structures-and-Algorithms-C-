//Merge sort IN C++
#include<iostream>
using namespace std;
void merging(int input [],int low, int mid, int high) { //Recursively
    int b[high-low+1];
    int l1=low,l2=mid+1,i=0;
    while(l1 <= mid && l2 <= high) {
        if(input[l1] <= input[l2])
            b[i++] = input[l1++];
        else
            b[i++] = input[l2++];
    } 
        while(l1 <= mid)  
        {
            b[i++] = input[l1++];
        }

        while(l2 <= high)  
        {
            b[i++] = input[l2++];
        }

        int j=0;
        for(i = low; i <= high; i++)
            input[i] = b[j++];
}
void merge(int arr[],int l, int mid,int r){//Normal way
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];int b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }
    int i=0; int j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++;i++;
        }
        else{
            arr[k]=b[j];
            k++;j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++;i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++;j++;
    }
}
void mergesort(int arr[],int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int arr[]={3,4,5,2,1,6};
    mergesort(arr,0,5);
    for(int i=0;i<=5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
