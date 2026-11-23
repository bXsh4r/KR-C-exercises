#include <stdio.h>
#define MAXLINE 10

int getLine(char arr[], int limit);
int copy(char from[], char to[], int j);

int main(){
	int c, i, len, index;
	char arr[MAXLINE];
	char longestString[MAXLINE*10];
	
	index=0;
	while((len = getLine(arr, MAXLINE)) > 0){
		if(len > 5){
			index = copy(arr, longestString, index);
	
		}
	}
	printf("%s", longestString);
}

int getLine(char arr[], int limit){
	int i, c;

	for(i=0; i<limit-1 && (c=getchar()) != EOF && c != '\n'; ++i){
		arr[i] = c;
	}
	if(c == '\n'){
		arr[i] = c;
		++i;
	}
	arr[i] = '\0';
	return i;
}

int copy(char from[], char to[], int j){
	int i = 0;

	while((to[j] = from[i]) != '\0'){
		++i;
		++j;
	}
	return j;
}
