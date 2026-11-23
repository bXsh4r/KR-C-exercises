#include <stdio.h>
#define MAX 100

int main(void){
	int c, count, tabs, blanks, extraBlanks;
	count = 0;
	while((c = getchar()) != EOF){
		
		while(c == ' '){
			c = getchar();
			++count;
		}

		if(count <= 0){
			printf("%c", c);
			++extraBlanks;
		}
		else{		
			tabs = count / 8;
			blanks = count - (tabs * 8);
			if(count >= 8)
				blanks+=extraBlanks;
			for(int i=1; i <= tabs; i++)
				printf("%c", '\t');
			for(int i=1; i <= blanks; i++)
				printf("%c", '-');
			printf("%c", c);
			count = 0;
			extraBlanks = -1;
		}
	}
}
