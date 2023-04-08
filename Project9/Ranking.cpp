#define _CRT_SECURE_NO_WARNINGS

#include "header.h"

#define NUM_MVP 10
static PlayInfo MVP[NUM_MVP];
static int nMVP = NUM_MVP;



static void initRanking() {
	PlayInfo noname = { "C++", 1, 0 };
	for (int i = 0; i < nMVP; i++)
	{
		MVP[i] = noname;
	}
}
void loadRanking(const char* filename) {
	FILE* fp=NULL;
	fopen_s(&fp, filename, "r");
	if (fp == NULL)
		initRanking();
	else {
		for (int i = 0; i < nMVP; i++)
			fscanf_s(fp, "%s%lf", &MVP[i].name, &MVP[i].Score);
		fclose(fp);
	}
}
void printRanking() {
	for (int i = 0; i < nMVP; i++)
		printf(" [%2d위]  %-16s %5.1lf\n", i + 1,
			MVP[i].name, MVP[i].Score);
}
void storeRanking(const char* filename) {
	FILE* fp=NULL;
	fopen_s(&fp, filename, "w");
	if (fp == NULL) return;
	for (int i = 0; i < nMVP; i++)
	{
		fprintf(fp, "%-16s %-5.1lf\n", MVP[i].name, MVP[i].Score);
	}
	fclose(fp);
}
int addRanking(int Bomb, double Score) {
	
	double result = Score;
		int pos = nMVP - 1;
		for (; pos > 0; pos--) {
			if (result<= (MVP[pos-1].Bomb*15) / MVP[pos - 1].nMove)break;
			MVP[pos] = MVP[pos - 1];
		}
		MVP[pos].Bomb = Bomb;
		MVP[pos].nMove = result / (MVP[pos].Bomb * 15);
		MVP[pos].Score = Score;
		printf("%d위입니다. 이름을 입력하세요: ", pos + 1);
		scanf_s("%s", MVP[pos].name);
	
	return 0;
}