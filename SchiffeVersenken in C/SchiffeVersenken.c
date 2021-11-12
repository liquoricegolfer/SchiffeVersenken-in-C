#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cussword.h"




/*BUG fixes:
einige Wahrscheinlichkeiten gehen in den negativen Bereich
wenn ein hit erzielt wurde funktioniert der erste Schuss in die Wahrscheinlichste Richtung, jedoch wird dann nicht mehr verfolgt*/


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




int biggest(int var1, int var2, int var3, int var4) {

    srand(time(NULL));
    int random2 = rand() % 2;
    int random3 = rand() % 3;
    int random4 = rand() % 4;


    /*code  1->rechts  2--> links 3--> oben 4--> unten*/

   


    if ((var1 > var2) && (var1 > var3) && (var1 > var4)) {
        printf("AUSWAHL1");
        return 1;
        
    }
    if ((var2 > var1) && (var2 > var3) && (var1 > var4)) {
        printf("AUSWAHL2");
        return 2;
    }

    if ((var3 > var1) && (var3 > var2) && (var3 > var4)) {
        printf("AUSWAHL3");
        return 3;
    }
    if ((var4 > var1) && (var4 > var2) && (var4 > var3)) {
        printf("AUSWAHL4");
        return 4;
    }
    if ((var1 == var2) && (var1 > var3) && (var1 > var4)) {
        printf("AUSWAHL5");
        if (random2 == 0) {
            return 1;
        }
        if (random2 == 1) {
            return 2;
        }
    }
    if ((var1 == var3) && (var1 > var2) && (var1 > var4)) {
        printf("AUSWAHL6");
        if (random2 == 0) {
            return 1;
        }
        if (random2 == 1) {
            return 3;
        }
    }
    if ((var1 == var4) && (var1 > var2) && (var1 > var3)) {
        printf("AUSWAHL7");
        if (random2 == 0) {
            return 1;
        }
        if (random2 == 1) {
            return 4;
        }

    }


    if ((var2 == var3) && (var2 > var1) && (var2 > var4)) {
        printf("AUSWAHL8");
        if (random2 == 0) {
            return 2;
        }
        if (random2 == 1) {
            return 3;
        }
    }
    if ((var2 == var4) && (var2 > var1) && (var1 > var3)) {
        printf("AUSWAHL9");
        if (random2 == 0) {
            return 2;
        }
        if (random2 == 1) {
            return 4;
        }
    }
    if ((var1 == var2) && (var1 == var3) && (var1 > var4)) {
        printf("AUSWAHL10");
        if (random3 == 0) {
            return 1;
        }
        if (random3 == 1) {
            return 2;
        }
        if (random3 == 2) {
            return 3;
        }
    }

    if ((var2 == var3) && (var2 == var4) && (var2 > var1)) {
        printf("AUSWAHL11");
        if (random3 == 0) {
            return 2;
        }
        if (random3 == 1) {
            return 3;
        }
        if (random3 == 2) {
            return 4;
        }
    }

    if ((var3 == var4) && (var3 == var1) && (var3 > var2)) {
        printf("AUSWAHL12");
        if (random3 == 0) {
            return 3;
        }
        if (random2 == 1) {
            return 4;
        }
        if (random3 == 2) {
            return 1;
        }
    }
    if ((var4 == var1) && (var1 == var2) && (var4 > var3)) {
        printf("AUSWAHL13");
        if (random3 == 0) {
            return 4;
        }
        if (random3 == 1) {
            return 1;
        }
        if (random3 == 2) {
            return 2;
        }
    }


    if ((var1 == var2) && (var1 == var3) && (var1 == var4)) {
        printf("AUSWAHL14");
        if (random4 == 0) {
            return 1;
        }
        if (random4 == 1) {
            return 2;
        }
        if (random4 == 2) {
            return 3;
        }
        if (random4 == 3) {
            return 4;
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
    int highest;
    int highestxy[60];
    int max=3;
    int* xyhit;

    /*
    FILE* ptr;
    ptr = fopen("home/chrisch/Coding/Stats.txt","a+");
    */

   /*

    if (ptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    */

 
    srand(time(NULL));



    for (int i = 0; i < 100; i++) {
        Spielfeld1[i] = 'w';
        Spielfeld2[i] = 'w';
        Probability[i] = 100;

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

    
    int rechts = 0;
    int links = 0;
    int oben = 0;
    int unten = 0;
    int hitting = 0;
    xy = 0;
    xyhit = 0;
    int prechts=0;
    int plinks=0;
    int poben = 0;
    int punten = 0;
    int firsthit = 0;

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
                            Sleep(2);
                            n = 1;

                        }
                    }
                }



            }




            /*Schuss von Algorithmus*/

            if (i % 2 == 0) {


                /*Sleep(1000);*/


                system("cls");

                for (int b = 0; b < 100; b++) {

                    if (Spielfeld2x[b] != 'X') {

                        Probability[b] = 0;
                    }

                }
                /*rounds wurde noch nicht aktualisiert*/
                if (rounds != 0 && hit==0) {

                    Probability[xy] = 0;
                    
                }

                

                printf("hit = %d xy= %d\n",hit,xy );

                /*Befüllung des Wahrscheinlichkeitsarrays*/
                
                for (int b = 0; b < 100; b++) {

                    for (int e = 1; e < 5; e++) {
                        
                        if (Probability[b] != 0) {

                            if (Probability[b + e] == 0) {
                                Probability[b]--;
                            }
                            if (Probability[b - e] == 0) {
                                Probability[b]--;
                            }
                            if (Probability[(b - (e * 10))] == 0) {
                                Probability[b]--;
                            }
                            if (Probability[(b + (e * 10))] == 0) {
                                Probability[b]--;
                            }


                            if (((b + e) / 10) > (b / 10) || ((b + e) > 99)) {
                                Probability[b]--;
                            }
                            if (((b - e) / 10) < (b / 10) || ((b - e) < 0)) {
                                Probability[b]--;
                            }


                            if (b + (e * 10) > 99) {
                                Probability[b]--;
                            }
                            if ((b - (e * 10)) < 0) {
                                Probability[b]--;
                            }
                        }
                    }
                }

                /*Ausgabe des Wahrscheinlichkeitsarrays zur Überprüfung*/

                for (int b = 0; b < 100; b++) {
                    if (b % 10 == 0) {
                        printf("\n");
                    }
                    printf("[%d]", Probability[b]);
                }

                /*Auswertung der Koordinaten mit der höchsten Wahrscheinlichkeit*/
                highest = Probability[0];
                int p = 1;

                for (int j = 1; j < 100; j++)
                {
                    if (highest < Probability[j]) {


                        highestxy[0] = j;
                        highest = Probability[j];
                        p = 1;
                    }
                    if (highest == Probability[j]) {
                        highestxy[p] = Probability[j];
                        p++;
                    }
                
                }

                printf("\nhighesefskdjfkdsj Probability: %d %d\n", highestxy[0], highestxy[1]);


               
                    xyhit = xy;
                    
                
                /*Random Schuss mit der höchsten Wahrscheinlichkeit falls zuvor nicht getrife´n wurde*/

                if (hit == 0 && hitting == 0) {
                    xy = highestxy[rand() % (p)];
                }

                

                rounds++;
                if (rounds == 1) {
                    xy = 44;

                }

                /*falls nicht getroffen wurde, aber zuvor zweimal hintereinander*/
                if (hit == 0 && hitting == 1) {
                    if (rechts > 1) {
                        links = 1;
                        if ((firsthit - 1) < 0) {
                            hitting = 0;
                            rechts = 0;
                            links = 0;
                            oben = 0;
                            unten = 0;
                        }
                        else {
                            xy = firsthit - 1;
                        }
                    }

                    if (links > 1) {
                        rechts = 1;
                        if ((firsthit + 1) > 99) {
                            hitting = 0;
                            rechts = 0;
                            links = 0;
                            oben = 0;
                            unten = 0;
                        }
                        xy = firsthit + 1;

                    }
                    if (oben > 1) {
                        unten = 1;
                        if ((firsthit + 10) > 99) {
                            hitting = 0;
                            rechts = 0;
                            links = 0;
                            oben = 0;
                            unten = 0;
                        }
                        else {
                            xy = firsthit + 10;
                        }
                    }
                    if (unten > 1) {
                        oben = 1;
                        if ((firsthit - 10) < 0) {
                            hitting = 0;
                            rechts = 0;
                            links = 0;
                            oben = 0;
                            unten = 0;
                        }
                        else {


                            xy = firsthit - 10;
                        }



                    }
                }
                

                printf("\nrounds = %d highest Probability RANDOM!!!!!= %d\n", rounds, xy);
                
                /*hier schaut man ob die maximale Länge erreicht wurde, falls ja wird abgebrochen und per random geschossen*/
                if (hit == 1 && hitting == 1) {
                    
                    if (rechts != 0) {
                        rechts++;
                    }
                    if (links != 0) {
                        links++;
                    }
                    if (oben != 0) {
                        oben++;
                    }
                    if (unten != 0) {
                        unten++;
                    }
                    if (rechts == 5 || links == 5 || oben == 5 || unten == 5) {
                        hitting = 0;
                        rechts = 0;
                        links = 0;
                        oben = 0;
                        unten = 0;
                    }
                    if (((rechts + links) == 5) || ((oben + unten) == 5)) {
                        hitting = 0;
                        rechts = 0;
                        links = 0;
                        oben = 0;
                        unten = 0;
                    }

                    
                }
               


                    /*falls direkt nach einen Treffer verfehlt wird*/

                    if (rechts == 1 || links ==1 || oben ==1 || unten == 1) {
                        printf("Schleife!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        if ((biggest(Probability[firsthit + 1], Probability[firsthit - 1], Probability[firsthit - 10], Probability[firsthit + 10])) == 1) {

                            xy = firsthit + 1;
                            rechts = 1;
                            unten = 0;
                            links = 0;
                            oben = 0;
                        }
                        if ((biggest(Probability[firsthit + 1], Probability[firsthit - 1], Probability[firsthit - 10], Probability[firsthit + 10])) == 2) {

                            xy = firsthit - 1;
                            links = 1;
                            oben = 0;
                            rechts = 0;
                            unten = 0;
                        }
                        if ((biggest(Probability[firsthit + 1], Probability[firsthit - 1], Probability[firsthit - 10], Probability[firsthit + 10])) == 3) {

                            xy = firsthit - 10;
                            oben = 1;
                            links = 0;
                            rechts = 0;
                            unten = 0;
                            
                        }
                        if ((biggest(Probability[firsthit + 1], Probability[firsthit - 1], Probability[firsthit - 10], Probability[firsthit + 10])) == 4) {

                            xy = firsthit + 10;
                            unten = 1;
                            oben = 0;
                            links = 0;
                            rechts = 0;
                            

                        }

                    }



                
               
                /*Wahrscheinlichkeit für nächste Richtung*/

                if (hit == 1) {

                    /*Falls getroffen wurde und die Richtung mit der höchsten Wahrscheinlichkeit richtig gewählt war*/
                    if (hitting == 1) {

                        if (rechts != 0) {
                            xy = xy + 1;
                            printf("HIIIIIIIIIIIIIIIIIIIIIIIIIIIIIITTTTTTTT RECHTS &&&&& %d",xy);
                        }
                        if (links != 0) {
                            xy = xy - 1;
                            printf("HIIIIIIIIIIIIIIIIIIIIIIIIIIIIIITTTTTTTT LLLLLLLLLLLLLIIIIIIINKKKKKKKKSSSSSS");
                        }
                        if (oben != 0) {
                            xy = xy - 10;
                        }
                        if (unten != 0) {
                            xy = xy + 10;
                        }
                    }

                    if (hitting == 0) {
                        firsthit = xyhit;

                        if (biggest(Probability[firsthit + 1], Probability[firsthit - 1], Probability[firsthit - 10], Probability[firsthit + 10]) == 1) {

                            xy = firsthit + 1;
                            rechts = 1;
                            links = 0;
                            oben = 0;
                            unten = 0;
                            printf("RECHTS!!");

                        }
                        if (biggest(Probability[firsthit + 1], Probability[firsthit - 1], Probability[firsthit - 10], Probability[firsthit + 10]) == 2) {

                            xy = firsthit - 1;
                            links = 1;
                            rechts = 0;
                            oben = 0;
                            unten = 0;
                            printf("LINKS!!");
                        }
                        if (biggest(Probability[firsthit + 1], Probability[firsthit - 1], Probability[firsthit - 10], Probability[firsthit + 10]) == 3) {

                            xy = firsthit - 10;
                            oben = 1;
                            rechts = 0;
                            links = 0;
                            unten = 0;


                            printf("OBEN!!");
                        }
                        if (biggest(Probability[firsthit + 1], Probability[firsthit - 1], Probability[firsthit - 10], Probability[firsthit + 10]) == 4) {

                            xy = firsthit + 10;
                            unten = 1;
                            rechts = 0;
                            links = 0;
                            oben = 0;
                            printf("UNTEN!!");

                        }

                        hitting = 1;
                    
                    }

                    
                    
                    

                }
                
                
                
                    


               



                printf("Geschossen wird auf  %d\n", xy);
                printf("mit einer wahrscheinlichkeit von %d\n", Probability[xy]);



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






                  Sleep(10000);





                Zaehler2 = 0;


                for (int i = 0; i < 100; i++) {
                    if (Spielfeld2[i] == 'S') {
                        Zaehler2++;

                        if (Zaehler2 == 30) {
                            printf("Spieler 2 hat gewonnen!!!");
                            Sleep(2000);

                            for (int i = 0; i <= rounds; i++) {
                               /* fprintf(ptr, "%d", xy_[i]);*/
                            }
                            n = 1;



                        }





                    }
                }



            }


        }



    }
    

    /*
    fclose(ptr);
    */




   
   

    return 0;
}





/*Change*/
/*Change2*/
