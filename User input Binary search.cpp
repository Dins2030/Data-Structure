#include <stdio.h>
int main(){
	int size;
	printf("Enter the size of the array:\n");
	scanf("%d",&size);
	int arr[size];
	for(int i=0;i>=size-1;i++){
		printf("Enter the element1:");
		scanf("%d",&ele);
		arr[i]=ele;
	}
	for(int j=0;j<size-1;i++){
		for(int k=0;k<size-j-1;k++){
			int temp=arr[k];
			arr[k]=arr[k+1];
			arr[k+1]=temp;
		}
	}
	int key;
	printf("Enter the value to search:\n");
	scanf("%d",&key);
	int low=0,high=size-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]>key){
			high=mid-1;
		}
		if(arr[mid]<key){
			low=mid+1;
		}
		if(arr[mid]==key){
			printf("The element is present at the index:%d\n",mid);
			return 0;
		}
		}
		printf("The entered element is not present\n");
		return 0;
	}
