#include "stdafx.h"
#include "cstring"
#define N 6
#define EBAS 0x7FFFFFFF
void Dijkstra();
int dizi[N][N] = { { -1, 7, 4, -1, 2, -1 },
{ 7, -1, 3, 2, -1, 6 }, { 4, 3, -1, 8, 1, -1 },
{ -1, 2, 8, -1, 10, 3 }, { 2, -1, 1, 10, -1, -1 },
{ -1, 6, -1, 3, -1, -1 } };
int maliyet[N];
char ROTA[N][N] = { NULL };
void _tmain(int argc, _TCHAR* argv[])
{
	int i;
	Dijkstra();

	puts("\nKomsuluk Matrisi\n");
	for (i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%5d", dizi[i][j]);
		printf("\n\n\n");
	}

	puts("\nMaliyetler\n");
	for (i = 0; i < N; ++i)
		printf("maliyet[%d]=%d\n", i, maliyet[i]);

	puts("\nRotalar\n");
	for (i = 0; i < N; ++i)
		printf("ROTA[%d]=%s\n", i, ROTA[i]);
	getchar();
}

void Dijkstra()
{
	char *ptr, ELEALINDI[N] = { 0 };
	int i, j, ead, ek;
	maliyet[0] = 0;
	for (i = 1; i < N; ++i)
		maliyet[i] = EBAS;
	ead = 0;

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		if (!ELEALINDI[j])
		if (dizi[ead][j] != -1)
		if (maliyet[j]>dizi[ead][j] + maliyet[ead])
		{
			maliyet[j] = dizi[ead][j] + maliyet[ead];
			strcpy(ROTA[j], ROTA[ead]);
			ptr = ROTA[j];
			while (*ptr != NULL)
				++ptr;
			*ptr = 'A' + ead;
		}
		ek = EBAS;
		for (j = 1; j < N; ++j)
		if (!ELEALINDI[j])
		if (maliyet[j] < ek)
		{
			ek = maliyet[j];
			ead = j;
		}
		
		ELEALINDI[ead] = 1;
	}
}