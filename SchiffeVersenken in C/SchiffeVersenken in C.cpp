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

    for (int e = 0; e < Laenge - 1; e++) {
        if ((random_y[u] - e) == 0) {
            z = z + 30;
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