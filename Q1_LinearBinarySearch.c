// Linear and Binary Search

#include<stdio.h>

int linearSearch(int value, int *arr, int len);
int binarySearch(int value, int *arr, int len);

int main(){
	int arr1[]={4,2,67,2,5,7,3,5,3,2,7,8,3,6,356,89,5,23}, value;
	int arr2[]={1,2,3,4,5,6,7,8,9,11,12,13,14};
	char choice;
	
	printf("Array 1: ");
	for(value=0; value< sizeof(arr1)/sizeof(arr1[0]); value++) printf("%d, ", arr1[value]);
	printf("\nArray 2: ");
    for(value=0; value< sizeof(arr2)/sizeof(arr2[0]); value++) printf("%d, ", arr2[value]);
    printf("\n");
	
	while(1){
	printf("\nEnter element to search: ");
	scanf("%d", &value);
	printf("Enter 1 for linear search\nEnter 2 for binary search\nEnter anything else to exit\n");
	fflush(stdin);
	scanf("%c", &choice);
	if(choice=='1')
	printf("Linear Search result: %d\n", linearSearch(value, arr1, (sizeof(arr1)/sizeof(int))) );
	else if(choice == '2') 
	printf("\nBinary Search result: %d\n", binarySearch(value, arr2, (sizeof(arr2)/sizeof(int))) );
	else return 0;
    }
}

int linearSearch(int value, int *arr, int len) {
	int i;
	for(i=0;i<len;i++) if( *(arr+i) == value ) return (i+1);
	return -1;
}

int binarySearch(int value, int *arr, int end){
	int beg=0, present;
	end--;
	while(end>=beg){
		
		present = (beg+end)/2;
		if( *(arr + present) == value) return (present+1);
		
		if( *(arr + present )  > value) end = present-1; // move left
		else beg = present+1; // move right
		
	}
	return -1;
}
