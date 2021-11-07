#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cussword.h"
#include <Windows.h>
#include <iostream>





void Schuss(int Spieler, char Spielfeld[], char Spielfeldx[]){
    int x;
    int y;

for (int u = 0; u < 100; u++) {                      
    if (u % 10 == 0) {
        printf("\n");
    }
    printf("[%c]", Spielfeldx[u]);
}

printf("Spieler %d, geben Sie bitte die Koordinaten fuer Ihren Schuss ein\n", Spieler);
scanf("%d %d", &x, &y);



if (Spielfeld[y * 10 + x] == 's' || Spielfeld[y * 10 + x] == 'S') {
    printf("Treffer!");
    Spielfeld[y * 10 + x] = 'S';
    Spielfeldx[y * 10 + x] = 'S';
}
else {

    printf("Leider nicht getroffen");
    Spielfeld[y * 10 + x] = 'W';
    Spielfeldx[y * 10 + x] = 'W';
}
int Zaehler = 0;


for (int i = 0; i < 100; i++) {
    if (Spielfeld[i] == 'S') {
        Zaehler++;

        if (Zaehler == 30) {
            printf("Spieler %d hat gewonnen!!!", Spieler);
            break;
        }
    }
}



}




int main() {
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
    int Auswahl;
    char random_Richtung[10];
    int random_y[400];
    int random_x[400];
    char random_Schiff[10] = { 'F','S','S','K','K','K','B','B','B','B' };
    int Fehler[5] = { 0,0,0,0,0 };
    int Felder[5] = { 0,0,0,0,0 };
    int Ueberpruefung[50];
    int Summe[10];
    int ztemp;
    int rounds;
    int counter_a = 0;
    int sunk = 0;
    int hit = 0;
    char* word_cussword;
    int missrightleft = 0;
    int missup = 0;
    int hittingships=0;
    int xy_[100];
    int xy;
    int Probability[100];
    int a;
   

    int max=3;
    int xyhit;

    FILE* ptr;
    ptr = fopen("Stats.txt","a+");


    if (ptr == NULL)
    {
        printf("Error!");
        exit(1);
    }


    int Laengenarray[4] = { 4,3,2,1 };
    for (int i = 0; i < 10; i++) {
        Summe[i] = 0;
    }
    for (int i = 0; i < 50; i++) {
        Ueberpruefung[i] = 0;
    }
    srand(time(NULL));



    for (int i = 0; i < 100; i++) {
        Spielfeld1[i] = 'w';
        Spielfeld2[i] = 'w';
        Probability[100] = 100;

    }







    
     
     
    


    printf("Geben Sie bitte die Anzahl der Spieler ein(1/2)\n");
    scanf("%d", &Auswahl);



    if (Auswahl == 2) {



        /*Schiffplazierung*/






        for (int i = 10; i > 0; i--) {

            system("@cls||clear");

            if (k == 1) {
                printf("Es stehen leider keine weiteren Schiff dieser Art zur verfuegung, bitte waehlen Sie eine andere Art.\n\n");
            }
            k = 0;



            if (i < 10) {
                printf("\nEs sind noch %d Schiffe zu vergeben\n", i);
            }

            for (int i = 0; i < 100; i++) {
                if (i % 10 == 0) {
                    printf("\n");
                }
                printf("[%c]", Spielfeld1[i]);

            }

            printf("\n\nSpieler 1, Welches Schiff wollen Sie plazieren?\n");
            printf("-->\nFlugzeugtraeger(1 Stueck  5 Felder Kuerzel: F)\nSchlachtSchiffe(2 Stueck  4 Felder Kuerzel: S)\n");
            printf("Kreuzer        (3 Stueck  3 Felder Kuerzel: K)\nSchnellboote   (4 Stueck  2 Felder Kuerzel: B)\n");

            scanf("%s", &Schiffe);


            /*SchiffsLaenge*/
            switch (Schiffe) {


            case 'F':
                if (Schiffanzahl[0] != 0) {
                    Laenge = 5;
                    Schiffanzahl[0]--;
                }
                else {

                    k = 1;
                    i++;

                }
                break;

            case 'S':
                if (Schiffanzahl[1] != 0) {
                    Laenge = 4;
                    Schiffanzahl[1]--;
                }
                else {

                    k = 1;
                    i++;

                }
                break;

            case 'K':
                if (Schiffanzahl[2] != 0) {
                    Laenge = 3;
                    Schiffanzahl[2]--;
                }
                else {

                    k = 1;
                    i++;

                }
                break;

            case 'B':
                if (Schiffanzahl[3] != 0) {
                    Laenge = 2;
                    Schiffanzahl[3]--;
                }
                else {

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

            switch (Richtung) {


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








        for (int i = 10; i > 0; i--) {

            system("@cls||clear");

            if (k == 1) {
                printf("Es stehen leider keine weiteren Schiff dieser Art zur verfuegung, bitte waehlen Sie eine andere Art.\n\n");
            }
            k = 0;

            if (i < 10) {
                printf("\nEs sind noch %d Schiffe zu vergeben\n", i);
            }

            for (int i = 0; i < 100; i++) {
                if (i % 10 == 0) {
                    printf("\n");
                }
                printf("[%c]", Spielfeld2[i]);

            }

            printf("\n\nSpieler 2, Welches Schiff wollen Sie plazieren?\n");
            printf("-->\nFlugzeugtraeger(1 Stueck  5 Felder Kuerzel: F)\nSchlachtSchiffe(2 Stueck  4 Felder Kuerzel: S)\n");
            printf("Kreuzer        (3 Stueck  3 Felder Kuerzel: K)\nSchnellboote   (4 Stueck  2 Felder Kuerzel: B)\n");

            scanf("%s", &Schiffe);



            /*SchiffsLaenge*/
            switch (Schiffe) {


            case 'F':
                if (Schiffanzahl[0] != 0) {
                    Laenge = 5;
                    Schiffanzahl[0]--;
                }
                else {
                    printf("\n\nEs stehen leider keine weiteren Schiff dieser Art zur verfügung, bitte waehlen Sie eine andere Art.\n\n");
                    k = 1;
                    i++;

                }
                break;

            case 'S':
                if (Schiffanzahl[1] != 0) {
                    Laenge = 4;
                    Schiffanzahl[1]--;
                }
                else {
                    printf("Es stehen leider keine weiteren Schiff dieser Art zur verfügung, bitte waehlen Sie eine andere Art.");
                    k = 1;
                    i++;

                }
                break;

            case 'K':
                if (Schiffanzahl[2] != 0) {
                    Laenge = 3;
                    Schiffanzahl[2]--;
                }
                else {
                    printf("Es stehen leider keine weiteren Schiff dieser Art zur verfügung, bitte waehlen Sie eine andere Art.");
                    k = 1;
                    i++;

                }
                break;

            case 'B':
                if (Schiffanzahl[3] != 0) {
                    Laenge = 2;
                    Schiffanzahl[3]--;
                }
                else {
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
            switch (Richtung) {


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

    else {                                  /*random generiertes Spielfeld*/






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











        for (int u = 0; u < 10; u++) {
            switch (random_Schiff[u]) {


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

            for (int g = 0; g < 5; g++) {
                Fehler[g] = 0;

            }
            z = 0;
            ztemp = 0;

            printf("%c", random_Richtung[u]);




            switch (random_Richtung[u]) {


            case 'r':


                while (1) {



                    for (int e = 0; e < Laenge; e++) {

                        Felder[e] = 10 * random_y[u] + random_x[u] + e;

                        if (Spielfeld1[10 * random_y[u + z] + random_x[u + z] + e] == 's') {
                            Fehler[e] = 1;
                        }
                        else {
                            Fehler[e] = 0;
                        }
                    }
                    for (int e = 0; e < Laenge - 1; e++) {

                        if ((random_x[u + z] + e) == 9) {

                            z = z + 30;
                            Fehler[e] = 1;


                        }


                    }



                    if (Fehler[0] + Fehler[1] + Fehler[2] + Fehler[3] + Fehler[4] != 0) {
                        z = z + 30;



                    }

                    else {

                        for (int i = 0; i < Laenge; i++) {
                            Spielfeld1[10 * random_y[u + z] + random_x[u + z] + i] = 's';
                        }
                        break;
                    }
                    for (int e = 0; e < 5; e++) {
                        Fehler[e] = 0;
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


                while (1) {



                    for (int e = 0; e < Laenge; e++) {

                        if (Spielfeld1[10 * random_y[u + z] + random_x[u + z] - e] == 's') {
                            Fehler[e] = 1;
                        }
                        else
                            Fehler[e] = 0;
                    }
                    for (int e = 0; e < Laenge - 1; e++) {

                        if ((random_x[u + z] - e) == 0) {

                            z = z + 30;
                            Fehler[e] = 1;

                        }


                    }



                    if ((Fehler[0] + Fehler[1] + Fehler[2] + Fehler[3] + Fehler[4]) != 0) {
                        z = z + 30;



                    }

                    else {

                        for (int i = 0; i < Laenge; i++) {
                            Spielfeld1[10 * random_y[u + z] + random_x[u + z] - i] = 's';
                        }
                        break;
                    }


                    for (int e = 0; e < 5; e++) {
                        Fehler[e] = 0;
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

                while (1) {



                    for (int e = 0; e < Laenge; e++) {
                        if (Spielfeld1[10 * random_y[u + z] + random_x[u + z] - e * 10] == 's') {
                            Fehler[e] = 1;
                            Felder[e] = 10 * random_y[u] + random_x[u] - e * 10;



                        }
                        else {
                            Fehler[e] = 0;
                        }
                    }
                    printf("\n%d %d\n", random_x[u + z], random_y[u + z]);

                    ztemp = z;


                    for (int e = 0; e < (Laenge - 1); e++) {
                        if ((random_y[u + z] - e) == 0) {
                            z = z + 30;
                            Fehler[e] = 1;
                        }
                    }


                    if ((Fehler[0] + Fehler[1] + Fehler[2] + Fehler[3] + Fehler[4]) != 0) {
                        z = z + 30;



                    }

                    else {

                        for (int i = 0; i < Laenge; i++) {
                            Spielfeld1[10 * random_y[u + z] + random_x[u + z] - i * 10] = 's';
                        }
                        break;
                    }

                    for (int e = 0; e < Laenge; e++) {

                        Fehler[e] = 0;
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
                while (1) {






                    for (int e = 0; e < Laenge; e++) {
                        if (Spielfeld1[10 * random_y[u + z] + random_x[u + z] + e * 10] == 's') {
                            Fehler[e] = 1;
                            Felder[e] = 10 * random_y[u] + random_x[u] + e * 10;



                        }
                        else {
                            Fehler[e] = 0;
                        }
                    }

                    for (int e = 0; e < Laenge - 1; e++) {
                        if ((random_y[u + z] + e) == 9) {
                            z = z + 30;
                            Fehler[e] = 1;

                        }
                    }


                    if ((Fehler[0] + Fehler[1] + Fehler[2] + Fehler[3] + Fehler[4]) != 0) {
                        z = z + 30;

                    }

                    else {

                        for (int i = 0; i < Laenge; i++) {
                            Spielfeld1[10 * random_y[u + z] + random_x[u + z] + i * 10] = 's';
                        }
                        break;
                    }
                    for (int e = 0; e < 5; e++) {

                        Fehler[e] = 0;
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
                /*for(int i=0; i<Laenge; i++){
                Spielfeld1[10*random_y[u]+random_x[u]+i*10]='s';
                }
                break;
                */

            default:
                break;
            }


            printf("%d %d\n \n%d\n", random_x[u + z], random_y[u + z], Laenge);

        }
/*
        int counter = 0;;


        for (int i = 0; i < 100; i++) {

            if (i % 10 == 0) {
                printf("\n");
            }

            printf("[%c]", Spielfeld1[i]);
            if (Spielfeld1[i] == 's') {
                counter++;
            }
        }
        printf("Counter: %d", counter);

        printf("\n");


        */



        /*Spieler*/




        for (int i = 10; i > 0; i--) {

            system("@cls||clear");

            if (k == 1) {
                printf("Es stehen leider keine weiteren Schiff dieser Art zur verfuegung, bitte waehlen Sie eine andere Art.\n\n");
            }
            k = 0;



            if (i < 10) {
                printf("\nEs sind noch %d Schiffe zu vergeben\n", i);
            }

            for (int i = 0; i < 100; i++) {
                if (i % 10 == 0) {
                    printf("\n");
                }
                printf("[%c]", Spielfeld2[i]);

            }

            printf("\n\nSpieler 1, Welches Schiff wollen Sie plazieren?\n");
            printf("-->\nFlugzeugtraeger(1 Stueck  5 Felder Kuerzel: F)\nSchlachtSchiffe(2 Stueck  4 Felder Kuerzel: S)\n");
            printf("Kreuzer        (3 Stueck  3 Felder Kuerzel: K)\nSchnellboote   (4 Stueck  2 Felder Kuerzel: B)\n");

            scanf("%s", &Schiffe);


            /*SchiffsLaenge*/
            switch (Schiffe) {


            case 'F':
                if (Schiffanzahl[0] != 0) {
                    Laenge = 5;
                    Schiffanzahl[0]--;
                }
                else {

                    k = 1;
                    i++;

                }
                break;

            case 'S':
                if (Schiffanzahl[1] != 0) {
                    Laenge = 4;
                    Schiffanzahl[1]--;
                }
                else {

                    k = 1;
                    i++;

                }
                break;

            case 'K':
                if (Schiffanzahl[2] != 0) {
                    Laenge = 3;
                    Schiffanzahl[2]--;
                }
                else {

                    k = 1;
                    i++;

                }
                break;

            case 'B':
                if (Schiffanzahl[3] != 0) {
                    Laenge = 2;
                    Schiffanzahl[3]--;
                }
                else {

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

            switch (Richtung) {


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




    rounds = 0;
   

    for (int i = 0; i < 100; i++) {  /*die Spielfelder, die der Gegner sieht werden mit X befüllt*/
        Spielfeld1x[i] = 'X';
        Spielfeld2x[i] = 'X';
    }
    if (Auswahl == 2) {


        for (int i = r; n != 1; i++) {
            if (i % 2 == 0) {

                Schuss(1, Spielfeld2, Spielfeld2x);
            }




            /*Schuss von Spieler 2*/

            if (i % 2 == 0) {

                Schuss(2, Spielfeld1, Spielfeld1x);



            }


        }




    }

    
    


    if (Auswahl == 1) {


        for (int i = r; n != 1; i++) {

            system("cls");

            if (i % 2 == 0) {

                for (int u = 0; u < 100; u++) {                      /*Schuss von Spieler*/
                    if (u % 10 == 0) {
                        printf("\n");
                    }
                    printf("[%c]", Spielfeld1x[u]);
                }

                printf("Geben Sie bitte die Koordinaten fuer Ihren Schuss ein\n");
                scanf("%d %d", &x, &y);



                if (Spielfeld1[y * 10 + x] == 's' || Spielfeld1[y * 10 + x] == 'S') {
                    printf("Treffer!");
                    Spielfeld1[y * 10 + x] = 'S';
                    Spielfeld1x[y * 10 + x] = 'S';
                }
                else {

                    printf("Leider nicht getroffen");
                    Spielfeld1[y * 10 + x] = 'W';
                    Spielfeld1x[y * 10 + x] = 'W';
                }
                Zaehler1 = 0;


                for (int i = 0; i < 100; i++) {
                    if (Spielfeld1[i] == 'S') {
                        Zaehler1++;

                        if (Zaehler1 == 30) {
                            printf("Sie haben gewonnen!!!");
                            Sleep(2000);
                            n = 1;
                            
                        }
                    }
                }



            }




            /*Schuss von Algorithmus*/

            if (i % 2 == 0) {


                /*Sleep(1000);*/


                system("cls");



                for (int j = 0; j < 100; j++) {

                    if (Spielfeld2x[xy] != 'W' && Spielfeld2x[xy] != 'S') {
                        
                        for (int e=4;i>0; e--) {
                            if (Spielfeld2x[j + e] <= 99) {
                                if (Spielfeld2x[j + e] == 'W' || Spielfeld2x[j + e] == 'S')
                                    Probability[j]--;
                            }
                            else {
                                Probability[j]--;
                            }
                            if (Spielfeld2x[j + e] >= 0) {
                                if (Spielfeld2x[j - e] == 'W' || Spielfeld2x[j - e] == 'S')
                                    Probability[j]--;
                            }
                            else {
                                Probability[j]--;
                            }
                            if (Spielfeld2x[j + e * 10] <= 99) {
                                if (Spielfeld2x[j + e * 10] == 'W' || Spielfeld2x[j + e * 10] == 'S')
                                    Probability[j]--;
                            }
                            else {
                                Probability[j]--;
                            }
                            if (Spielfeld2x[j + e] > 0) {
                                if (Spielfeld2x[j - e * 10] == 'W' || Spielfeld2x[j - e * 10] == 'S')
                                    Probability[j]--;
                            }
                            else {
                                Probability[j]--;
                            }

                        }
                    }


                }
               
                for (int e = 0; e < 100; ++e)
                {

                    for (int j = e + 1; j < 100; ++j)
                    {

                        if (Probability[e] > Probability[j])
                        {

                            a = Probability[e];
                            Probability[e] = Probability[j];
                            Probability[j] = a;

                        }

                    }

                }

                


                rounds++;
                if (rounds == 1) {
                    xy = 44;
                    
                }


                /*beobachtung der maximalen Schiffllänge*/
                if (Laengenarray[4] == 0) {
                    max = 3;
                }
                if (Laengenarray[3] == 0 && Laengenarray[4]==0) {
                    max = 2;
                }
                if (Laengenarray[2] == 0 && Laengenarray[3] == 0 && Laengenarray[4]==0) {
                    max = 1;
                }
                if (Laengenarray[1] == 0 && Laengenarray[2] == 0 && Laengenarray[3] == 0 && Laengenarray[4] == 0) {
                }
                    max = 0;


                    if (rounds != 1 && hit==0) {
                    }
                    if (Spielfeld2x[xy + 15] != 'S') {
                        xy = xy + 15;
                    }

                    
                

                

            }



            


            

            if (Spielfeld2[xy] == 's' || Spielfeld2[xy] == 'S') {
                printf("\n\nHAHA! Du %s\n\n", randomcussword());
                Spielfeld2[xy] = 'S';
                Spielfeld2x[xy] = 'S';
                hit = 1;
                xy_[rounds / 2] = xy;
               
            }
            else {

                printf("\n\n...");
                Spielfeld2[xy] = 'W';
                Spielfeld2x[xy] = 'W';
                hit = 0;
            }






          /*  Sleep(1000);*/





            Zaehler2 = 0;


            for (int i = 0; i < 100; i++) {
                if (Spielfeld2[i] == 'S') {
                    Zaehler2++;

                    if (Zaehler2 == 30) {
                        printf("Spieler 2 hat gewonnen!!!");
                        Sleep(2000);
                        for (int i = 0; i <= rounds; i++) {
                            fprintf(ptr, "%d", xy_[i]);
                        }
                        n = 1;
                        
                       
                       
                    }





                }
            }



        }


    }




    


    fclose(ptr);





   
   

    return 0;
}

/*Change*/
/*Change2*/
