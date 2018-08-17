#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

void main_menu(void);
void do_you_want_more(void);
float zadatak_1();
void zadatak_2(void);
void zadatak_3(void);

int main()
{
	printf("******************************************************************\n");
	printf("*    PMA Vjeba 3 2017/2018    (nije upisano)    Josip Vuckovic   *\n");
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
	printf("*    1 - Zadatak 1 - Funkcija, pretvorba definirnih vauta        *\n");
	/*printf("*    2 - Zadatak 2 - Pregled znamenki brojeva                    *\n");
	printf("*    3 - Zadatak 3 - Pregled temperatura po godinama             *\n");*/
	/*printf("*    4 - Zadatak 4 - Opseg trokuta, kruga ili pravokutnika       *\n");*/
	/*printf("*    5 - Zadatak 5 -   *\n");*/
	printf("*    6 - Izlaz                                                   *\n");
	printf("******************************************************************\n");
	printf("         Vas izbor: ");
	scanf(" %c", &izbor);
	switch (izbor)
	{
	case '1':
		zadatak_1();
		break;
	/*case '2':
		zadatak_2();
	/*	break;*/
	/*case '3':
		zadatak_3();
		break;*/
		/*case '4':
		zadatak_4();
		break;
		case '5':
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
	scanf(" %c", &odabir);
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

float konverzija_valuta(float tecaj_valute, float kolicina_novca)
{
	return tecaj_valute * kolicina_novca;
}
float zadatak_1()
{
	float tecaj_USD=0;
	float tecaj_EUR=0;
	float tecaj_GBP=0;
	char izbor_valute=NULL;
	char *prijenos_podataka=NULL;
	char tecaj[14] = { "" };;
	FILE *tecajna_list;
	int i = 0;
	float iznos_hrk,iznos_devize;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                           Zadatak 1                                *\n");
	printf("* Program ima definirane 3 strane valute EUR(E), USD(D) te GBP(F),   *\n");
	printf("* tecaj prema HRK je spremljen u txt fajlu u direktoriju programa.   *\n");
	printf("* Zadatak ima funkciju koja prema izabranoj valuti preracunava stranu*\n");
	printf("* valutu u HRK. Program radi, dok se ne unese X ili x.               *\n");
	printf("**********************************************************************\n");
	printf("\n");
	tecajna_list=fopen("TecajnaLista.txt", "r");
	/* Dobra for za beskonacnu petlju :) */
	while (1)
	{
		prijenos_podataka = fgets(tecaj, 13, tecajna_list); 
		/*Komentirani dijelovi su zbog kontrole prebacivanja podataka*/
		/*printf("varijabla prijenos podataka: "); 
		printf(prijenos_podataka);
		printf("\n");*/
		strncpy(tecaj, prijenos_podataka+4,11);
		/*printf("\nvarijabla tecaj: ");
		printf(tecaj);
		printf("\n");*/
		switch (i)
		/*Svaki drugi nosi podatak, provjeriti jos tocno zasto je tako, dali je zbog novih redova?*/
		{
		case 0:
			tecaj_USD = atof(tecaj);
			break;
		case 1:
			tecaj_EUR = atof(tecaj);
			break;
		case 2:
			tecaj_GBP = atof(tecaj);
			break;
		default:
			break;
		}
		i++;
		if (i>2)
		{
			break;
		}
	}
	fclose(tecajna_list);
	if ((tecaj_EUR && tecaj_GBP && tecaj_USD) == 0)
	{
		printf("Tecajna lista nije uspjesno inicijalizirana!!!! Molimo obratite se IT podrsci!");
		printf("\n");
		do_you_want_more();
		return;
	}
	else
	{
		printf("Tecajna list uspjesno incijalizirana!\n");
	}
	printf("**********************************************************************\n");
	printf("                  Izaberite valutu za preracun\n");
	printf("                           Euro - E\n");
	printf("                       Americki dolar - D\n");
	printf("                       Britanska funta - F\n");
	printf("                            Izlaz - X\n");
	printf("**********************************************************************\n");
	while (izbor_valute != 'x')
	{
		printf("Unesite valutu i iznos, X za izlaz\n");
		printf("Unesite Valutu: ");
		scanf(" %c", &izbor_valute);
		
		switch (izbor_valute)
		{
		case 'E':
		case 'e':
			printf("Unesite iznos: ");
			scanf("%f", &iznos_devize);
			printf("Konvertirani iznos: %.2f Kn\n", konverzija_valuta(tecaj_EUR, iznos_devize));
			printf("\n");
			break;
		case 'F':
		case 'f':
			printf("Unesite iznos: ");
			scanf("%f", &iznos_devize);
			printf("Konvertirani iznos: %.2f Kn\n", konverzija_valuta(tecaj_GBP, iznos_devize));
			printf("\n");
			break;
		case 'D':
		case 'd':
			printf("Unesite iznos: ");
			scanf("%f", &iznos_devize);
			printf("Konvertirnani iznos: %.2f Kn\n", konverzija_valuta(tecaj_USD, iznos_devize));
			printf("\n");
			break;
		case'x':
		case'X':
			izbor_valute = 'x';
			break;
		default:
			printf("\n");
			printf("Nepodrzana valuta, ponovite unos!");
			printf("\n");
			break;
		}
	} 
	printf("\n");
	do_you_want_more();
}