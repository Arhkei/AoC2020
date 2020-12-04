#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int part_one(int min, int max, char ch, char *password){
	int count = 0;

	for(int i=0; password[i]; i++)
		if(password[i] == ch)
			count++;

	if(min <= count && count <= max)
		return 1;
	else
		return 0;
}

int part_two(int min, int max, char ch, char *password){
	if((password[min-1] == ch) ^ (password[max-1] == ch))
		return 1;
	else
		return 0;
}

int main(){
	FILE *fptr = fopen("input.txt","r");
	char password[100], ch;
	int min, max, validPasswords, validPasswords2;

	while(fscanf(fptr,"%d-%d %c: %s",&min,&max,&ch,password)!= EOF){
		validPasswords += part_one(min, max, ch, password);
		validPasswords2 += part_two(min, max, ch, password);
	}

	fclose(fptr);
	printf("Part 1: %d\n", validPasswords);
	printf("Part 2: %d\n", validPasswords2);
	return 0;
}
