
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <memory.h>
#include <time.h>
#include <ctype.h>



extern struct PlayInfo {
	char name[200];
	int Bomb;
	double nMove;
	double Score;
};

extern int playMineSweeper(int nBomb = 13);
extern void loadRanking(const char* filename);
extern void storeRanking(const char* filename);
extern void printRanking();
extern int addRanking(int total, double Move);


