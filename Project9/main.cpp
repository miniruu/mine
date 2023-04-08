#include "header.h"

int main()
{
	int total;
	printf(" <Mine Sweeper>\n");
	printf(" 매설할 총 지뢰의 개수 입력 :");
	scanf_s("%d", &total);
	loadRanking("thetop.txt");
	int rank=playMineSweeper(total);
	storeRanking("thetop.txt");
	printRanking();
}