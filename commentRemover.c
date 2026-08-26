#include <stdio.h>

#define MAX 1000

int getLine(char arr[]);
int contains(char arr[], int sizeOfArray, char string[], int sizeOfString);
int main(){
	char arr[MAX];
	char newProgrsm[MAX];

	int length, i, index;
 	i =  0;

	while((length = getLine(arr)) > 0){
		
		if((index = contains(arr, length, "//", 2)) != -1){
			arr[index] = '\n';
			arr[index+1] = '\0';
		}
		
		printf("%s", arr);
	}


	//printf("%d", contains("hello world", 11, "d", 1));

	
	return 0;
}

int getLine(char arr[]){

	int c, i;

	i = 0;

	while((c = getchar()) != '\n'){
		if(c == EOF)
			return -1;
		arr[i] = c;
		++i;
			
	}
	arr[i] = '\n';
	++i;

	return i;
}

int contains(char arr[], int sizeOfArray, char string[], int sizeOfString){

	int i, j, index;
	i=0; 
	j=0;
	index = -1;

	while(i <= sizeOfArray){

		if(arr[i] == string[j]){
			if(index == -1)
				index = i;

			++j;
			if(j == sizeOfString)
				return index;
		}else{
			i-=j;
			j = 0;
			index = -1;
		}
		++i;
	}

	return -1;
}
