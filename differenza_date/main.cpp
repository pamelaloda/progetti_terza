// Autrice: Pamela Loda

#include <iostream>

using namespace std;

// Ritorna 1 se è bisestile, zero altrimenti
int bisestile (int a)
{
    if (a % 400 == 0)
        return 1;
    if (a % 100 == 0)
        return 0;
    if (a % 4 == 0)
        return 1;
    return 0;
}

// Ritorna i giorni del mese m
int giorni_del_mese(int m, int a)
{
    if (m == 2)
        return 28 + bisestile(a);
    if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    else
        return 31;
}

// Ritorna il numero di giorni
// da 1 gennaio al mese m escluso
int giorni_dei_mesi(int m, int a)
{
    int giorni = 0;
    for (int i = 1; i < m; i++)
        giorni += giorni_del_mese(i, a);
    return giorni;
}

int giorni_degli_anni(int a)
{
    int giorni = 0;
    for (int i = 1; i < a; i++)
        giorni += 365 + bisestile(i);
    return giorni;
}

// Trasforma una data in giorni
// da 1 gennaio anno 0
int trasforma_in_giorni(int g, int m, int a)
{
    int giorni = 0;
    // con data g = 12, m = 2, a = 2
    // giorni = 12 + 31 + 365 * 2
    giorni = g + giorni_dei_mesi(m, a) + giorni_degli_anni(a);
    return giorni;
}

int differenza_date(int g1, int m1, int a1,
                    int g2, int m2, int a2)
{
    int giorniData1 = trasforma_in_giorni(g1, m1, a1);
    int giorniData2 = trasforma_in_giorni(g2, m2, a2);
    return giorniData1 - giorniData2;
}

int main()
{
    int giorni, mese, anno, giorni2, mese2, anno2;
    cout << "DATA RECENTE: " << endl;
    cout << "Inserisci il giorno: ";
    cin >> giorni;
    cout << "Inserisci il mese: ";
    cin >> mese;
    cout << "Inserisci l'anno: ";
    cin >> anno;
    cout << endl;

    cout << "DATA MENO RECENTE: " << endl;
    cout << "Inserisci il giorno: ";
    cin >> giorni2;
    cout << "Inserisci il mese: ";
    cin >> mese2;
    cout << "Inserisci l'anno: ";
    cin >> anno2;
    cout << endl;

    int differenza = differenza_date(giorni, mese, anno, giorni2, mese2, anno2);
    cout << "La differenza tra le due date vale: " << differenza << " giorni." << endl;
    return 0;
}
