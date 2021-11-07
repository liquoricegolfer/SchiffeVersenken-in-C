// SchiffeVersenken in C.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once

#include <iostream>
#include <time.h>
#ifndef cussword   /* Include guard */
#define cussword

char* randomcussword() {
	srand(time(NULL));
	char cussword_x[57][17] = {"Lump","Ekelpaket","Hanswurst","Lackaffe","Scheusal","Schuft","Hirsch","Urschel","Dillo","Toelpel","Hohlbrot","Buero","Horst","Flachzange","Stinkmorchel","Brotkasten","Lauch","Sau","Vogel","Vollpfosten","Pflaumenaugust","Himbeertoni","Trulla","Hampelmann","Rohrdommel","Arschgeige","Mistmade","Lappen","Montag","Nervensaege","Estragonscheißer","Damdrara","Deliriumwanzn","Wurschtfredl","Verbrunzter","Platzpatrone","Wurst","Eimer","Schmock","Pupskopf","Hornochse","Pflock","Tubel","Mistfink","Heisl","Loeffel","Klobuerste","Oasch","Flasche","Dulli","Koffer","Sepp","Ei","Clown","Arschkriecher","Elendiger","Wirsing"};
		int x = rand()%57;
		char* word;
		word = cussword_x[x];
		return word;

	
}
	
	
	
	/* An example function declaration */
#endif // cussword

// TODO: Verweisen Sie hier auf zusätzliche Header, die Ihr Programm erfordert.
