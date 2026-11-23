#include <stdio.h>

int takeOut(char arr[], char temp[], int j);
int getLine(char arr[]);

int main(){
	int c, j, k, length, space, isUpdating;
	char arr[100] = {'\0'};
	char temp[8] = {'\0'};
	
	length = 0;

	while((length = getLine(arr)) > 0){
	
		isUpdating=1;
		space = 8;
		j = 0;
		k=0;
		while(j <= length){
			k = takeOut(arr, temp, j);
		
			for(int i = 7; i >= 0; i--){
				if(temp[i] == '-' && isUpdating==1){
					space--;
					temp[i] = '\0';
				}else{
					isUpdating=0;
				}
			}
			if(space < 8)
				temp[space] = '\t';
	
			isUpdating=1;
			space=8;
			
			if(k==(j+8)){
				j+=8;
			}else{
				j=k;
			}
		
	
			for(int i=0; i<8;i++){
				if(temp[i] == '\0'){}
				else{
					printf("%c", temp[i]);
				}	
			}
		}
	}
	return 0;
}

int takeOut(char arr[], char temp[], int j){
	int i, isTab;
	i =0;
	isTab = 0;
	while(i < 8){
		if(isTab == 1){
			temp[i] = '\0';
		}else{
			temp[i] = arr[j];
			arr[j] = '\0';
			++j;
		}
		if(temp[i] == '\t'){
			isTab = 1;
		}
		++i;
	}
	return j;
}


int getLine(char arr[]){
	int c, i;

	i=0;
	while((c=getchar()) != '\n'){
		if(c == EOF)
			return -1;
		arr[i] = c;	
		++i;
	}
	arr[i] = '\n';
	++i;
	
	return i;
}	
