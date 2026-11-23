#include <stdio.h>

#define TRUE 1
#define FALSE 0

void insertionSort(int arr[], int size){
	for(int i = 1; i < size; i++){
		int key = arr[i];
		int j = i - 1;

		while(j >= 0 && key > arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main(){
	
	int c;
	int firstWhite = FALSE;
	int wordLenCount[10];
	int wordLenSorted[10];
	int longestWord = 0;
	int count = 0;
	int infinityLen = FALSE;
	int infinityCount = 0;
	
	for(int i = 0; i < 10; i++){
		wordLenCount[i] = 0;
	}

	while((c = getchar()) != EOF){
		if(c == ' ' || c == '\n' || c == '\t'){
			if(firstWhite == TRUE){
				firstWhite = FALSE;
				if(count > 10){
					infinityLen = TRUE;	
					++infinityCount;
					count = 0;	
				}
				else{
					++wordLenCount[count-1];
					++wordLenSorted[count-1];
					if(count > longestWord)
						longestWord = count;
					count = 0;
				}	
			}					
		}
		else{
			firstWhite = TRUE;
			count++;
		}
	}
	
	for(int i = 0; i < longestWord; i++){
			printf("Words with length %d | ", i+1);
			for(int j = 0; j < wordLenCount[i]; j++){
				printf("%c", '*');
			}
			printf("\n");
	}
	if(infinityLen == TRUE){
		printf("%d WORDS WITH INFINITE LENGTH", infinityCount);
	}

	printf("\n\n\n\n");
	
	int largestCount = 0;	
	
	insertionSort(wordLenSorted, longestWord);
	
	for(int i=0; i<longestWord; i++){
		if(wordLenCount[i] > largestCount)
			largestCount = wordLenCount[i];
	}

	while(largestCount > 0){
		printf("%02d |", largestCount);
		for(int i=0; i<longestWord; i++){
			if(wordLenCount[i] - largestCount >= 0){
				printf("* ");
			}
			else{
				printf("  ");
			}
		}
		printf("\n");
		--largestCount;
	}	
	printf("___");	
	for(int i=0; i<longestWord; i++){
		printf("__");
	}
	printf("\n    ");
	for(int i=0; i<longestWord; i++){
		printf("%d ", i+1);
	}	
	return 0;
}
