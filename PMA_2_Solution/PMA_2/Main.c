#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


void main_menu(void);
void do_you_want_more(void);
void zadatak_1(void);

int main()
{
	printf("******************************************************************\n");
	printf("*    PMA Vjeba 2 2017/2018    (nije upisano)    Josip Vuckovic   *\n");
	printf("*    Ovaj program moze pokretati sve zadatke iz vjezbe te Vas    *\n");
	printf("*    molim da napravite izbor koji zadatak Vas zanima.           *\n");
	printf("******************************************************************\n");
	main_menu();

	return 0;
}

void main_menu(void)
{
	char izbor;
	printf("******************************************************************\n");
	printf("*    1 - Zadatak 1 - Random funkcija, bacanje novcica            *\n");
	printf("*    2 - Zadatak 2 - Pregled znamenki brojeva                    *\n");
	printf("*    3 - Zadatak 3 - Pregled temperatura po godinama             *\n");
	/*printf("*    4 - Zadatak 4 - Opseg trokuta, kruga ili pravokutnika       *\n");*/
	/*printf("*    5 - Zadatak 5 -   *\n");*/
	printf("*    6 - Izlaz                                                   *\n");
	printf("******************************************************************\n");
	printf("         Vas izbor: ");
	scanf_s(" %c", &izbor);
	switch (izbor)
	{
	case '1':
		zadatak_1();
		break;
	/*case '2':
		zadatak_2();
		break;
	case '3':
		zadatak_3();
		break;*/
	/*case '4':
		zadatak_4();
		break;*/
	/*case '5':
		Zad5Sub();
		break;*/
	case '6':
		printf("\nHvala na koristenju\n");
		printf("pritisnite bilo koju tipku za izlaz\n");
		getchar();
		break;
	default:
		system("cls");
		printf("\n\n **Nepoznat odabir, molim Vas ponovite unos**\n\n");
		main_menu();
		break;
	}

}

void do_you_want_more(void)
{
	char odabir;
	printf("****************************************************************\n");
	printf("                   *Zelite li drugi zadatak?                   *\n");
	printf("****************************************************************\n");
	printf("y/n: ");
	scanf_s(" %c", &odabir);
	switch (odabir)
	{
	case 'y':
	case 'Y':
		system("cls");
		main_menu();
		break;
	case 'n':
	case 'N':
		printf("\nHvala na korištenju\n");
		printf("pritisnite bilo koju tipku za izlaz\n");
		getchar();
		break;
	default:
		printf("\nNepoznat unos!\n");
		do_you_want_more();
		break;
	}
}

void zadatak_1(void)
{
	int i=0;
	int novcic[99];
	int tri_za_redom=0;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                           Zadatak 1                                *\n");
	printf("* Simuliramo bacanje novcica sve dok tri puta za redom ne dobijemo   *\n");
	printf("* istu stranu novcica, 0 je pismo, 1 je glava.                       *\n");
	printf("**********************************************************************\n");
	printf("\n");
	while (tri_za_redom!=1)
	{
		novcic[i] = rand() % 2;
		switch (novcic[i])
		{
		case 0:
			printf("P ");
			break;
		case 1:
			printf("G ");
			break;
		default:
			break;
		}
		if (i >= 2)
		{
			if ((novcic[i] == novcic[i - 1]) && (novcic[i] == novcic[i - 2]))
			{
				tri_za_redom = 1;
			}
		}
		i++;
	}
	printf("\n");
	printf("\n");
	printf("Tri ponavljanja su se dogodila nakon %d bacanja.", i);
	printf("\n");
	printf("\n");
	do_you_want_more();
	
}