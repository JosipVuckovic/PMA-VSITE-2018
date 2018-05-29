#include <stdio.h>
#include <string.h>
#include <conio.h>


void main_menu(void);
void zadatak_1(void);
void do_you_want_more(void);

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

	printf("******************************************************************\n");
	printf("*    1 - Zadatak 1 - Izracun potrosnje pretplate za mobitel      *\n");
	printf("*    2 - Zadatak 2 -                                             *\n");
	printf("*    3 - Zadatak 3 -                                             *\n");
	printf("*    4 - Zadatak 4 -                                             *\n");
	/*printf("*    5 - Zadatak 5 -   *\n");*/
	printf("*    6 - Izlaz                                                    *\n");
	printf("*******************************************************************\n");
	printf("         Vas izbor: ");
	char izbor;
	scanf_s("%c",&izbor);
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
		/*Zad4Sub();*/
		break;
	case '5':
		/*Zad5Sub();*/
			break;
	case '6':
		printf("\nHvala na koristenju\n");
		printf("pritisnite bilo koju tipku za izlaz\n");
		getchar();
	default:
		system("cls");
		printf("\n\n **Nepoznat odabir, molim Vas ponovite unos**\n\n");
		main_menu();

	} 
	
	}
void do_you_want_more(void)
{
	

	printf("****************************************************************\n");
	printf("*Zelite li drugi zadatak?*\n");
	printf("****************************************************************\n");
	printf("y/n:\n");
	char odabir;
	scanf_s("%c", &odabir);
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
		
		
	}
}
	void zadatak_1(void)
	{
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
			float pdv;
			scanf_s("%f", &pdv);
		printf("\nIznos pretplate bez PDV-a: ");
			float iznos_pretplate;
			scanf_s("%f", &iznos_pretplate);
		printf("\nUnesite kolicinu minuta u pretplati: ");
			float minuta_preplata;
			scanf_s("%f", &minuta_preplata);
		printf("\nUnesite kolicina poruka u pretplati: ");
			float sms_pretplata;
			scanf_s("%f", &sms_pretplata);
		printf("\nUnesite cijenu poziva po minuti, bez PDV-a: ");
			float cijena_poziva;
			scanf_s("%f", &cijena_poziva);
		printf("\nUnesite cijenu sms-a: ");
			float cijena_sms;
			scanf_s("%f", &cijena_sms);
		printf("\n");
		printf("**********************************************************************\n");
		printf("\n");
		printf("Podaci o potrosnji: \n");
		printf("**********************************************************************\n");
		printf("\nSati razgovora: ");
			float potroseno_sati_razgovora=0;
			scanf_s("%f", &potroseno_sati_razgovora);
		printf("\nMinuta razgovora: ");
			float potroseno_minuta_razgovora=0;
			scanf_s("%f", &potroseno_minuta_razgovora);
		printf("\nPoslano sms-ova ");
			float poslanih_sms=0;
			scanf_s("%f", &poslanih_sms);
		printf("**********************************************************************\n");
		float potroseno_razgovora_ukupno;
		potroseno_razgovora_ukupno = potroseno_minuta_razgovora + (potroseno_sati_razgovora * 60);
		float za_doplatu_razgovora;
		float za_doplatu_sms;
		float za_platiti_ukupno;
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

	
	