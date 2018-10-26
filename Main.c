#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define TRUE 1

//Hanif Rachmadani - 1606870774
//Ahmad Aufar Husaini - 1606904730

//Ticketing App ver 3 - 17/10/18

//Changelog 
//(24/10/2018)
//-Added Date-based Pricing Function
//(25/10/2018)
//-Added Sinopsis Functionality
//(26/10/2018)
//-Improved Sinopsis Function
//-Improved number of tickets input + error handling


void mainmenu(), listFilm(), listJadwal(), ticket(), readFilm(), readJadwal(), readSinopsis(), seating(), summary();
int price();	//Harga tergantung hari -- Hari Kerja 40K - Hari Libur 60K

int i, chinput, j; //Counter & Misc.
int filmpil, jadwalpil, jumlahtiket =2; //Kode Film, Jadwal, Jumlah Tiket yang dipilih

int main()
{
	char Film[4][40], Jadwal[4][4][10], Sinopsis[4][2][50]; 
	
	SetColor(15);
	readFilm(Film);
	readJadwal(Jadwal);
	readSinopsis(Sinopsis);
	
	printf("%s", Sinopsis[2][1]);

	while(TRUE)
	{
	
		mainmenu();
		
		listFilm(Film,Jadwal);
		listJadwal(filmpil,Film,Jadwal,Sinopsis);
		ticket(filmpil,jadwalpil,Film,Jadwal,Sinopsis);
		
		char seat[jumlahtiket][3];
		
		seating(seat, jumlahtiket);
		
		summary(seat,Film,Jadwal,filmpil,jadwalpil,jumlahtiket);
	}
		return 0;	
}

void mainmenu()
{
	int pilihan = 1, tipe = 0;
	menudisp(pilihan, tipe);	
	while(TRUE)
	{
		chinput = getch();
		switch(chinput)
		{
			case 13 :
				switch(pilihan)
				{
					case 1 : 
						return ; break;
					case 2 : 
						tipe = 1;
						menudisp(pilihan, tipe);
						break;
					case 3 : 
						exit(0); break;
				}
				break;
			case 80 :
				pilihan++;
				if(pilihan == 4){ pilihan = 1;}
				menudisp(pilihan, tipe);
				break;
			case 72 :
				pilihan--;
				if(pilihan == 0){ pilihan = 3;}
				menudisp(pilihan, tipe);
				break;
			default : 
				menudisp(pilihan, tipe);
				fflush(stdin);
				break;
		}
	}
}

void listFilm(char judul[4][40] ,char jadwal[][4][10])
{
	int pilihan = 1;
	
	listdisp(pilihan,judul,jadwal);
	
	while((chinput = getch()) != 27)
	{
		switch(chinput)
		{
			case 13 :
				switch(pilihan)
				{
					case 1 :
						filmpil = pilihan;
						return;
						break;
					case 2 :
						filmpil = pilihan;
						return;
						break;
					case 3 :
						filmpil = pilihan;
						return;
						break;
					case 4 :
						filmpil = pilihan;
						return;
						break;
				}
				break;
			case 80 :
				pilihan++;
				if(pilihan == 5){ pilihan = 1;}
				listdisp(pilihan,judul,jadwal);
				break;
			case 72 :
				pilihan--;
				if(pilihan == 0){ pilihan = 4;}
				listdisp(pilihan,judul,jadwal);
				break;
			default :
				listdisp(pilihan,judul,jadwal);
				fflush(stdin);
				break;
		}
	}
}

void listJadwal(int filmpil ,char judul[][40] ,char jadwal[][4][10], char sinopsis[][2][50])
{
	int pilhrzntl = 1, tipe = 0;
	
	jadwaldisp(filmpil,pilhrzntl,judul,jadwal,sinopsis);
	
	while((chinput = getch()) != 27)
	{
		switch(chinput)
		{
			case 13 :
				switch(pilhrzntl)
				{
					case 1 :
						jadwalpil = pilhrzntl;
						return;
						break;
					case 2 :
						jadwalpil = pilhrzntl;
						return;
						break;
					case 3 :
						jadwalpil = pilhrzntl;;
						return;
						break;
					case 4 :
						jadwalpil = pilhrzntl;
						return;
						break;
				}
				break;
	
			case 77 :
				pilhrzntl++;
				if(pilhrzntl == 5){ pilhrzntl = 1;}
				jadwaldisp(filmpil,pilhrzntl,judul,jadwal,sinopsis);
				break;
			case 75 :
				pilhrzntl--;
				if(pilhrzntl == 0){ pilhrzntl = 4;}
				jadwaldisp(filmpil,pilhrzntl,judul,jadwal,sinopsis);
				break;
			default :
				jadwaldisp(filmpil,pilhrzntl,judul,jadwal,sinopsis);
				fflush(stdin);
				break;
		}
	}
}

void ticket(int filmpil ,int jadwalpil,char judul[][40] ,char jadwal[][4][10], char sinopsis[][2][50])
{
	int pilhrzntl = 1;
	ticketdisp(filmpil,jadwalpil,pilhrzntl,judul,jadwal,sinopsis);
	
	while((chinput = getch()) != 27)
	{
		switch(chinput)
		{
			case 13 :
				jumlahtiket = pilhrzntl;
				return;
				break;
	
			case 77 :
				pilhrzntl++;
				ticketdisp(filmpil,jadwalpil,pilhrzntl,judul,jadwal,sinopsis);
				break;
			case 75 :
				pilhrzntl--;
				if(pilhrzntl == 0){ pilhrzntl = 1;}
				ticketdisp(filmpil,jadwalpil,pilhrzntl,judul,jadwal,sinopsis);
				break;
			default :
				ticketdisp(filmpil,jadwalpil,pilhrzntl,judul,jadwal,sinopsis);
				fflush(stdin);
				break;
		}
	}
}

void seating(char input[][3], int jumlahtiket)
{	
	int theater;
	srand(time(NULL));
	theater = rand() % 2;
	seatingdisp(theater);
	
	for(i=0;i<jumlahtiket;i++)
	{
		seatingdisp(theater);
		printf("\n\n  Silakan Pilih Kursi ke %d : ", i+1);
		scanf(" %[^\n]s", &input[i]);
	}
}

int price()
{
	time_t rawtime;
	struct tm *info;

	char day[2];

	time( &rawtime );

	info = localtime( &rawtime );
	
	strftime(day,2,"%w", info);	
   
	switch(day[0])
	{
		case '0' : case '6' :
			return 60000;
			break;
		case '1' : case '2' : case '3' : case '4' : case '5' :
			return 40000;
			break; 
	}
}

void summary(char seat[][3], char judul[][40] ,char jadwal[][4][10] ,int filmpil ,int jadwalpil ,int jumlahtiket)
{
	int pilihan = 1;
	
	summarydisp(pilihan, judul,jadwal,seat,filmpil,jadwalpil,jumlahtiket);
	
	while((chinput = getch()) != 27)
	{
		switch(chinput)
		{
			case 13 :
				switch(pilihan)
				{
					case 1 : 
						fflush(stdin);
						fflush(stdout);
						return ; break;
					case 2 : 
						exit(0); break;
				}
				break;
			case 77 :
				pilihan++;
				if(pilihan == 3){ pilihan = 1;}
				summarydisp(pilihan, judul,jadwal,seat,filmpil,jadwalpil,jumlahtiket);
				break;
			case 75 :
				pilihan--;
				if(pilihan == 0){ pilihan = 2;}
				summarydisp(pilihan, judul,jadwal,seat,filmpil,jadwalpil,jumlahtiket);
				break;
			default : 
				summarydisp(pilihan, judul,jadwal,seat,filmpil,jadwalpil,jumlahtiket);
				fflush(stdin);
				break;
		}
	}
}

void readFilm(char input[][40])
{
	int i= 0;
	FILE *ptrfile;
	
	ptrfile = fopen("ListFilm.txt","r");

	while(!feof(ptrfile))
	{
		if(fgets(input[i], 40, ptrfile) != NULL)
		{
			input[i][strcspn(input[i], "\n")] = 0;
			i++;
		}
	}	
	fclose(ptrfile);
}

void readJadwal(char input[][4][10])
{
	i= 0;
	FILE *ptrfile;
	char temp[4][40];
	
	ptrfile = fopen("Jadwal.txt","r");

	while(!feof(ptrfile))
	{
		if(fgets(temp[i], 40, ptrfile) != NULL)
		{
			temp[i][strcspn(temp[i], "\n")] = 0;
			i++;
		}
	}	
	fclose(ptrfile);
	
	for(i=0;i<4;i++)
	{
		j = 0;
		sscanf(temp[i], "%s %s %s %s", &input[i][j], &input[i][j+1], &input[i][j+2], &input[i][j+3]);
	}
}

void readSinopsis(char input[][2][50])
{
	char sinopsis[8][50];
	int i= 0, j=0, k;
	FILE *ptrfile;
	
	ptrfile = fopen("Sinopsis.txt","r");

	while(!feof(ptrfile))
	{
		if(fgets(sinopsis[i], 50, ptrfile) != NULL)
		{
			sinopsis[i][strcspn(sinopsis[i], "\n")] = 0;
			i++;
		}
	}	

	fclose(ptrfile);
	
	i = 0;
	for(j=0;j<4;j++)
	{
		k = 0;
		while(k<2)
		{
			strcpy(input[j][k], sinopsis[i]);
			i++;
			k++;
		}
	}
}
