#include <stdio.h>

int main(int argc, char const *argv[])
{
	//punto 1
	char x,*p;

	//punto 2
	char y,*puntero;

	//punto 3
	x='x';

	//punto 4
	p=&x;

	//punto 5
	printf("%c\n",*p);

	//punto 6
	p=p+1;
	//punto 7
	printf("%c\n",*p);
	//punto 8
	p=p+2;
	//punto 9
	printf("%c\n",*p);
	//punto 10
	y='y';
	//punto 11
	puntero=&y;
	//punto 12
	printf("%c\n",*puntero );
	return 0;
}