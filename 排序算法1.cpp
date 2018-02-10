#include <iostream>

using namespace std;
//1.插入法排序
void InsertSort(int nums[],int len){
    int i,j;
    int temp;
    for(i=1;i<len;i++){
        temp=nums[i];
        for(j=i-1;j>=0&&nums[j]>temp;j--)
            nums[j+1]=nums[j];
        nums[j+1]=temp;
    }
}

//2.冒泡法排序
void BubbleSort(int nums[],int len){
    int i,j,temp;
    for(i=0;i<len;i++)
        for(j=0;j<len-1-i;j++){
            if(nums[j]>nums[j+1]){
                temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
}

//3.选择法排序
void ChooseSort(int nums[],int len){
    int i,j;
    int temp;
    for(i=0;i<len-1;i++){
        for(j=i+1;j<len;j++)
            if(nums[j]<nums[i]){
                temp=nums[j];nums[j]=nums[i];nums[i]=temp;
            }
    }
}

//4.归并排序
void Merge(int nums[],int reg[],int start,int end){
    if (start >= end)return;
    int len=end-start,mid=start+len/2;
    Merge(nums,reg,start,mid);
    Merge(nums,reg,mid+1,end);
    int l=start,r=mid+1;
    int k=start;
    while(l<=mid&&r<=end)
        reg[k++]=nums[l]<=nums[r]?nums[l++]:nums[r++];
    while(l<=mid)
        reg[k++]=nums[l++];
    while(r<=end)
        reg[k++]=nums[r++];
    for(k=start;k<=end;k++)
        nums[k]=reg[k];
}
void MergeSort(int nums[],int len){
    int start=0,end=len-1;
    int reg[len];
    Merge(nums,reg,start,end);
}

//5.快速排序
void OnceSort(int nums[],int start,int end){
    //初始时以最后一个数为轴
    int i=start,j=end;
    int pivot=nums[end];
    if(start>=end) return;
    while(i<j){
        while(i<j&&nums[i]<pivot) i++;
        if(i<j){
            nums[j]=nums[i];
        }
        while(i<j&&nums[j]>pivot) j--;
        if(i<j){
            nums[i]=nums[j];
        }
    }
    nums[i]=pivot;
    OnceSort(nums,start,i-1);
    OnceSort(nums,i+1,end);
}
void QuickSort(int nums[],int len){
    OnceSort(nums,0,len-1);
}

//6.堆排序
void Heapify(int nums[],int start,int end){
    //调整使新加入元素于根节点时仍然为堆;
    int father=start,son=father*2+1;
    int temp;
    while(son<=end){
        //定位左右子节点中较大的一个;
        if(son+1<=end&&nums[son]<nums[son+1]) son++;
        if(nums[father]>=nums[son]) break;  //调整完毕
        temp=nums[father];nums[father]=nums[son];nums[son]=temp;
    }
}
void HeapSort(int nums[],int len){
    int i;
    //初始化堆
    for(i=len/2-1;i>=0;i--)
        Heapify(nums,i,len-1);
    int temp;
    for(i=len-1;i>0;i--){
        temp=nums[i];nums[i]=nums[0];nums[0]=temp;
        //调整成堆
        Heapify(nums,0,i-1);
    }
}

int main()
{
    //有关测试
    int nums[]={6,1,8,3,2,4,5,7};
    int len=sizeof(nums)/sizeof(nums[0]);
    int i;
    for(i=0;i<len;i++) cout<<nums[i]<<' ';
    cout<<endl;
    InsertSort(nums,len);
    //BubbleSort(nums,len);
    //ChooseSort(nums,len);
    //MergeSort(nums,len);
    //QuickSort(nums,len);
    //HeapSort(nums,len);
    for(i=0;i<len;i++) cout<<nums[i]<<' ';
    cout<<endl;
    return 0;
}
