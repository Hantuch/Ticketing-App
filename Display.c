#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"


char marker[4];

void menudisp(int pilihan, int tipe)
{	
	switch(pilihan)
		{
			case 1  : marker[0] = '>'; marker[1] = ' '; marker[2] = ' '; break;
			case 2  : marker[0] = ' '; marker[1] = '>'; marker[2] = ' '; break;
			case 3  : marker[0] = ' '; marker[1] = ' '; marker[2] = '>'; break;
			default : marker[0] = ' '; marker[1] = ' '; marker[2] = ' '; break;
		}
		
	if(tipe == 0)
	{	
	
		system("cls");
		printf("  ==============================================\n");
		printf("  |                 Buy Ticket!                |\n");
		printf("  ==============================================\n");
		printf("\n\n");
		printf("	%c See Available Film\n", 		marker[0]);
		printf("	%c Help				 \n", 		marker[1]);
		printf("	%c Exit\n", marker[2]);
	}
	else if(tipe == 1)
	{
		system("cls");
		printf("  ==============================================\n");
		printf("  |                 Buy Ticket!                |\n");
		printf("  ==============================================\n");
		printf("\n\n");
				
		printf(" Program ini membantu anda dalam pembelian tiket \n"
			   " secara mandiri,langkah yang akan dilalui adalah \n"
			   " sebagai berikut :\n\n");
		printf(" Pilih Film -> Pilih jadwal -> Pilih Kursi \n"
			   " -> Detil Pembayaran\n\n");
		printf("	%c See Available Film\n", 		marker[0]);
		printf("	%c Help				 \n", 		marker[1]);
		printf("	%c Exit\n", marker[2]);	
	}
}

void listdisp(int pilihan, char judul[][40], char jadwal[][4][10])
{	
	switch(pilihan)
		{
			case 1  : marker[0] = '>'; marker[1] = ' '; marker[2] = ' '; marker[3] = ' '; break;
			case 2  : marker[0] = ' '; marker[1] = '>'; marker[2] = ' '; marker[3] = ' '; break;
			case 3  : marker[0] = ' '; marker[1] = ' '; marker[2] = '>'; marker[3] = ' '; break;
			case 4  : marker[0] = ' '; marker[1] = ' '; marker[2] = ' '; marker[3] = '>'; break;
			default : marker[0] = ' '; marker[1] = ' '; marker[2] = ' '; marker[3] = ' '; break;
		}	
	
	system("cls");
	printf("  ==============================================\n");
	printf("  |                 Buy Ticket!                |\n");
	printf("  ==============================================\n");
	printf("\n  Film Hari Ini :\n\n");
	printf("  %c %s\n", marker[0], judul[0]);
	printf("	[%s] [%s] [%s] [%s]\n", jadwal[0][0], jadwal[0][1], jadwal[0][2], jadwal[0][3]);
	printf("  %c %s\n", marker[1], judul[1]);
	printf("	[%s] [%s] [%s] [%s]\n", jadwal[1][0], jadwal[1][1], jadwal[1][2], jadwal[1][3]);
	printf("  %c %s\n", marker[2], judul[2]);
	printf("	[%s] [%s] [%s] [%s]\n", jadwal[2][0], jadwal[2][1], jadwal[2][2], jadwal[2][3]);
	printf("  %c %s\n", marker[3], judul[3]);
	printf("	[%s] [%s] [%s] [%s]\n", jadwal[3][0], jadwal[3][1], jadwal[3][2], jadwal[3][3]);
}

void jadwaldisp(int pilihan,int pilihan2, char judul[][40], char jadwal[][4][10], char sinopsis[][2][50])
{
	int marker2[4], i;
	switch(pilihan2)
		{
			case 1  : marker2[0] = 10; marker2[1] = 15; marker2[2] = 15; marker2[3] = 15; break;
			case 2  : marker2[0] = 15; marker2[1] = 10; marker2[2] = 15; marker2[3] = 15; break;
			case 3  : marker2[0] = 15; marker2[1] = 15; marker2[2] = 10; marker2[3] = 15; break;
			case 4  : marker2[0] = 15; marker2[1] = 15; marker2[2] = 15; marker2[3] = 10; break;			
			default : marker2[0] = 15; marker2[1] = 15; marker2[2] = 15; marker2[3] = 15; break;
		}
	
	system("cls");
	SetColor(15);
	printf("  ==============================================\n");
	printf("  |                 Buy Ticket!                |\n");
	printf("  ==============================================\n");

	printf("\n  %s\n\n",judul[pilihan-1]);
	
	for(i=0;i<2;i++)
	{
		printf("  %s\n", sinopsis[pilihan-1][i]);
	}

	printf("\n  Silakan Pilih Jadwal yang Diinginkan :\n\n");
	printf("    ");
	printcolor("[",marker2[0]);printcolor(jadwal[pilihan-1][0],marker2[0]);printcolor("] ",marker2[0]);
	printcolor("[",marker2[1]);printcolor(jadwal[pilihan-1][1],marker2[1]);printcolor("] ",marker2[1]);
	printcolor("[",marker2[2]);printcolor(jadwal[pilihan-1][2],marker2[2]);printcolor("] ",marker2[2]);
	printcolor("[",marker2[3]);printcolor(jadwal[pilihan-1][3],marker2[3]);printcolor("] ",marker2[3]);	
}

void ticketdisp(int pilihan,int pilihan2,int pilihan3, char judul[][40], char jadwal[][4][10], char sinopsis[][2][50])
{
	int marker2[4], i;
	switch(pilihan2)
		{
			case 1  : marker2[0] = 10; marker2[1] = 15; marker2[2] = 15; marker2[3] = 15; break;
			case 2  : marker2[0] = 15; marker2[1] = 10; marker2[2] = 15; marker2[3] = 15; break;
			case 3  : marker2[0] = 15; marker2[1] = 15; marker2[2] = 10; marker2[3] = 15; break;
			case 4  : marker2[0] = 15; marker2[1] = 15; marker2[2] = 15; marker2[3] = 10; break;			
			default : marker2[0] = 15; marker2[1] = 15; marker2[2] = 15; marker2[3] = 15; break;
		}
	
	system("cls");
	SetColor(15);
	printf("  ==============================================\n");
	printf("  |                 Buy Ticket!                |\n");
	printf("  ==============================================\n");

	printf("\n  %s\n\n",judul[pilihan-1]);
	
	for(i=0;i<2;i++)
	{
		printf("  %s\n", sinopsis[pilihan-1][i]);
	}

	printf("\n  Silakan Pilih Jadwal yang Diinginkan :\n\n");
	printf("    ");
	printcolor("[",marker2[0]);printcolor(jadwal[pilihan-1][0],marker2[0]);printcolor("] ",marker2[0]);
	printcolor("[",marker2[1]);printcolor(jadwal[pilihan-1][1],marker2[1]);printcolor("] ",marker2[1]);
	printcolor("[",marker2[2]);printcolor(jadwal[pilihan-1][2],marker2[2]);printcolor("] ",marker2[2]);
	printcolor("[",marker2[3]);printcolor(jadwal[pilihan-1][3],marker2[3]);printcolor("] ",marker2[3]);	
	
	printf("\n\n");
	printf("  Berapa Jumlah Tiket yang Anda Inginkan?\n");
	printf("\n                     << %d >>\n", pilihan3);
	
}

void seatingdisp(int theater)
{
	switch(theater)
	{
		case 0 :
			system("cls");
			printf("  =====================================================================================================\n"
				   "  |       ___________________________________________________________________________________         |\n" 
				   "  |      |_______________________________________LAYAR_______________________________________|        |\n"
				   "  |                                                                                                   |\n"
				   "  |                                                                                                   |\n"
				   "  |                                                                                                   |\n"
				   "  |                   |-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|                   |\n"
				   "  |                   | G 1 | G 2 | G 3 | G 4 | G 5 | G 6 | G 7 | G 8 | G 9 | G10 |                   |\n"
				   "  |                   |-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|                   |\n"
				   "  |                   | F 1 | F 2 | F 3 | F 4 | F 5 | F 6 | F 7 | F 8 | F 9 | F10 |                   |\n"
				   "  |                   |-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|                   |\n"
				   "  |                   | E 1 | E 2 | E 3 | E 4 | E 5 | E 6 | E 7 | E 8 | E 9 | E10 |                   |\n"
				   "  |                   |-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|                   |\n"
				   "  |                   | D 1 | D 2 | D 3 | D 4 | D 5 | D 6 | D 7 | D 8 | D 9 | D10 |                   |\n"
				   "  |                   |-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|                   |\n"
				   "  |                   | C 1 | C 2 | C 3 | C 4 | C 5 | C 6 | C 7 | C 8 | C 9 | C10 |                   |\n"
				   "  |                   |-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|                   |\n"
				   "  |                   | B 1 | B 2 | B 3 | B 4 | B 5 | B 6 | B 7 | B 8 | B 9 | B10 |                   |\n"
				   "  |       |-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|       |\n"
				   "  |       | A 1 | A 2 | A 3 | A 4 | A 5 | A 6 | A 7 | A 8 | A 9 | A10 | A11 | A12 | A13 | A14 |       |\n"
				   "  |       |-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|       |\n"
				   "  |                                                                                                   |\n"
				   "  =====================================================================================================");
			return;		
			break;
			
		case 1 :
			system("cls");
			printf("=====================================================================================================\n"
				   "|       ____________________________________________________________________________________        |\n"
				   "|      |_______________________________________LAYAR________________________________________|       |\n"
    	           "|                                                                                                   |\n"
        	       "|                                                                                                   |\n"
            	   "|                                                                                                   |\n"
               	   "|       |-----|-----|-----|-----|-----|-----|     |-----|-----|-----|-----|-----|-----|-----|       |\n"
	               "|       | G 1 | G 2 | G 3 | G 4 | G 5 | G 6 |     | G 7 | G 8 | G 9 | G10 | G11 | G12 | G13 |	    |\n"
    	           "|       |-----|-----|-----|-----|-----|-----|     |-----|-----|-----|-----|-----|-----|-----|	    |\n"
        	       "|       | F 1 | F 2 | F 3 | F 4 | F 5 | F 6 |     | F 7 | F 8 | F 9 | F10 | F11 | F12 | F13 |	    |\n"
            	   "|       |-----|-----|-----|-----|-----|-----|     |-----|-----|-----|-----|-----|-----|-----|	    |\n"
	               "|       | E 1 | E 2 | E 3 | E 4 | E 5 | E 6 |     | E 7 | E 8 | E 9 | E10 | E11 | E12 | E13 |	    |\n"
    	           "|       |-----|-----|-----|-----|-----|-----|     |-----|-----|-----|-----|-----|-----|-----|	    |\n"
        	       "|       | D 1 | D 2 | D 3 | D 4 | D 5 | D 6 |     | D 7 | D 8 | D 9 | D10 | D11 | D12 | D13 |	    |\n"
            	   "|       |-----|-----|-----|-----|-----|-----|     |-----|-----|-----|-----|-----|-----|-----|	    |\n"
	               "|       | C 1 | C 2 | C 3 | C 4 | C 5 | C 6 |     | C 7 | C 8 | C 9 | C10 | C11 | C12 | C13 |       |\n"
    	           "|       |-----|-----|-----|-----|-----|-----|     |-----|-----|-----|-----|-----|-----|-----| 	    |\n"
        	       "|       | B 1 | B 2 | B 3 | B 4 | B 5 | B 6 |     | B 7 | B 8 | B 9 | B10 | B11 | B12 | B13 |       |\n"
	           	   "|       |-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|       |\n"
    	           "|    	| A 1 | A 2 | A 3 | A 4 | A 5 | A 6 | A 7 | A 8 | A 9 | A10 | A11 | A12 | A13 | A14 |       |\n"
        	       "|    	|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----| 	    |\n"
            	   "|                                                                                                   |\n"
	               "=====================================================================================================");
	        return;
			break;	
	}
}

void summarydisp(int pilihan, char judul[][40], char jadwal[][4][10], char seat[][3], int filmpil, int jadwalpil, int jumlahtiket)
{
	int i;
	switch(pilihan)
		{
			case 1  : marker[0] = '>'; marker[1] = ' '; break;
			case 2  : marker[0] = ' '; marker[1] = '>'; break;
			default : marker[0] = ' '; marker[1] = ' '; break;
		}
	system("cls");
	printf("  ==============================================\n");
	printf("  |                 Buy Ticket!                |\n");
	printf("  ==============================================\n");
	printf("\n");
	printf("  Berikut Rincian Tiket Anda : \n\n");
	printf("  Judul Film  : %s\n\n", judul[filmpil-1]);
	printf("  Jadwal      : %s\n\n", jadwal[filmpil-1][jadwalpil-1]);
	printf("  Seating     :");

	for(i=0;i<jumlahtiket;i++)
	{
		printf(" %s", seat[i]);
	}
	printf("\n\n");
	printf("  Total Pembarayan : Rp %d", jumlahtiket*price());
	printf("\n\n");
	printf("           %c [Lanjut]   %c [Keluar]", marker[0], marker[1]);
	printf("\n\n");
}


