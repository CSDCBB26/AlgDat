#include <stdio.h>
#include <stdlib.h>

// Universelle Funktion, die in beliebigen Arrays das
// groesste oder das kleinste Element findet.

struct meineStruktur
{
    int w1;
    int w2;
    char c;
};

typedef struct meineStruktur mS;
typedef struct meineStruktur * p_mS;

int vgl_int_kl(char * e1, char * e2)
{
    int * wert1 = (int *)e1;
    int * wert2 = (int *)e2;
    
    return *wert1 < *wert2;
}

int vgl_double_gr(char * e1, char * e2)
{
    double * wert1 = (double *)e1;
    double * wert2 = (double *)e2;
    
    return *wert1 > *wert2;
}

int vgl_struct_kl(char * e1, char * e2)
{
    p_mS wert1 = (p_mS)e1;  // aequivalent zu: struct meineStruktur * wert1 = (struct meineStruktur *) e1
    p_mS wert2 = (p_mS)e2;
    
    return ((wert1->w1 - wert1->w2) < (wert2->w1 - wert2->w2)) && (wert1->c > wert2->c);
}

char * SucheElement(char * feld, int len, int groesse, int (*vergleiche)(char *, char *))
{
    // len = Laenge des Feldes
    // groesse = Groesse eines Elementes im Feld
    // 00 01 02 03 04 05 06 007 08 ... Bytes in Feld
    // Beispiel:
    // groesse == 4
    // d.h. Bytes 00 bis 03 bilden einen Wert (entspricht einem Element in Feld)
    //      Bytes 04 bis 07 bilden den zweiten Wert usw.
    
    // Definiere: Erster Wert ist der gesuchte
    char * retWert = feld;
    
    // Stelle auf zweiten Wert
    feld += groesse;
    len -= groesse; //<-- len = len - groesse
    
    // hier: Pointer feld zeigt auf das zweite Element von Feld
    for (char * p = feld; len > 0; len -= groesse, p += groesse)
    {
        if (!vergleiche(retWert, p))   // Ist die Relation (Vergleich) nicht wahr
        {
            retWert = p;        // dann wird p das aktuelle Element für das return
        }
    }
    return retWert;
}


int main()
{
    int f1[10] = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
    double f2[5] = { 3.14, 2.72, 1.23, 42.0, 3.45 };
    mS f3[4] = { {1, 1, 'a'}, {1, 2, 'x'}, {5, 2, 'a'}, {25, 7, 'c'} };
    
    int * p = (int *)SucheElement((char *)f1, 10 * sizeof(int), sizeof(int), vgl_int_kl);
    printf("Der kleinste Wert in f1 ist %d\n\n", *p);

    printf("Der groesste Wert in f2 ist %lf\n\n",
           *(double *)SucheElement((char *)f2, 5 * sizeof(double), sizeof(double), vgl_double_gr));
    //     ^     ^ Typecast für Rueckgabewert
    //     + Dereferenzierung des als Pointer auf double interpretierten Rückgabewertes
    
    p_mS q = (p_mS)SucheElement((char *)f3, 4 * sizeof(mS), sizeof(mS), vgl_struct_kl);
    printf("Das gesuchte Strukturelement ist <%d, %d, %c>\n\n", q->w1, q->w2, q->c);

    return 0;
}
