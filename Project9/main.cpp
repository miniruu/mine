#include "header.h"

int main()
{
	int total;
	printf(" <Mine Sweeper>\n");
	printf(" �ż��� �� ������ ���� �Է� :");
	scanf_s("%d", &total);
	loadRanking("thetop.txt");
	int rank=playMineSweeper(total);
	storeRanking("thetop.txt");
	printRanking();
}