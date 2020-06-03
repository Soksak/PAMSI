#include"Game.h"
#include<iostream>
using namespace sf;
using namespace std;

int Menu(int &Size, int &Mode, int& Moves)
{

    bool check = 0;

    cout << "           Menu Gry Kóło i Krzyżyk" << endl << endl;
    cout << "       Wybierz wielkość planszy od 3 do 9 " << endl;

    while(check == 0) {
        cout << "           Twój wybór: ";
        cin >> Size;

        if(cin.fail()) {
            cout << "Niepoprawne dane. Wpisz ponownie" << endl << "Wybór: ";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if(Size < 3 || Size > 9) {
            cout << "Niepoprawne dane. Wpisz ponownie "
                 << endl << "Wybór: ";
        } else {
            check = 1;
        }
    }

    check = 0;

    cout << "       Ilość znaków w linii potrzebna do wygranej [3-9]" << endl;

    while(check == 0) {
        cout << "           Twój wybór: ";
        cin >> Moves;

        if(cin.fail()) {
            cout << "Niepoprawne dane. Wpisz ponownie" << endl << "Wybór: ";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if(Moves < 3 || Moves > 9 || Moves > Size) {
            cout << "Niepoprawne dane. Wpisz ponownie "
                 << endl << "Wybór: ";
        } else {
            check = 1;
        }
    }

    check = 0;
    cout << "       Wybierz tryb gry:" << endl
         << "       1 - gra z komputerem, zaczyna gracz" << endl
         << "       2 - gra z komputerem, zaczyna komputer" << endl
         << "       3 - PvP, gracz vs gracz" << endl
         << "           Twój wybór: ";

    while(check == 0) {
        cin >> Mode;
        if(cin.fail()) {
            cout << "Niepoprawne dane. Wpisz ponownie." <<  endl << "Wybor: ";
            cin.clear();
            cin.ignore(10000, '\n');
        } else if(Mode < 1 || Mode > 3) {
            cout << "Niepoprawne dane. Wpisz ponownie" << endl << "Wybór: ";
        } else {
            check = 1;
        }
    }
}
int main()
{

    int Size, Mode, Moves;
    Menu(Size, Mode, Moves);
    Game* game = new Game(Size, Mode, Moves);

    // Główna pętla
    while (game->running()) {

        game->update();
        game->render();

    }
}
