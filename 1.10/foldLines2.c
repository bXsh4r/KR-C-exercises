#include <stdio.h>

#define MAX 100
#define COL 10

int getLine(char arr[]);

int main(){
	char arr[MAX];
	char buffer[COL];
	int length, currentLength, i, j, limit, extraChars, incompleteLine;
	
	while((length = getLine(arr)) > 0){
		currentLength = length;
		j=0;
		extraChars = 0;
		while(currentLength > 0){
			incompleteLine = 0;
			limit = COL;
			limit -= extraChars;
			extraChars = 0;
			i=0;
			while(i < limit && j < length){
				buffer[i] = arr[j];
				++i;
				++j;
			}
			if(buffer[i-1] != ' ' && arr[j] != ' '){
				for(int index=i-1; index>=0 && incompleteLine == 0; index--){
					if(buffer[index] == ' '){
						buffer[index] = '\n';
						incompleteLine = 1;
					}else{
						++extraChars;					
					}
				}	
			}
			for(int index = 0; index < i; ++index){
				if(index == 9 && extraChars == 10){
					putchar('-');
					putchar('\n');
					incompleteLine = 1;
					extraChars = 0;
				}
				putchar(buffer[index]);
			}
			
			if(incompleteLine == 0)
				putchar('\n');
			currentLength -= i;
		}			
	}
	return 0;
}

int getLine(char arr[]){
	int i, c;
	i =0;
	while((c = getchar()) != '\n'){
		if(c == EOF)
			return -1;
		arr[i] = c;
		++i;
	}
	arr[i]=' ';
	
	return i;
}
