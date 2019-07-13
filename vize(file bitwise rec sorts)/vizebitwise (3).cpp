#include <stdio.h>
#include <conio.h>

int main(){

	int gun, ay, yil;
	int data;
// ^ aynı değilse 1 verir aynıysa 0
	printf("Tarihi Giriniz \n");
	printf("Gun : "); scanf("%d",&gun); //   [0000 0000  0000 0000  0000 0000  000*0 0100]
	printf("Ay  : "); scanf("%d",&ay);  //   [0000 0000  0000 0000  0000 0000  0000* 0011]
	printf("Yil : "); scanf("%d",&yil); //   [0000 0000  0000 0000  0000 0000  *0111 0100]
	yil=yil-1900;

	data = 0;
	data = data | gun; data = data<<4;  //   [0000 0000  0000 0000  0000 0000  0100 0000]
	data = data | ay;  data = data<<8;  //   [0000 0000  0000 0000  0100 0011  0000 0000]
	data = data | yil;                  //   [0000 0000  0000 0000  0100 0011  0111 0100]

	printf("\n\n\n");

	int gunX, ayX, yilX;
	int okunan;

	okunan = data;

	yilX = 256-1; // 2^8-1 -> [..00  1111 1111]
	yilX = yilX & okunan; okunan = okunan>>8;
	ayX  = 16-1; // 2^4-1 ->  [..00  0000 1111]
	ayX  = ayX & okunan; okunan = okunan>>4;
	gunX = 32-1; // 2^5-1 ->  [..00  0001 1111]
	gunX = gunX & okunan;
	//gunX = okunan;

	yilX = yilX + 1900;

	printf("Tarihi Giriniz \n");
	printf("Gun : %d   Ay : %d   Yil : %d\n", gunX, ayX, yilX);

	getch();

	unsigned char X = 45, Y = 56;

	printf("X : %d   Y : %d\n", X, Y);
	X = X ^ Y;
    Y = Y ^ X;
    X = X ^ Y;
	printf("X : %d   Y : %d\n", X, Y);

	return (0);
}
