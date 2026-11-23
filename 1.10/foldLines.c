#include <stdio.h>

#define MAX 100
#define COL 10

int newLineTracker;

int getLine(char arr[]);
int foldLine(char buffer[], char arr[], int j, int overflow);


int main(){
	
	char arr[MAX];
	char buffer[COL];
	int length;
	
	while((length = getLine(arr)) > 0){
		int j = 0;
		int currentLength = length;
		newLineTracker = 0;

		while(currentLength > COL){
			int i = 0;
			while(i < COL){
				buffer[i] = arr[j];
				++i;	
				++j;
			}
			int incompleteLine;
			incompleteLine = foldLine(buffer, arr, j, 0);
			newLineTracker+=i;

			if(incompleteLine == 1 && newLineTracker > 10)
				foldLine(buffer, arr, j, 1);
			int space = 1;
			for(int i=COL-1; i>=0; i--){
				if(space == 1 && buffer[COL - 1 - i] != ' ')
					space = 0;
				if(space == 0)
					putchar(buffer[COL - 1 - i]);
			}
			if(incompleteLine == 1 || (incompleteLine == 1 && buffer[COL-1] != ' '))
				putchar('\n');
			currentLength-=COL;
		}
		for(int i=j; i<length; i++){
			putchar(arr[i]);
		}
	}	
	
	return 0;
} 

int getLine(char arr[]){
	int i, c;
	i=0;
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

int foldLine(char buffer[], char arr[], int j, int overflow){

	int incompleteLine = 1;
	if(buffer[COL-1] != ' ' && arr[j] != ' ' || overflow == 1){
		for(int i=COL-1; i>=0 && incompleteLine == 1; i--){
			if(overflow == 1)
				newLineTracker = 0;
			if(buffer[i] == ' '){
				buffer[i] = '\n';
				incompleteLine = 0;	
			}
			++newLineTracker;
		}
	}
	return incompleteLine;	
}
