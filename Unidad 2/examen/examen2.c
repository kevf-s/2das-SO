#include <stdio.h>

int main(int argc, char const *argv[])
{
	char arrayChar[5];
	int i;
	int letra=97;
	for (i= 0; i < 5; ++i)
	{
		arrayChar[i]=letra;
		letra++;

	}
	//paso 3
	char *punteroChar;
	punteroChar=&arrayChar[0];
	//paso 4
	char *punteroCharDos;
	punteroCharDos=&arrayChar[0];
	//paso 5
	printf("%c\n",arrayChar[0]);
	//paso 6
	printf("%c\n",*punteroChar);
	//paso 7
	printf("%c\n",*punteroCharDos);
	//paso 8
	printf("%c\n",arrayChar[4]);
	//paso 9
	printf("%c\n",*(punteroChar+4));
	//paso 10
	printf("%c\n",*(punteroCharDos+4));
	//paso 11
	for (i = 0; i < 5; ++i)
	{
		printf("%c", *(punteroCharDos+i));
	}
	printf("\n");
	//paso 12
	for (i = 0; i < 5; ++i)
	{
		printf("%c", *(punteroCharDos+i)); 
	}
	printf("\n");

	return 0;
}