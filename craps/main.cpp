// Autrice: Pamela Loda

#include <iostream>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
    #define PAUSE system("pause>nul|set/p = Premere un tasto per lanciare il dado...");
 #else
    #define PAUSE system("read -p 'Premere INVIO per lanciare il dado...' continue");
 #endif // WIN32

using namespace std;

int main()
{
    int dado1, dado2, target, lancio, tiri = 1, scelta = 1, partite_vinte = 0, partite_perse = 0;

    cout << "                CRAPS                " << endl << endl;

    srand (time(NULL));

    while (scelta == 1)
    {
        PAUSE
        cout << endl << endl;

        cout << "Tiro numero " << tiri << endl << endl;

        dado1 = rand() % 6 + 1;
        cout << "Il primo dado segna: " << dado1 << endl;

        dado2= rand() % 6 + 1;
        cout << "Il secondo dado segna: " << dado2 << endl << endl;

        lancio = dado1 + dado2;
        cout << "La somma dei due numeri sui dadi viene: " << lancio << endl << endl;

        if (lancio == 7)
        {
            partite_vinte++;
            cout << "HAI VINTO!" << endl << "IL GIOCO FINISCE QUI." << endl << endl;
        }
        else if (lancio == 2 || lancio == 3 || lancio == 12)
        {
            partite_perse++;
            cout << "HAI PERSO!" << endl << "IL GIOCO FINISCE QUI." << endl << endl;
        }
        else
        {
            target = lancio;
            lancio = lancio - 10;

            cout << "Il target ora risulta " << target << " cerca di azzeccarlo!" << endl << endl;

            while (lancio != target && lancio != 7)
            {
                //cout << "Ritira i dadi (1 Tiro - 0 No)? ";
                //cin >> scelta;

                PAUSE
                cout << endl << endl;

                tiri++;

                cout << "Tiro numero " << tiri << endl << endl;

                dado1 = rand() % 6 + 1;
                cout << "Il primo dado segna: " << dado1 << endl;

                dado2 = rand() % 6 + 1;
                cout << "Il secondo dado segna: " << dado2 << endl << endl;

                lancio = dado1 + dado2;
                cout << "La somma dei due numeri sui dadi viene: " << lancio << endl << endl;

                if (target != lancio && lancio != 7)
                    cout << "Il target era " << target << " ritenta!" << endl << endl;
            }

            if (lancio == 7)
            {
                partite_perse++;
                cout << "HAI PERSO!" << endl << "IL GIOCO FINISCE QUI." << endl << endl;
            }
            else if (target == lancio)
            {
                partite_vinte++;
                cout << "Hai azzeccato il target!" << endl << "HAI VINTO! IL GIOCO FINISCE QUI." << endl << endl;
            }

            cout << "Vuoi giocare un'altra partita? (1-SI, 0-NO): ";
            cin >> scelta;
            cout << endl;
            tiri = 1;
        }
   }
        cout << "Hai vinto " << partite_vinte << " partite!" << endl << endl;
        cout << "Hai perso " << partite_perse << " partite!" << endl << endl;

    return 0;
}
