#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct _student {
	char ime[20];
	char prezime[20];
	int bodovi;
}student;
int numOfRows(const char *nameFile) {
	int brojac = 0;
	FILE* fp = fopen(nameFile, "r");
	if (!fp) {
		printf("greska pri otvaranju");
		return -1;
	}
	char buffer[50];
	while (fgets(buffer, sizeof(buffer), fp) != NULL) {
		if (buffer[0] != '\n') {
			brojac++;
		}
	}
	fclose(fp);
	return brojac;
}
void printStudents(const char *nameFile, student*studenti,int numStudent) {
	FILE* fp = fopen(nameFile, "r");
	if (fp == NULL) {
		printf("greška");
		return;
	}
	for (int i = 0; i < numStudent; i++) {
		fscanf(fp, "%15s %15s %d", studenti[i].ime, studenti[i].prezime, &studenti[i].bodovi);
	}
	fclose(fp);
	for (int i = 0; i < numStudent; i++) {
		double relPoints = (double)studenti[i].bodovi / MAX * 100;	
		printf("%-15s %-15s %d %.2f\n", studenti[i].ime, studenti[i].prezime, studenti[i].bodovi, relPoints);
	}
}
int main() {
	const char* nameFile = "studenti.txt";
	int numOfStudents = numOfRows(nameFile);
	if (numOfStudents <= 0) {
		printf("Datoteka je prazna ili je nepostojeća\n");
		return 1;
	}
	student* studenti = (student*)malloc(numOfStudents * sizeof(student));
	if (studenti == NULL) {
		printf("Greska u alokaciji memorije\n");
		return 1;
	}
	printf("Broj studenata koji su u datoteci je %d", numOfStudents);
	printStudents("studenti.txt", studenti, numOfStudents);
	free(studenti);
	return 0;
	
}

