//Autrice: Pamela Loda

#include <iostream>

using namespace std;

int main()
{
    const int N1 = 1000;
    int v[N1], v1[N1];
    int N;
    int numero;
    int somma = 0, contatore_pari = 0, contatore_dispari = 0, elementi = 0, elementi1 = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> numero;
        while (numero < 0 || numero > 5)
        {
            cin >> numero;
            N + 1;
        }
        if (numero % 2 == 0)
        {
            contatore_pari++;
            v[elementi] = i;
            elementi++;
        }
        else
        {
            contatore_dispari++;
            v1[elementi1] = i;
            elementi1++;
        }
        somma += numero;
    }
    if (somma % 2 == 0)
    {
        cout << contatore_pari << endl;
        for (int i = 0; i < elementi; i++)
            cout << v[i] << " ";
    }
    else
    {
        cout << contatore_dispari << endl;
        for (int i = 0; i < elementi1; i++)
            cout << v1[i] << " ";
    }
    return 0;
}
