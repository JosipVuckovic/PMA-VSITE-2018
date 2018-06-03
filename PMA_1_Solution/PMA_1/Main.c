#include <stdio.h>
#include <string.h>
#include <conio.h>
#define _USE_MATH_DEFINES
#include <math.h>



void main_menu(void);
void zadatak_1(void);
void do_you_want_more(void);
void zadatak_4(void);

int main()
{
	printf("******************************************************************\n");
	printf("*    PMA Vjeba 1 2017/2018    (nije upisano)    Josip Vuckovic   *\n");
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
	printf("*    1 - Zadatak 1 - Izracun potrosnje pretplate za mobitel      *\n");
	printf("*    2 - Zadatak 2 -                                             *\n");
	printf("*    3 - Zadatak 3 -                                             *\n");
	printf("*    4 - Zadatak 4 - Opseg trokuta, kruga ili pravokutnika       *\n");
	/*printf("*    5 - Zadatak 5 -   *\n");*/
	printf("*    6 - Izlaz                                                   *\n");
	printf("******************************************************************\n");
	printf("         Vas izbor: ");
		scanf_s(" %c",&izbor);
	switch (izbor)
	{
	
		
	case '1':
		zadatak_1();
			break;
	case '2':
		/*Zad2Sub();*/
		break;
	case '3':
		/*Zad3Sub();*/
		break;
	case '4':
		zadatak_4();
		break;
	case '5':
		/*Zad5Sub();*/
			break;
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
	printf("*Zelite li drugi zadatak?*\n");
	printf("****************************************************************\n");
	printf("y/n: ");
	scanf_s(" %c", &odabir);
	switch (odabir)
	{
	
	case 'y':
		system("cls");
		main_menu();
		break;
	case 'Y':
		system("cls");
		main_menu();
		break;
	case 'n':
		printf("\nHvala na korištenju\n");
		printf("pritisnite bilo koju tipku za izlaz\n");
		getchar();
		break;
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
		
		float pdv;
		float iznos_pretplate;
		float minuta_preplata;
		float sms_pretplata;
		float cijena_poziva;
		float cijena_sms;
		float potroseno_sati_razgovora = 0;
		float potroseno_minuta_razgovora = 0;
		float poslanih_sms = 0;
		float potroseno_razgovora_ukupno;
		float za_doplatu_razgovora;
		float za_doplatu_sms;
		float za_platiti_ukupno;
		system("cls");
		printf("**********************************************************************\n");
		printf("*							Zadatak 1                                *\n");
		printf("* Unosimo iznos poreza, cijenu paketa bez poreza te koliko minuta i  *\n");
		printf("* poruka ja ukljuceno u paket mobilne preplate, nakon toga unosimo   *\n");
		printf("* koliko sati i minuta smo pricali, najmanja obracunska jedinica je  *\n");
		printf("* minuta. Program nam izracunava koliko moramo platiti za uslugu.    *\n");
		printf("**********************************************************************\n");
		printf("\n");
		printf("Podaci o pretplati: \n");
		printf("**********************************************************************\n");
		printf("PDV: ");
			
			scanf_s("%f", &pdv);
		printf("\nIznos pretplate bez PDV-a: ");
			
			scanf_s("%f", &iznos_pretplate);
		printf("\nUnesite kolicinu minuta u pretplati: ");
			
			scanf_s("%f", &minuta_preplata);
		printf("\nUnesite kolicina poruka u pretplati: ");
			
			scanf_s("%f", &sms_pretplata);
		printf("\nUnesite cijenu poziva po minuti, bez PDV-a: ");
			
			scanf_s("%f", &cijena_poziva);
		printf("\nUnesite cijenu sms-a: ");
			
			scanf_s("%f", &cijena_sms);
		printf("\n");
		printf("**********************************************************************\n");
		printf("\n");
		printf("Podaci o potrosnji: \n");
		printf("**********************************************************************\n");
		printf("\nSati razgovora: ");
			
			scanf_s("%f", &potroseno_sati_razgovora);
		printf("\nMinuta razgovora: ");
			
			scanf_s("%f", &potroseno_minuta_razgovora);
		printf("\nPoslano sms-ova ");
			
			scanf_s("%f", &poslanih_sms);
		printf("**********************************************************************\n");
		
		potroseno_razgovora_ukupno = potroseno_minuta_razgovora + (potroseno_sati_razgovora * 60);
		
		switch (minuta_preplata>=potroseno_razgovora_ukupno)
		{
		case 0:
			za_doplatu_razgovora = potroseno_razgovora_ukupno - minuta_preplata;
			break;
		case 1:
			za_doplatu_razgovora = 0;
		default:
			break;
		}
		switch (sms_pretplata>=poslanih_sms)
		{
		case 0:
			za_doplatu_sms = poslanih_sms - sms_pretplata;
			break;
		case 1:
			za_doplatu_sms = 0;
		default:
			break;
		}

		za_platiti_ukupno = ((iznos_pretplate + (za_doplatu_razgovora*cijena_poziva)) + (za_doplatu_sms*cijena_sms))*(1.0f + (pdv / 100.0f));

		printf("\n Ukupno treba platiti: %.2f kn.\n", za_platiti_ukupno);
		printf("**********************************************************************\n");
		printf("\n");
		do_you_want_more();
		

	}

	void zadatak_4(void)
	{
		char izbor;
		float stranica_a, stranica_b, stranica_c;
		system("cls");
		printf("**********************************************************************\n");
		printf("*                     Zadatak 4                                      *\n");
		printf("* Zadatak racuna opseg pravokutnika, trokuta ili kruga. Korisnik sam *\n");
		printf("* odlucuje koji opseg ce se racunati.                                *\n");
		printf("*                    1 - opseg kruga                                 *\n");
		printf("*                    2 - opseg trokuta                               *\n");
		printf("*                    3 - opseg pravokutnika                          *\n");
		printf("**********************************************************************\n");
		printf("                     Vas odabir: ");
		scanf_s(" %c", &izbor);
		printf("\n");
		switch (izbor)
		{
		case '1':
			printf("Izabrali ste opseg kruga.\n");
			printf("formula: O = 2 * r * π\n\n");
			printf("Unesite radijus: ");
			scanf_s("%f", &stranica_a);
			printf("\n");
			printf("Opseg kruga iznosi: %.2f", 2*stranica_a*M_PI);
			printf("\n\n");
			
			do_you_want_more();
			break;
		case '2':
			printf("Izabrali ste opseg trokuta.\n");
			printf("formula: O = a + b + c\n\n");
			printf("Unesite stranicu a: ");
			scanf_s("%f", &stranica_a);
			printf("\n");
			printf("Unesite stranicu b: ");
			scanf_s("%f", &stranica_b);
			printf("\n");
			printf("Unesite stranicu c: ");
			scanf_s("%f", &stranica_c);
			printf("\n");
			printf("Opseg trokuta iznosi: %.2f", stranica_a+stranica_b+stranica_c);
			printf("\n\n");

			do_you_want_more();
			break;
		case '3':
			printf("Izabrali ste opseg pravokutnika.\n");
			printf("formula: O = 2 * (a + b)\n\n");
			printf("Unesite stranicu a: ");
			scanf_s("%f", &stranica_a);
			printf("\n");
			printf("Unesite stranicu b: ");
			scanf_s("%f", &stranica_b);
			printf("\n");
			printf("Opseg pravokutnika iznosi: %.2f", 2*(stranica_a + stranica_b));
			printf("\n\n");

			do_you_want_more();
			break;
		default:
			printf("\n Nepoznat izbor!\n");
			zadatak_4();
			break;
		}
	
	}

	