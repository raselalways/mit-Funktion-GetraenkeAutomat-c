#include <stdio.h>
#include <stdlib.h>

int menue(void);
int getraenk_preis(int auswahl);
int bezahlung(int preis);
void rueckgeld_ausgeben(int rueckgeld);
void getraenk_ausgeben(void);

int main(void)
{
    int auswahl = 0;
    int preis = 0;
    int gezahlt = 0;
    int rueckgeld = 0;


    printf("\n-----------GetraenkeAutomat-----------------\n");

    while (auswahl != 5)
    {
        auswahl = menue();

        if (auswahl == 5)
        {
            printf("Vielen Dank\n");
            break;
        }

        preis = getraenk_preis(auswahl);

        if (preis == 0)
        {
            printf("\nFalsche Eingabe!!!\n");
            continue;
        }

        gezahlt = bezahlung(preis);
        rueckgeld = gezahlt - preis;

        if (rueckgeld > 0)
        {
            rueckgeld_ausgeben(rueckgeld);
        }

        getraenk_ausgeben();
        printf("\n-------------------------------------\n");
    }

    return 0;
}

int menue(void)
{
    int auswahl;

    printf("\n1. Cola\t\t120 Cent\n");
    printf("2. Fanta\t130 Cent\n");
    printf("3. Sprite\t140 Cent\n");
    printf("4. Wasser\t150 Cent\n");
    printf("5. Beenden!\n");
    printf("\nIhre Auswahl: ");
    scanf("%d", &auswahl);

    return auswahl;
}

int getraenk_preis(int auswahl)
{
    switch (auswahl)
    {
        case 1: return 120;
        case 2: return 130;
        case 3: return 140;
        case 4: return 150;
        default: return 0;
    }
}

int bezahlung(int preis)
{
    int gezahlt = 0;
    int einwurf;

    do
    {
        printf("Noch %d Cent fehlt!\n", preis - gezahlt);
        printf("Geld einwerfen: ");
        scanf("%d", &einwurf);
        gezahlt += einwurf;
    }
    while (gezahlt < preis);

    return gezahlt;
}

void rueckgeld_ausgeben(int rueckgeld)
{
    printf("\nRueckgeld: %d Cent\n", rueckgeld);

    printf("%d x 2 Euro\n", rueckgeld / 200);
    rueckgeld %= 200;

    printf("%d x 1 Euro\n", rueckgeld / 100);
    rueckgeld %= 100;

    printf("%d x 50 Cent\n", rueckgeld / 50);
    rueckgeld %= 50;

    printf("%d x 20 Cent\n", rueckgeld / 20);
    rueckgeld %= 20;

    printf("%d x 10 Cent\n", rueckgeld / 10);
    rueckgeld %= 10;

    printf("%d x 5 Cent\n", rueckgeld / 5);
    rueckgeld %= 5;
}

void getraenk_ausgeben(void)
{
    printf("\nNehmen Sie Ihr Getraenk!!! Vielen Dank\n");
}
