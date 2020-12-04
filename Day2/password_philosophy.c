#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int part_one(int min, int max, char *word, char letter){
	int count = 0;
	for(int i=0; word[i]; i++){
		if(word[i] == letter){
			count++;
		}
	}
	if(min <= count && count <= max)
		return 1;
	else
		return 0;
}

int part_two(int min, int max, char *word, char letter){
	if((word[min-1] == letter) ^ (word[max-1] == letter)){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	FILE *fptr = fopen("input.txt","r");
	char passwords[2000][32];
	int counter, validPasswords1, validPasswords2;

	while(fgets(passwords[counter],32,fptr)){
		passwords[counter][strlen(passwords[counter])-1] = '\0';

		int dash, colon, space;
		for(int i=0; i<32; i++){
			switch(passwords[counter][i]){
				case '-':
					dash = i;
					break;
				case ':':
					colon = i;
					break;
				case ' ':
					space = i;
					break;
			}
		}
		char min[6] = "";
		for(int i=0; i<dash; i++){
			strncat(min,&passwords[counter][i],1);
		}
		char max[6] = "";
		for(int i=dash+1; i<space; i++){
			strncat(max,&passwords[counter][i],1);
		}
		char word[32] = "";
		for(int i=colon+2; i<sizeof(passwords[counter])/sizeof(passwords[counter][0]) - 1; i++){
			strncat(word,&passwords[counter][i],1);
		}
		char letter = passwords[counter][colon-1];
		validPasswords1 += part_one(atoi(min), atoi(max), word, letter);
		validPasswords2 += part_two(atoi(min), atoi(max), word, letter);
		counter++;
	}
	fclose(fptr);
	printf("Part 1: %d\n", validPasswords1);
	printf("Part 2: %d\n", validPasswords2);
	return 0;
}
