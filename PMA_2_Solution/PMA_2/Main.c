#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>


void main_menu(void);
void do_you_want_more(void);
void zadatak_1(void);
int zadatak_2();
void zadatak_3(void);



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
	case '2':
		zadatak_2();
		break;
	case '3':
		zadatak_3();
		break;
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
	printf("* istu stranu novcica, 1 je pismo, 0 je glava.                       *\n");
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
int provjera_zad_2(int broj)
{
	int znamenka;
	int zbroj=0;
	while (broj != 0)
	{
		znamenka = broj % 10;
		broj = broj / 10;
		if (znamenka % 2 != 0)
		{
			zbroj = 0;
			break;
		}
		else
		{
			zbroj = zbroj + (znamenka * znamenka);
		}
	}
	return zbroj;
}
int zadatak_2()
{
	int donja_granica;
	int gornja_granica;
	int zbroj;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                           Zadatak 2                                *\n");
	printf("* Unosimo granice brojeva te izmedu tih granica (granice ukljucene)  *\n");
	printf("* gledamo koji brojevi su sastavljeni samo od parnih znamenki, kod   *\n");
	printf("* brojeva koji su sastavljeni samo od parnih znamenki ispisujemo     *\n");
	printf("* zbroj kvadrata znamenki, kod onih koji nisu sastavljeni samo od    *\n");
	printf("* parnih znamenki samo ispisujemo poruku kako znamenke nisu parne.   *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite donju granicu: ");
	scanf_s("%d", &donja_granica);
	printf("\n");
	printf("Unesite gornju granicu: ");
	scanf_s("%d", &gornja_granica);
	printf("\n");
	printf("**********************************************************************\n");
	printf("\n");
	for (donja_granica; donja_granica <= gornja_granica; donja_granica++)
	{
		zbroj = provjera_zad_2(donja_granica);
		if (zbroj > 0)
		{
			printf("Broj: %d ima sve parne znamenke, suma kvadrata: %d\n", donja_granica, zbroj);
		}
		else
		{
			printf("Broj: %d nema sve parne znamenke!\n", donja_granica);
		}
	}
	printf("\n");
	do_you_want_more();
	return 0;
}
struct Temp_po_godini
{
	int redni_broj_godine;
	float najniza_temperatura;
	float najvisa_temperatura;
};

void zadatak_3(void)
{
	struct Temp_po_godini *Temperature;
	int broj_godina;
	int i;
	float unesena_temperatura;
	float unesena_temperatura_2;
	int b;
	system("cls");
	printf("**********************************************************************\n");
	printf("*                           Zadatak 3                                *\n");
	printf("* Traziti od korisnika broj godina u nekom mjernom razdoblju,        *\n");
	printf("* upisati dvije temperature za svaku godinu, manju tretirati kao     *\n");
	printf("* najmanju izmjerenu a vecu kao najvisu izmjerenu.                   *\n");
	printf("* Izracunati prosjek najnizih i najvisih temperatura.                *\n");
	printf("**********************************************************************\n");
	printf("\n");
	printf("Unesite za koliko godina unosite temperature: ");
	scanf_s("%d", &broj_godina);
	printf("\n");
	Temperature=malloc(broj_godina+1 ,sizeof(Temperature));
	b = broj_godina + 1;

	for (i=1; i <= broj_godina; i++)
	{
		Temperature->redni_broj_godine = i;
		printf("Unosite temperaturu za %d mjernu godinu.\n", i);
		printf("Unesite prvu temperaturu: ");
		scanf_s("%f", &unesena_temperatura);
		printf("\n");
		printf("Unesite drugu temperaturu: ");
		scanf_s("%f", &unesena_temperatura_2);
		printf("\n");
		if (unesena_temperatura < unesena_temperatura_2)
		{
			Temperature[i].najniza_temperatura = unesena_temperatura;
			Temperature[i].najvisa_temperatura = unesena_temperatura_2;
		}
		else
		{
			Temperature[i].najniza_temperatura = unesena_temperatura_2;
			Temperature[i].najvisa_temperatura = unesena_temperatura;
		}
		Temperature[b].najniza_temperatura += Temperature[i].najniza_temperatura;
		Temperature[b].najvisa_temperatura += Temperature[i].najvisa_temperatura;
	}
	for ( i = 0; i <= broj_godina ; i++)
	{
		
	}
	printf("\n");
	printf("Prosjek najnizih temperatura je: %.2f\n", Temperature[b].najniza_temperatura / broj_godina);
	printf("Prosjek najvisih temperatura je: %.2f\n", Temperature[b].najvisa_temperatura / broj_godina);
	printf("\n");
	do_you_want_more();
	free(Temperature);
}