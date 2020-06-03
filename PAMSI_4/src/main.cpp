#include"Game.h"
#include<iostream>
using namespace sf;
using namespace std;

void Menu(int Size,int Mode){

    bool check=0;

    cout << "     Menu Gry Kóło i Krzyżyk"<<endl;
    cout<< "Wybierz wielkość planszy od 3 do 9 "<<endl;
    while(check==0){

        cin >> Size;
        if(cin.fail()){
            cout << "Niepoprawne dane. Wpisz ponownie" << endl << "Wybór: ";
            cin.clear();
            cin.ignore(10000,'\n');
        }
        else if(Size<3 ||Size>26){
            cout <<"Niepoprawne dane. Wpisz ponownie "
            << endl << "Wybór: ";
        }
        else{
        check=1;
        }
    }
    check=0;
    cout << "Wybierz tryb gry:" << endl
    << "1 - gra z komputerem, zaczyna gracz" << endl
    << "2 - gra z komputerem, zaczyna komputer" << endl
    << "3 - PvP, gracz vs gracz" << endl
    << "Twój wybór: ";
    while(check==0){
        cin >> Mode;
        if(cin.fail()){
            cout << "Niepoprawne dane. Wpisz ponownie." <<  endl << "Wybor: ";
            cin.clear();
            cin.ignore(10000,'\n');
        }
        else if(Mode<1 || Mode>3){
            cout << "Niepoprawne dane. Wpisz ponownie" << endl << "Wybór: ";
        }
        else{
            check=1;
        }
    }
}
int main()
{

    int Size,Mode;
    Menu(Size,Mode);
    Game* game=new Game(Size,Mode);
    // Główna pętla
    while (game->running()) {

        game->update();
        game->render();

    }
}
