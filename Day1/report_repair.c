#include <stdio.h>

void part_one(int reportNumbers[], int counter){
	for(int i=0; i<counter; i++)
		for(int j=i+1; j<counter; j++)
			if(reportNumbers[i] + reportNumbers[j] == 2020)
				printf("Part 1: %d\n", reportNumbers[i] * reportNumbers[j]);
}

void part_two(int reportNumbers[], int counter){
	for(int i=0; i<counter; i++)
		for(int j=i+1; j<counter; j++)
			for(int k=j+1; k<counter; k++)
				if(reportNumbers[i] + reportNumbers[j] + reportNumbers[k] == 2020)
					printf("Part 2: %d\n", reportNumbers[i] * reportNumbers[j] * reportNumbers[k]);
}

int main(){
	FILE *fptr = fopen("input.txt","r");
	int reportNumbers[200];
	int counter = 0;
	while(!feof(fptr)){
		fscanf(fptr, "%d", &reportNumbers[counter]);
		counter ++;
	}
	fclose(fptr);
	part_one(reportNumbers, counter);
	part_two(reportNumbers, counter);
	return 0;
}
