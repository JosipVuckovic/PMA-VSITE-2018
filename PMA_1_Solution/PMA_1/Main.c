#include <stdio.h>
#include <string.h>
#include <conio.h>
#define _USE_MATH_DEFINES
#include <math.h>



void main_menu(void);
void zadatak_1(void);
void do_you_want_more(void);
void zadatak_4(void);
void zadatak_2(void);
void zadatak_3(void);

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
	printf("*    2 - Zadatak 2 - Pregled zadovoljenih uvijeta, if uvijet     *\n");
	printf("*    3 - Zadatak 3 - Pregled u kojem kvadratu je tocka, if uvijet*\n");
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
		zadatak_2();
		break;
	case '3':
		zadatak_3();
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

	 void zadatak_2(void)
	{
		int bodovi_matematika;
		int bodovi_hrvatski;
		int bodovi_informatika;
		int bodovi_ukupno;
		system("cls");
		printf("**********************************************************************\n");
		printf("*                           Zadatak 2                                *\n");
		printf("* Unosimo bodove iz matematike, hravatskog, informatike i ukupne     *\n");
		printf("* bodove. Specifikacije bodovnih pragova su u tekstu vjezbe.         *\n");
		printf("* Kada korisnik unese bodove, program mu daje poruku o tome koja     *\n");
		printf("* opcija je zadovoljena, ukoliko nije, to se takoder javlja.         *\n");
		printf("**********************************************************************\n");
		printf("\n");
		printf("Unesite bodove iz matematike: ");
		scanf_s("%d", &bodovi_matematika);
		printf("\n");
		printf("Unesite bodove iz hrvatskog: ");
		scanf_s("%d", &bodovi_hrvatski);
		printf("\n");
		printf("Unesite bodove iz informatike: ");
		scanf_s("%d", &bodovi_informatika);
		printf("\n");
		printf("Unesite ukupan broj bodova: ");
		scanf_s("%d", &bodovi_ukupno);
		printf("\n");
		printf("**********************************************************************\n");
		printf("\n");
		if (bodovi_matematika>=60 && bodovi_hrvatski>= 50 && bodovi_informatika>= 50 && bodovi_ukupno>=180)
		{
			printf("Cestitamo! Zadovoljili ste opciju 1! \n");
			printf("\n");

		}
		else if (bodovi_matematika>=60 && bodovi_informatika >=50 && bodovi_ukupno>=140)
		{
			printf("Cestitamo! Zadovoljili ste opciju 2! \n");
			printf("\n");
		}
		else
		{
			printf("Nazalost, niste zadovoljli niti jednu opciju. :( \n");
			printf("\n");
		}
		do_you_want_more();
		
	}
	 void zadatak_3(void)
	 {
		 float koordinata_x;
		 float koordinata_y;

		 system("cls");
		 printf("**********************************************************************\n");
		 printf("*                           Zadatak 3                                *\n");
		 printf("* Korisnik unosi X i Y koordinatu neke tocke, a program javlja u     *\n");
		 printf("* kojem se kvadrntu tocka nalazi.                                    *\n");
		 printf("**********************************************************************\n");
		 printf("\n");
		 printf("Unesite X koordinatu: ");
		 scanf_s("%f", &koordinata_x);
		 printf("\n");
		 printf("Unesite Y koordinatu: ");
		 scanf_s("%f", &koordinata_y);
		 if (koordinata_x > 0 && koordinata_y > 0)
		 {
			 printf("\n Tocka se nalazi u prvom kvadrantu.\n");
			 printf("\n");
			 printf("         ^\n");
			 printf("         |y \n");
			 printf("         |\n");
			 printf("         | .T(%.2f,%.2f) \n",koordinata_x,koordinata_y);
			 printf("         | \n");
			 printf("---------|-----------> \n");
			 printf("         |        x \n");
			 printf("         |  \n");
			 printf("         |  \n");
			 printf("         |  \n");
			 printf("\n");
		 }
		 else if (koordinata_x< 0 && koordinata_y >0)
		 {
			 printf("\n Tocka se nalazi u drugom kvadrantu.\n");
			 printf("\n");
			 printf("               ^\n");
			 printf("               |y \n");
			 printf("               |\n");
			 printf("(%.2f,%.2f)T. |  \n", koordinata_x, koordinata_y);
			 printf("               | \n");
			 printf("      ---------|-----------> \n");
			 printf("               |        x \n");
			 printf("               |  \n");
			 printf("               |  \n");
			 printf("               |  \n");
			 printf("\n");
		 }
		 else if (koordinata_x <0 && koordinata_y <0)
		 {
			 printf("\n Tocka se nalazi u trecem kvadrantu.\n");
			 printf("\n");
			 printf("                ^\n");
			 printf("                |y \n");
			 printf("                |\n");
			 printf("                |  \n");
			 printf("                | \n");
			 printf("       ---------|-----------> \n");
			 printf("                |        x \n");
			 printf("(%.2f,%.2f)T. |  \n", koordinata_x, koordinata_y);
			 printf("                |  \n");
			 printf("                |  \n");
			 printf("\n");
		 }
		 else if (koordinata_x >0 && koordinata_y <0)
		 {
			 printf("\n Tocka se nalazi u trecem kvadrantu.\n");
			 printf("\n");
			 printf("         ^\n");
			 printf("         |y \n");
			 printf("         |\n");
			 printf("         | \n");
			 printf("         | \n");
			 printf("---------|-----------> \n");
			 printf("         |        x \n");
			 printf("         | .T(%.2f,%.2f)\n", koordinata_x, koordinata_y);
			 printf("         |  \n");
			 printf("         |  \n");
			 printf("\n");
		 }
		 else
		 {
			 printf("\n Tocka se nalazi u ishodistu.\n");
			 printf("\n");
			 printf("         ^\n");
			 printf("         |y \n");
			 printf("         |\n");
			 printf("         | \n");
			 printf("         | T(0,0) \n");
			 printf("---------|-----------> \n");
			 printf("         |        x \n");
			 printf("         | \n");
			 printf("         |  \n");
			 printf("         |  \n");
			 printf("\n");
		 }
		 do_you_want_more();
	 }