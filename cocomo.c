#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	const double EAF = /* PCAP  * LEXP * MODP * TOOL */ 0.7 * 0.95 * 0.82 * 0.82;
	int option;
	int size_project;
	double work;
	double time;
		
	printf("enter the size of the project(KSLOC): ");
	scanf("%d", &size_project);
	if(size_project < 50){
		printf("normal mode\n");
		option = 1;
	} else if(size_project >= 50 && size_project < 500){
		printf("intermediate mode\n");
		option = 2;
	} else if(size_project >= 500){
		printf("built-in mode\n");
		option = 3;
	}
	
		
	switch(option){
		case 1:
			work = 3.2 * EAF * pow(size_project, 1.05);
			time = 2.5 * pow(work, 0.38);
			break;
		case 2:
			work = 3.0 * EAF * pow(size_project, 1.12);
			time = 2.5 * pow(work, 0.35);
			break;
		case 3:
			work = 2.8 * EAF * pow(size_project, 1.2);
			time = 2.5 * pow(work, 0.32);
			break;
	}
	
	printf("work = %f\ntime = %f", round(work), round(time));
	getchar();
	return 0;
}