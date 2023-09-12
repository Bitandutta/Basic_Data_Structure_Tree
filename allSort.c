#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int takeArray(int*, int);
void bubbleSort(int*, int, int);
void selectionSort(int*, int, int);
void insertionSort(int*, int, int);
void quickSortR(int*, int, int, int);
void quickSort(int*, int, int);
int partition(int*, int, int, int);
void mergeSortR(int*, int, int, int);
void mergeArray(int*,int,int,int,int);
void mergeSort(int*, int, int);
void radixSort(int*, int, int);
void heapSort(int*, int);
void heapify(int*, int, int);
void shellSort(int*, int, int);
void displayTimeComplexity();
void displayArray(int*, int);

int main() {
	int arr[100], i, choice, len=-1, order;

	while(1) {
		printf("\n1. Bubble Sort\n");
		printf("2. Selection Sort\n");
		printf("3. Insertion Sort\n");
		printf("4. Quick Sort (Recursive)\n");
		printf("5. Quick Sort (Non-recursive)////////\n");
		printf("6. Merge Sort (Recursive)\n");
		printf("7. Merge Sort (Non-recursive)\n");
		printf("8. Radix Sort\n");
		printf("9. Heap Sort\n");
		printf("10. Shell Sort\n");
		printf("11. Display Time Complexity\n");
		printf("12. Take Array\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		if(choice>12 || choice<1) return 0;
		if(choice<11) {
			if(len==-1) len = takeArray(arr, (sizeof(arr)/(sizeof(arr[0]))));
			if(len==-1) continue; // user enters wrong array size
			printf("Enter 0 for ascending and 1 for descending: ");
			scanf("%d", &order);
		}
		switch(choice) {
			case 1:
				bubbleSort(arr, len, order);
				displayArray(arr,len);
				break;
			case 2:
				selectionSort(arr, len, order);
				displayArray(arr,len);
				break;
			case 3:
				insertionSort(arr, len, order);
				displayArray(arr,len);
				break;
			case 4:
				quickSortR(arr, 0, (len-1), order);
				displayArray(arr,len);
				break;/*
           case 5: quickSort(arr, len, order);
           break;*/
			case 6:
				mergeSortR(arr, 0, (len-1), order);
				displayArray(arr,len);
				break;
			case 7:
				mergeSort(arr, len, order);
				displayArray(arr,len);
				break;/*
           case 8: radixSort(arr, len, order);
           break;*/
           case 9: 
		        heapSort(arr, len);
                displayArray(arr, len);
           break;
			case 10:
				shellSort(arr, len, order);
				displayArray(arr, len);
				break;
			case 11:
				displayTimeComplexity();
				break;
			case 12:
				len = takeArray(arr, (sizeof(arr)/(sizeof(arr[0]))));
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

void bubbleSort(int *arr, int len, int order) {
	int i,j;
	for(i=0; i<(len-1); i++) {
		for(j=0; j<(len-1-i); j++) {
			if(arr[j]<arr[j+1] && order) { // descending order
				order=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=order;
				order=1;
			} else if(arr[j]>arr[j+1] && !order) { // ascending order
				order=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=order;
				order=0;
			} else continue;
		}
	}
}

void selectionSort(int *arr, int len, int order) {
	int i,j;
	for(i=0; i<len-1; i++) {
		for(j=(i+1); j<len; j++) {
			if(arr[i]<arr[j] && order) { // descending order
				order=arr[j];
				arr[j]=arr[i];
				arr[i]=order;
				order=1;
			} else if(arr[i]>arr[j] && !order) { // ascending order
				order=arr[j];
				arr[j]=arr[i];
				arr[i]=order;
				order=0;
			} else continue;
		}
	}
}

void insertionSort(int *arr, int len, int order) {
	int pass=1,y,j;
	while(pass<len) {
		y=arr[pass];
		j=pass-1;
		if(order) { // descending order
			while(j>=0 && y>arr[j]) {
				arr[j+1]=arr[j]; // left shift
				j--;
			}
		} else { // ascending order
			while(j>=0 && y<arr[j]) {
				arr[j+1]=arr[j]; // left shift
				j--;
			}
		}

		arr[j+1]=y;
		pass++;
	}
}

void quickSortR(int *arr, int low, int high, int order) {
	if(low<high) {
		int pointer = partition(arr, low, high, order);
		quickSortR(arr, low, pointer-1, order);
		quickSortR(arr, pointer+1, high, order);
	}
}


int partition(int *arr, int low, int high, int order) {
	int down, pivot, temp;
	pivot=arr[low];
	down = low;

	while(down<high) {

		while(arr[down] <= pivot && down < high) down ++;
		while(arr[high] > pivot) high --;
		
		if(down < high) {
			temp = arr[high];
			arr[high]= arr[down];
			arr[down] = temp;
		}

	}
	
	arr[low] = arr[high];
	arr[high] = pivot;
	return high;

}

/*
void quickSort(int *arr, int len, int order);
*/
void mergeSortR(int *arr, int left, int right, int order) {
	if(right<=left) return;
	int mid = (left+right)/2;
	mergeSortR(arr,left,mid,order);
	mergeSortR(arr,mid+1,right,order);
	mergeArray(arr,left,mid,right,order);
}
void mergeArray(int *arr, int left, int mid, int right, int order) {
	int i, j, k, A[(mid-left)+1], B[(right-mid)];

	k=0;
	for(i=left; i<=mid; i++) A[k++]=arr[i];
	k=0;
	for(i=mid+1; i<=right; i++) B[k++]=arr[i];

	i=0; // counter for array A (till n1)
	j=0; // counter for array B (till n2)
	k=left;
	if(order) { // descending
		while(i<(mid-left+1) && j<(right-mid)) {
			if(A[i]<B[j])
				arr[k++]=B[j++];
			else
				arr[k++]=A[i++];
		}
	} else { // ascending
		while(i<(mid-left+1) && j<(right-mid)) {
			if(A[i]>B[j])
				arr[k++]=B[j++];
			else
				arr[k++]=A[i++];
		}
	}

	while(i<(mid-left+1)) arr[k++] = A[i++];
	while(j<(right-mid)) arr[k++] = B[j++];
}

void mergeSort(int *arr, int len, int order) {
	int size, l1, u1, l2, u2;
	for(size=1; size<len; size*=2) {
		l1=0;
		while((l1+size)<len) {
			l2=l1+size;
			u1=l2-1;
			if((l2+size-1)<len) u2=l2+size-1;
			else u2=len-1;
			mergeArray(arr, l1, u1, u2, order);
			l1 += 2*size;
		}
	}
}

/*
void radixSort(int *arr, int len, int order);
*/

void shellSort(int *arr, int len, int order) {
	int h, pass, y, j;
	for (h = len/2; h >= 1; h /= 2) {
		for (pass = h; pass < len; pass += 1) {
			y = arr[pass];
			if(order) for (j=(pass-h); ((j>=0) && (y>arr[j])) ; j-=h) arr[j+h] = arr[j];
			else  for (j=(pass-h); ((j>=0) && (y<arr[j])) ; j-=h) arr[j+h] = arr[j];
			arr[j+h] = y;
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

void displayTimeComplexity() {
	clock_t start;
	int arr[200000],arr2[200000], len, i; // 200K arrays

	for(i=0; i<200000; i++) arr[i]=rand(); // initialising array

	printf("\n\t\t 10000\t 20000\t 50000\t 60000\t 80000\t 90000\t 140000\t 200000\n");

	// Bubble Sort Row //
	printf("Bubble sort\t");

	// len=10000
	len=10000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	bubbleSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=20000
	len=20000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	bubbleSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=50000
	len=50000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	bubbleSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=60000
	len=60000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	bubbleSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=80000
	len=80000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	bubbleSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=90000
	len=90000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	bubbleSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=140000
	len=140000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	bubbleSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=200000
	len=200000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	bubbleSort(arr2, len, 1);
	printf("%0.4f", (float)(clock()-start)/CLOCKS_PER_SEC);

	// Selection Sort Row //
	printf("\nSelection sort  ");

	// len=10000
	len=10000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	selectionSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=20000
	len=20000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	selectionSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=50000
	len=50000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	selectionSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=60000
	len=60000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	selectionSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=80000
	len=80000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	selectionSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=90000
	len=90000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	selectionSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=140000
	len=140000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	selectionSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=200000
	len=200000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	selectionSort(arr2, len, 1);
	printf("%0.4f", (float)(clock()-start)/CLOCKS_PER_SEC);

	// Insertion Sort Row //
	printf("\nInsertion sort  ");

	// len=10000
	len=10000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	insertionSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=20000
	len=20000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	insertionSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=50000
	len=50000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	insertionSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=60000
	len=60000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	insertionSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=80000
	len=80000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	insertionSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=90000
	len=90000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	insertionSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=140000
	len=140000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	insertionSort(arr2, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=200000
	len=200000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	insertionSort(arr2, len, 1);
	printf("%0.4f", (float)(clock()-start)/CLOCKS_PER_SEC);

	// Merge Sort Row //
	printf("\nMerge sort (rec)");

	// len=10000
	len=10000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSortR(arr, 0, len-1, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=20000
	len=20000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSortR(arr, 0, len-1, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=50000
	len=50000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSortR(arr, 0, len-1, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=60000
	len=60000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSortR(arr, 0, len-1, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=80000
	len=80000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSortR(arr, 0, len-1, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=90000
	len=90000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSortR(arr, 0, len-1, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=140000
	len=140000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSortR(arr, 0, len-1, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=200000
	len=200000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSortR(arr, 0, len-1, 1);
	printf("%0.4f", (float)(clock()-start)/CLOCKS_PER_SEC);

	// Merge Sort Row //
	printf("\nMerge sort      ");

	// len=10000
	len=10000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSort(arr, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=20000
	len=20000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSort(arr, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=50000
	len=50000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSort(arr, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=60000
	len=60000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSort(arr, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=80000
	len=80000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSort(arr, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=90000
	len=90000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSort(arr, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=140000
	len=140000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSort(arr, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=200000
	len=200000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	mergeSort(arr, len, 1);
	printf("%0.4f", (float)(clock()-start)/CLOCKS_PER_SEC);

	// Quick Sort Row //
	printf("\nQuick sort Rec  ");

	// len=10000
	len=10000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	quickSortR(arr, 0, (len-1), 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=20000
	len=20000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	quickSortR(arr, 0, (len-1), 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=50000
	len=50000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	quickSortR(arr, 0, (len-1), 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=60000
	len=60000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	quickSortR(arr, 0, (len-1), 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=80000
	len=80000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	quickSortR(arr, 0, (len-1), 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=90000
	len=90000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	quickSortR(arr, 0, (len-1), 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=140000
	len=140000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	quickSortR(arr, 0, (len-1), 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=200000
	len=200000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	quickSortR(arr, 0, (len-1), 1);
	printf("%0.4f", (float)(clock()-start)/CLOCKS_PER_SEC);

	// Shell Sort Row //
	printf("\nShell sort      ");

	// len=10000
	len=10000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	shellSort(arr, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=20000
	len=20000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	shellSort(arr, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=50000
	len=50000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	shellSort(arr, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=60000
	len=60000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	shellSort(arr, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=80000
	len=80000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	shellSort(arr, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=90000
	len=90000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	shellSort(arr, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=140000
	len=140000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	shellSort(arr, len, 1);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=200000
	len=200000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	shellSort(arr, len, 1);
	printf("%0.4f", (float)(clock()-start)/CLOCKS_PER_SEC);
	
	    // Heap Sort Row //
	printf("Heap sort\t");

	// len=10000
	len=10000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	heapSort(arr2, len);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=20000
	len=20000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	heapSort(arr2, len);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=50000
	len=50000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	heapSort(arr2, len);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=60000
	len=60000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	heapSort(arr2, len);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=80000
	len=80000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	heapSort(arr2, len);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=90000
	len=90000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	heapSort(arr2, len);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=140000
	len=140000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	heapSort(arr2, len);
	printf("%0.4f\t", (float)(clock()-start)/CLOCKS_PER_SEC);

	// len=200000
	len=200000;
	for(i=0; i<len; i++) arr2[i]=arr[i]; // making copy
	start=clock();
	heapSort(arr2, len);
	printf("%0.4f", (float)(clock()-start)/CLOCKS_PER_SEC);

	printf("\n");
}
