/*Mein Ziel ist zuerst ein funktionsfähiges Schiffe versenken Programm zu zu erstellen,
bei dem es möglich ist mit zwei Spielern, mit individuell platzierten Schiffen oder zufällig
platzierten Schiffen zu spielen. Dies mache ich aus dem Grund, da ich dann 1. sehe ob der
Code funktioniert und 2. um die funktionierenden Teile zu nehmen und zu ergänzen.
Z.B: das erstellte Feld durch algorithmisiertes zu ersetzen.  Der zweite Spieler, sowie die Auswahl der
Schusskoordinaten werden natürlich auch wegfallen


Das mit der individuellen Spielfeldauswahl funktioniert soweit, das
zufällig generierte Feld jedoch nicht, da es nur ein Schiff platziert.
Ich habe einiges versucht, finde den Fehler jedoch nicht.
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char Spielfeld1[100];
    char Spielfeld2[100];
    char Spielfeld1x[100];
    char Spielfeld2x[100];
    char Schiffe;
    int x, y, Laenge;
    int Zaehler1 = 0;
    int Zaehler2 = 0;
    int Schiffanzahl[4] = { 1,2,3,4 };
    char Richtung;
    int n = 0;
    int n1 = 0;
    int n2 = 0;
    int z = 0;
    int r = rand() % 100 + 1;
    int k = 0;
    char Auswahl;
    char random_Richtung[10];
    int random_y[400];
    int random_x[400];
    char random_Schiff[10] = { 'F','S','S','K','K','K','B','B','B','B' };
    int Fehler[5] = { 0,0,0,0,0 };
    int Felder[5] = { 0,0,0,0,0 };
    int Ueberpruefung[50];
    int Summe[10];
    for (int i = 0; i < 10; i++) {
        Summe[i] = 0;
    }
    for (int i = 0; i < 50; i++) {
        Ueberpruefung[i] = 0;
    }
    srand(time(NULL));





    printf("Wollen Sie die Schiffe selber platzieren? (ja,nein) (alternativ werden die Schiffe zufällig plaziert)\n");
    scanf("%c", &Auswahl);



    if (Auswahl == 'j')
    {



        /*Schiffplazierung*/



        for (int i = 0; i < 100; i++)
        {
            Spielfeld1[i] = 'w';
        }



        for (int i = 10; i > 0; i--) {

            system("@cls||clear");

            if (k == 1) {
                printf("Es stehen leider keine weiteren Schiff dieser Art zur verfuegung, bitte waehlen Sie eine andere Art.\n\n");
            }
            k = 0;



            if (i < 10)
            {
                printf("\nEs sind noch %d Schiffe zu vergeben\n", i);
            }

            for (int i = 0; i < 100; i++)
            {
                if (i % 10 == 0)
                {
                    printf("\n");
                }
                printf("[%c]", Spielfeld1[i]);

            }

            printf("\n\nSpieler 1, Welches Schiff wollen Sie plazieren?\n");
            printf("-->\nFlugzeugtraeger(1 Stueck  5 Felder Kuerzel: F)\nSchlachtSchiffe(2 Stueck  4 Felder Kuerzel: S)\n");
            printf("Kreuzer        (3 Stueck  3 Felder Kuerzel: K)\nSchnellboote   (4 Stueck  2 Felder Kuerzel: B)\n");

            scanf("%s", &Schiffe);


            /*SchiffsLaenge*/
            switch (Schiffe)
            {


            case 'F':
                if (Schiffanzahl[0] != 0)
                {
                    Laenge = 5;
                    Schiffanzahl[0]--;
                }
                else
                {

                    k = 1;
                    i++;

                }
                break;

            case 'S':
                if (Schiffanzahl[1] != 0)
                {
                    Laenge = 4;
                    Schiffanzahl[1]--;
                }
                else
                {

                    k = 1;
                    i++;

                }
                break;

            case 'K':
                if (Schiffanzahl[2] != 0)
                {
                    Laenge = 3;
                    Schiffanzahl[2]--;
                }
                else
                {

                    k = 1;
                    i++;

                }
                break;

            case 'B':
                if (Schiffanzahl[3] != 0)
                {
                    Laenge = 2;
                    Schiffanzahl[3]--;
                }
                else
                {

                    k = 1;
                    i++;

                }
                break;

            default:
                break;

            }



            if (k == 1) {


            }
            else {

                printf("\n Auf welchen Koordinaten wünschen Sie dieses Schiff zu plazieren?(x ; y)\n");
                scanf("%d %d", &x, &y);

                printf("In welche Richtung soll dieses Schiff plaziert werden?(rechts(r), links(l), oben(o), unten(u))\n");

                /*ich weiß leider nicht warum, aber das Programm funktioniert nur mit 2 scanf's*/
                scanf("%c", &Richtung);
                scanf("%c", &Richtung);
            }

            switch (Richtung)
            {


            case 'r':
                for (int i = 0; i < Laenge; ++i) {
                    Spielfeld1[10 * y + x + i] = 's';
                }
                break;


            case 'l':
                for (int i = 0; i < Laenge; i++) {
                    Spielfeld1[10 * y + x - i] = 's';
                }
                break;


            case 'o':
                for (int i = 0; i < Laenge; i++) {
                    Spielfeld1[10 * y + x - i * 10] = 's';
                }
                break;

            case 'u':
                for (int i = 0; i < Laenge; i++) {
                    Spielfeld1[10 * y + x + i * 10] = 's';
                }
                break;


            default:
                break;
            }





        }



        system("@cls||clear");



        /*Spieler 2*/




        for (int i = 0; i < 100; i++)
        {
            Spielfeld2[i] = 'w';
        }




        for (int i = 10; i > 0; i--) {

            system("@cls||clear");

            if (k == 1) {
                printf("Es stehen leider keine weiteren Schiff dieser Art zur verfuegung, bitte waehlen Sie eine andere Art.\n\n");
            }
            k = 0;

            if (i < 10)
            {
                printf("\nEs sind noch %d Schiffe zu vergeben\n", i);
            }

            for (int i = 0; i < 100; i++)
            {
                if (i % 10 == 0)
                {
                    printf("\n");
                }
                printf("[%c]", Spielfeld2[i]);

            }

            printf("\n\nSpieler 2, Welches Schiff wollen Sie plazieren?\n");
            printf("-->\nFlugzeugtraeger(1 Stueck  5 Felder Kuerzel: F)\nSchlachtSchiffe(2 Stueck  4 Felder Kuerzel: S)\n");
            printf("Kreuzer        (3 Stueck  3 Felder Kuerzel: K)\nSchnellboote   (4 Stueck  2 Felder Kuerzel: B)\n");

            scanf("%s", &Schiffe);



            /*SchiffsLaenge*/
            switch (Schiffe)
            {


            case 'F':
                if (Schiffanzahl[0] != 0)
                {
                    Laenge = 5;
                    Schiffanzahl[0]--;
                }
                else
                {
                    printf("\n\nEs stehen leider keine weiteren Schiff dieser Art zur verfügung, bitte waehlen Sie eine andere Art.\n\n");
                    k = 1;
                    i++;

                }
                break;

            case 'S':
                if (Schiffanzahl[1] != 0)
                {
                    Laenge = 4;
                    Schiffanzahl[1]--;
                }
                else
                {
                    printf("Es stehen leider keine weiteren Schiff dieser Art zur verfügung, bitte waehlen Sie eine andere Art.");
                    k = 1;
                    i++;

                }
                break;

            case 'K':
                if (Schiffanzahl[2] != 0)
                {
                    Laenge = 3;
                    Schiffanzahl[2]--;
                }
                else
                {
                    printf("Es stehen leider keine weiteren Schiff dieser Art zur verfügung, bitte waehlen Sie eine andere Art.");
                    k = 1;
                    i++;

                }
                break;

            case 'B':
                if (Schiffanzahl[3] != 0)
                {
                    Laenge = 2;
                    Schiffanzahl[3]--;
                }
                else
                {
                    printf("Es stehen leider keine weiteren Schiff dieser Art zur verfügung, bitte waehlen Sie eine andere Art.");
                    k = 1;
                    i++;

                }
                break;

            default:
                break;

            }



            if (k == 1) {


            }
            else {

                printf("\n Auf welchen Koordinaten wünschen Sie dieses Schiff zu plazieren?(x ; y)\n");
                scanf("%d %d", &x, &y);

                printf("In welche Richtung soll dieses Schiff plaziert werden?(rechts(r), links(l), oben(o), unten(u))\n");

                /*ich weiß leider nicht warum, aber das Programm funktioniert nur mit 2 scanf's*/
                scanf("%c", &Richtung);
                scanf("%c", &Richtung);
            }
            switch (Richtung)
            {


            case 'r':
                for (int i = 0; i < Laenge; ++i) {
                    Spielfeld2[10 * y + x + i] = 's';
                }
                break;


            case 'l':
                for (int i = 0; i < Laenge; i++) {
                    Spielfeld2[10 * y + x - i] = 's';
                }
                break;


            case 'o':
                for (int i = 0; i < Laenge; i++) {
                    Spielfeld2[10 * y + x - i * 10] = 's';
                }
                break;

            case 'u':
                for (int i = 0; i < Laenge; i++) {
                    Spielfeld2[10 * y + x + i * 10] = 's';
                }
                break;


            default:
                break;
            }





        }




    }

    else                                    /*random generiertes Spielfeld*/
    {






        /*Schiffplazierung*/


        for (int u = 0; u < 10; u++) {
            random_Richtung[u] = "rlou"[rand() % 4];
        }

        for (int u = 0; u < 400; u++) {
            random_x[u] = rand() % 10;
        }
        for (int u = 0; u < 400; u++) {
            random_y[u] = rand() % 10;
        }











        for (int u = 0; u < 10; u++)
        {
            switch (random_Schiff[u])
            {


            case 'F':
                Laenge = 5;
                break;

            case 'S':
                Laenge = 4;
                break;

            case 'K':
                Laenge = 3;
                break;

            case 'B':
                Laenge = 2;
                break;

            default:
                break;

            }



            switch (random_Richtung[u])
            {


            case 'r':


                while (n1 != 1) {



                    for (int e = 0; e < Laenge; e++) {

                        Felder[e] = 10 * random_y[u] + random_x[u] + e;

                        if (Spielfeld1[10 * random_y[u + z] + random_x[u + z] + e] == 's')
                        {
                            Fehler[e] = 1;



                        }
                    }
                    for (int e = 0; e < Laenge - 1; e++) {

                        if ((Felder[e] == 9 && Felder[e + 1] == 10) || Felder[e] == 19 && Felder[e + 1] == 20 || Felder[e] == 29 && Felder[e + 1] == 30 || Felder[e] == 39 && Felder[e + 1] == 40 || Felder[e] == 49 && Felder[e + 1] == 50 || Felder[e] == 59 && Felder[e + 1] == 60 || Felder[e] == 69 && Felder[e + 1] == 70 || Felder[e] == 79 && Felder[e + 1] == 80 || Felder[e] == 89 && Felder[e + 1] == 90 || Felder[e] > 99 || Felder[e + 1] > 99) {

                            n2 = 1;

                        }


                    }



                    if (Fehler[0] + Fehler[1] + Fehler[2] + Fehler[3] + Fehler[4] != 0 || n2 == 1)
                    {
                        z = z + 30;



                    }

                    else {

                        for (int i = 0; i < Laenge; i++) {
                            Spielfeld1[10 * random_y[u] + random_x[u] + i] = 's';
                        }
                        n1 = 1;
                    }
                }
                /*{
                for(int i=0; i<Laenge; ++i){
                    Spielfeld1[10*random_y[u]+random_x[u]+i]='s';
                }
                else{
                    for(int e=30;e<500; e++){
                            if(Spielfeld1[10*random_y[u+e]+random_x[u+e]+i]='s')

                    }
                }
                }
                */
                /* for(int i=0; i<100; i++)
                        {
                            if(i%10==0)
                            {
                                printf("\n");
                            }
                            printf("[%c]",Spielfeld1[i]);

                        }
                */
                break;








            case 'l':
                /*for(int i=0; i<Laenge; i++){
                Spielfeld1[10*random_y[u]+random_x[u]-i]='s';
                }
                */

                while (n1 != 1) {



                    for (int e = 0; e < Laenge; e++) {

                        Felder[e] = 10 * random_y[u] + random_x[u] - e;

                        if (Spielfeld1[10 * random_y[u + z] + random_x[u + z] - e] == 's')
                        {
                            Fehler[e] = 1;



                        }
                    }
                    for (int e = 0; e < Laenge - 1; e++) {

                        if ((Felder[e + 1] == 9 && Felder[e] == 10) || Felder[e + 1] == 19 && Felder[e] == 20 || Felder[e + 1] == 29 && Felder[e] == 30 || Felder[e + 1] == 39 && Felder[e] == 40 || Felder[e + 1] == 49 && Felder[e] == 50 || Felder[e + 1] == 59 && Felder[e] == 60 || Felder[e + 1] == 69 && Felder[e] == 70 || Felder[e + 1] == 79 && Felder[e] == 80 || Felder[e + 1] == 89 && Felder[e] == 90 || Felder[e] < 0 || Felder[e + 1] < 0) {

                            n2 = 1;

                        }


                    }



                    if (Fehler[0] + Fehler[1] + Fehler[2] + Fehler[3] + Fehler[4] != 0 || n2 == 1)
                    {
                        z = z + 30;



                    }

                    else {

                        for (int i = 0; i < Laenge; i++) {
                            Spielfeld1[10 * random_y[u] + random_x[u] - i] = 's';
                        }
                        n1 = 1;
                    }
                }



                /*   for(int i=0; i<100; i++)
                      {
                          if(i%10==0)
                          {
                              printf("\n");
                          }
                          printf("[%c]",Spielfeld1[i]);

                      }
                      */

                break;


            case 'o':

                while (n1 != 1) {



                    for (int e = 0; e < Laenge; e++) {
                        if (Spielfeld1[10 * random_y[u + z] + random_x[u + z] - e * 10] == 's')
                        {
                            Fehler[e] = 1;
                            Felder[e] = 10 * random_y[u] + random_x[u] - e * 10;


                        }
                    }




                    if (Fehler[0] + Fehler[1] + Fehler[2] + Fehler[3] + Fehler[4] != 0 || Felder[0] < 0 || Felder[1] < 0 || Felder[2] < 0 || Felder[3] < 0 || Felder[4] < 0)
                    {
                        z = z + 30;

                    }

                    else {

                        for (int i = 0; i < Laenge; i++) {
                            Spielfeld1[10 * random_y[u] + random_x[u] - i * 10] = 's';
                        }
                        n1 = 1;
                    }
                }




                /*for(int i=0; i<Laenge; i++){
                Spielfeld1[10*random_y[u]+random_x[u]-i*10]='s';
                }
                break;
            */
            /*
             for(int i=0; i<100; i++)
                    {
                        if(i%10==0)
                        {
                            printf("\n");
                        }
                        printf("[%c]",Spielfeld1[i]);

                    }
                    */

                break;
            case 'u':

                while (n1 != 1) {



                    for (int e = 0; e < Laenge; e++) {
                        if (Spielfeld1[10 * random_y[u + z] + random_x[u + z] + e * 10] == 's')
                        {
                            Fehler[e] = 1;
                            Felder[e] = 10 * random_y[u] + random_x[u] + e * 10;


                        }
                    }




                    if (Fehler[0] + Fehler[1] + Fehler[2] + Fehler[3] + Fehler[4] != 0 || Felder[0] > 99 || Felder[1] > 99 || Felder[2] > 99 || Felder[3] > 99 || Felder[4] > 99)
                    {
                        z = z + 30;

                    }

                    else {

                        for (int i = 0; i < Laenge; i++) {
                            Spielfeld1[10 * random_y[u] + random_x[u] + i * 10] = 's';
                        }
                        n1 = 1;
                    }
                }


                /*
                     for(int i=0; i<100; i++)
                        {
                            if(i%10==0)
                            {
                                printf("\n");
                            }
                            printf("[%c]",Spielfeld1[i]);

                        }

                */
                break;
                /*for(int i=0; i<Laenge; i++){
                Spielfeld1[10*random_y[u]+random_x[u]+i*10]='s';
                }
                break;
            */

            default:
                break;
            }




        }








        /*Spieler 2*/
        /* !wird durch den Code von Spieler 1 ersetzt, sobald dieser funktioniert!*/
        /*voerst zu ignorieren, da es der selbe Code, wie beim individuellen Spielfeld ist*/




        for (int i = 0; i < 100; i++)
        {
            Spielfeld2[i] = 'w';
        }




        for (int i = 10; i > 0; i--) {



            if (i < 10)
            {
                printf("\nEs sind noch %d Schiffe zu vergeben\n", i);
            }

            for (int i = 0; i < 100; i++)
            {
                if (i % 10 == 0)
                {
                    printf("\n");
                }
                printf("[%c]", Spielfeld2[i]);

            }

            printf("\n\nSpieler 2, Welches Schiff wollen Sie plazieren?\n");
            printf("-->\nFlugzeugtraeger(1 Stueck  5 Felder Kuerzel: F)\nSchlachtSchiffe(2 Stueck  4 Felder Kuerzel: S)\n");
            printf("Kreuzer        (3 Stueck  3 Felder Kuerzel: K)\nSchnellboote   (4 Stueck  2 Felder Kuerzel: B)\n");

            scanf("%s", &Schiffe);

            printf("\n Auf welchen Koordinaten wuenschen Sie dieses Schiff zu plazieren?(x ; y)\n");
            scanf("%d %d", &x, &y);

            printf("In welche Richtung soll dieses Schiff plaziert werden?(rechts(r), links(l), oben(o), unten(u))\n");


            scanf("%c", &Richtung);
            scanf("%c", &Richtung);


            switch (Schiffe)
            {


            case 'F':
                Laenge = 5;
                break;

            case 'S':
                Laenge = 4;
                break;

            case 'K':
                Laenge = 3;
                break;

            case 'B':
                Laenge = 2;
                break;

            default:
                break;

            }




            switch (Richtung)
            {


            case 'r':
                for (int i = 0; i < Laenge; ++i) {
                    Spielfeld2[10 * y + x + i] = 's';
                }
                break;


            case 'l':
                for (int i = 0; i < Laenge; i++) {
                    Spielfeld2[10 * y + x - i] = 's';
                }
                break;


            case 'o':
                for (int i = 0; i < Laenge; i++) {
                    Spielfeld2[10 * y + x - i * 10] = 's';
                }
                break;

            case 'u':
                for (int i = 0; i < Laenge; i++) {
                    Spielfeld2[10 * y + x + i * 10] = 's';
                }
                break;


            default:
                break;
            }






        }


    }

















    /*Spiel*/




    for (int i = 0; i < 100; i++)    /*die Spielfelder, die der Gegner sieht werden mit X befüllt*/
    {
        Spielfeld1x[i] = 'X';
        Spielfeld2x[i] = 'X';
    }



    for (int i = r; n != 1; i++)
    {
        if (i % 2 == 0) {

            for (int u = 0; u < 100; u++)                        /*Schuss von Spieler 1*/
            {
                if (u % 10 == 0)
                {
                    printf("\n");
                }
                printf("[%c]", Spielfeld2x[u]);
            }

            printf("Spieler 1, geben Sie bitte die Koordinaten fuer Ihren Schuss ein\n");
            scanf("%d %d", &x, &y);



            if (Spielfeld2[y * 10 + x] == 's' || Spielfeld2[y * 10 + x] == 'S')
            {
                printf("Treffer!");
                Spielfeld2[y * 10 + x] = 'S';
                Spielfeld2x[y * 10 + x] = 'S';
            }
            else {

                printf("Leider nicht getroffen");
                Spielfeld2[y * 10 + x] = 'W';
                Spielfeld2x[y * 10 + x] = 'W';
            }


            for (int i = 0; i < 100; i++)
            {
                if (Spielfeld2[i] == 'S')
                {
                    Zaehler1++;

                    if (Zaehler1 == 30) {
                        printf("Spieler 1 hat gewonnen!!!");
                        n = 1;
                    }
                }
            }



        }




        /*Schuss von Spieler 2*/

        if (i % 2 == 0) {

            for (int u = 0; u < 100; u++)
            {
                if (u % 10 == 0)
                {
                    printf("\n");
                }
                printf("[%c]", Spielfeld1x[u]);
            }

            printf("Spieler 2, geben Sie bitte die Koordinaten fuer Ihren Schuss ein\n");
            scanf("%d %d", &x, &y);



            if (Spielfeld1[y * 10 + x] == 's' || Spielfeld1[y * 10 + x] == 'S')
            {
                printf("Treffer!");
                Spielfeld1[y * 10 + x] = 'S';
                Spielfeld1x[y * 10 + x] = 'S';
            }
            else {

                printf("Leider nicht getroffen");
                Spielfeld1[y * 10 + x] = 'W';
                Spielfeld1x[y * 10 + x] = 'W';
            }


            for (int i = 0; i < 100; i++)
            {
                if (Spielfeld1[i] == 'S')
                {
                    Zaehler2++;

                    if (Zaehler2 == 30) {
                        printf("Spieler 2 hat gewonnen!!!");
                        n = 1;
                    }
                }
            }



        }


    }















    return 0;
}

/*Change*/
/*Change2*/