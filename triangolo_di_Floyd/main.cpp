// Autrice: Pamela Loda

#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "TRIANGOLO DI FLOYD" << endl;
    cout << "Inserire un numero: ";
    cin >> n;

    int righe = 1, numero = 1, contatore = 1, numeri_riga = 1;

    cout << endl;

    /*
    Non ho utilizzato il for perchè mi mettevano
    in confusione i contatori.
    */

    while (numero <= n)
    {
        contatore = 1;

        while (contatore <= numeri_riga && numero <= n)
        {
            if (numero < 10)
                cout << "   " << numero;
            else if (numero < 100)
                cout << "  " << numero;
            else
                cout << " " << numero;

            numero++;
            contatore++;
        }

    cout << endl;

    righe++;
    numeri_riga++;

   }

   return 0;
}
