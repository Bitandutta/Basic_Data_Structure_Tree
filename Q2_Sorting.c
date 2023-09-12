#include <stdio.h>
#include <stdlib.h>

int takeArray(int*, int);
void selectionSort(int*, int);
void mergeSortR(int*, int, int);
void mergeArray(int*,int,int,int);
void mergeSort(int*, int);
void heapSort(int*, int);
void heapify(int*, int, int);
void displayArray(int*, int);

int main() {
	int arr[100], choice, len;

	while(1) {

        len = takeArray(arr, (sizeof(arr)/(sizeof(arr[0]))));

		printf("\n1. Selection Sort\n");
		printf("2. Merge Sort (Recursive)\n");
		printf("3. Merge Sort (Non-recursive)\n");
		printf("4. Heap Sort\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		if(choice>4 || choice<1) return 0; // exit
		
		switch(choice) {
			case 1:
				selectionSort(arr, len);
				displayArray(arr,len);
				break;
			case 2:
				mergeSortR(arr, 0, (len-1));
				displayArray(arr,len);
				break;
			case 3:
				mergeSort(arr, len);
				displayArray(arr,len);
				break;
           case 4: 
		        heapSort(arr, len);
                displayArray(arr, len);
           break;
			default:
				;
		}
	}
}

void displayArray(int *arr, int len) {
	int i;
	printf("\nArray: ");
	for(i=0; i<len; i++) printf("%d, ", arr[i]);
	printf("\n");
}

int takeArray(int *arr, int max) {
	int i, len;
	printf("\nEnter number of element for array: ");
	scanf("%d", &len);
	if(len>max || len<1) {
		printf("Wrong array size entered!");
		return -1;
	}
	printf("\n");
	for(i=0; i<len; i++) {
		printf("Enter %d element: ", (i+1));
		scanf("%d", &arr[i]);
	}
	return len;
}

void selectionSort(int *arr, int len) {
	int i,j, cache;
	for(i=0; i<len-1; i++) {
		for(j=(i+1); j<len; j++) {
            if(arr[i]>arr[j]) { // ascending order
				cache=arr[j];
				arr[j]=arr[i];
				arr[i]=cache;
			}
		}
	}
}

void mergeSortR(int *arr, int left, int right) {
	if(right<=left) return;
	int mid = (left+right)/2;
	mergeSortR(arr,left,mid);
	mergeSortR(arr,mid+1,right);
	mergeArray(arr,left,mid,right);
}
void mergeArray(int *arr, int left, int mid, int right) {
	int i, j, k, A[(mid-left)+1], B[(right-mid)];

	k=0;
	for(i=left; i<=mid; i++) A[k++]=arr[i];
	k=0;
	for(i=mid+1; i<=right; i++) B[k++]=arr[i];

	i=0; // counter for array A (till n1)
	j=0; // counter for array B (till n2)
	k=left;

		while(i<(mid-left+1) && j<(right-mid)) {
			if(A[i]>B[j])
				arr[k++]=B[j++];
			else
				arr[k++]=A[i++];
		}

	while(i<(mid-left+1)) arr[k++] = A[i++];
	while(j<(right-mid)) arr[k++] = B[j++];
}

void mergeSort(int *arr, int len) {
	int size, l1, u1, l2, u2;
	for(size=1; size<len; size*=2) {
		l1=0;
		while((l1+size)<len) {
			l2=l1+size;
			u1=l2-1;
			if((l2+size-1)<len) u2=l2+size-1;
			else u2=len-1;
			mergeArray(arr, l1, u1, u2);
			l1 += 2*size;
		}
	}
}

void heapify(int *arr, int size, int root){
	int largest = root, left = (2*root)+1, right = (2*root)+2, cache;
	
    if(left<size && arr[left]>arr[largest]) largest = left;
    if(right<size && arr[right]>arr[largest]) largest = right;
	
	if(largest != root){ // swap
		cache = arr[root];
		arr[root] = arr[largest];
		arr[largest] = cache;
		heapify(arr, size, largest);
	}
}
void heapSort(int *arr, int size){
	int root, cache;
	for(root = size/2-1; root>=0 ; root--) heapify(arr, size, root);
	
	for(root=0; root<size-1; root++){
		cache = arr[0];
		arr[0] = arr[size-1-root];
		arr[size-1-root] = cache;
		heapify(arr, size-root-1, 0);
	}
}
