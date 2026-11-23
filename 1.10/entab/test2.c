#include <stdio.h>

void takeOut(char arr[], char temp[], int j);
void putIn(char temp[], char arr[], int j);

int main(){
	int c, j, length, space, isUpdating;
	char arr[100];
	char temp[8];

	arr[0] = '\0';
	temp[0] = '\0';
	space = 8;
	length = 0;
	isUpdating=1;
	j = 0;

	while((c = getchar()) != '\n'){
		arr[length] = c;
		++length;		
	}
	

	while(j <= length){
		takeOut(arr, temp, j);
		
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
		putIn(temp, arr, j);
		
		j+=8;
	}
	arr[length] = '\0'; 
	for(int i=0; i<length;i++){
		if(arr[i] == '\0'){}
		else{
			printf("%c", arr[i]);
		}	
	}
}

void takeOut(char arr[], char temp[], int j){
	int i = 0;
	while(i < 8){
		temp[i] = arr[j];
		i++;
		j++;
	}
}

void putIn(char temp[], char arr[], int j){
	int i = 0;
	while(i < 8){
		arr[j] = temp[i];
		i++;
		j++;
	}
}
