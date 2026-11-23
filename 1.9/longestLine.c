#include <stdio.h>
#define MAXLINE 10

int getLine(char line[], int limit);
void copy(char to[], char from[]);
int getRemainingLength();
void reverseString(char s[], int length);

int main(){

	int len;
	int max;
	int remainingLength;
	int totalLength;
	char line[MAXLINE];
	char longest[MAXLINE];
	char longStrings[MAXLINE*10];

	max = 0;
	while((len = getLine(line, MAXLINE)) > 0){	
		totalLength = len;
		if(line[len-1] != '\n'){
			remainingLength = getRemainingLength();
			totalLength = remainingLength + len;
		}

		if(totalLength >= max){
			max = totalLength;
			copy(longest, line);
		}
		
		if(totalLength > 5){
	//		printf("%s", line);
		}
		reverseString(line, len);
		printf("%s", line);
		if(line[len-1] != '\n')
			printf("\n");
	}
	if(max > 0){
		printf("%d, %s",max, longest);
	}
	return 0;
}

int getLine(char line[], int limit){
	int i, c, whitespaces;
	whitespaces = 0;
	for(i=0; i < limit-1 && (c=getchar()) != EOF && c != '\n'; i++){	
		line[i] = c;

		if(c == ' ' || c == '\t'){
			++whitespaces;
		}else{
			whitespaces = 0;
		}
	}
	i = i - whitespaces;

	if(c == '\n'){
		line[i] = c;
		i++;
	}
			
	line[i] = '\0';
	return i;
}

void copy(char to[], char from[]){
	int i = 0;
	while((to[i] = from[i]) != '\0'){
		i++;
	}
}	

int getRemainingLength(){
	int i = 0;
	int c;
	while((c =getchar()) != '\n' && c != EOF){
	i++;
	}
	return ++i;
}

void reverseString(char s[], int length){
	int temp;
	int j;
	j = length;
	if(length > 1){
		if(s[length-1] == '\n'){
			--j;
		}
		for(int i=0; i<(length)/2; i++){
			temp = s[i];
			s[i] = s[j-1-i];
			s[j-1-i] = temp;	
		}
	}
}
