#include <stdio.h>

int main(void){
	int c, count;

	count = 8;
	while((c=getchar()) != EOF){
		if(count == 0 || c == '\n')
			count = 8;
		if(c == '\t'){
			while(count > 0){
				printf("_");
				--count;
			}
		}else{
			printf("%c", c);
			if(c != '\n')
				--count;
		}	
	}	
}
