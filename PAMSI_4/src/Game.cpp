#include "Game.h"


void Game::initOX()
{
    this->tekstura1.loadFromFile("kolko.jpg");
    this->o.setTexture(tekstura1);
    o.setScale(3.f / Size, (3.f / Size));
    this->tekstura2.loadFromFile("x.png");
    this->x.setTexture(tekstura2);
    x.setScale(3.f / Size, 3.f / Size);

}
void Game::initVar()
{
    this->window = nullptr;
    this->initOX();
    turn = 'o';
    this->endGame = false;

    if(Size == 3)
    {
        MaxDepth = 5;
    } else if(Size < 7)
    {
        MaxDepth = 3;
    } else if(Size <= 9)
    {
        MaxDepth = 2;
    }

    font.loadFromFile("arial.ttf");

    for(int i = 0; i < Size * Size; i++)
    {
        pola.push_back('e');
    }

    plansza.resize(Size);

    for (int i = 0; i < Size; i++) {
        plansza[i].resize(Size, 'e');
    }

}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(900, 960), "kolko krzyzyk");
}


void Game::initFields()
{
    this->field.setPosition(0.f, 0.f);
    this->field.setSize(sf::Vector2f(900.f / Size, 900.f / Size));
    this->field.setFillColor(sf::Color::White);
    this->field.setOutlineColor(sf::Color::Black);
    this->field.setOutlineThickness(3.f);

    for(int j = 0; j < Size; j++) {
        for(int i = 0; i < Size; i++) {
            this->fields.push_back(this->field);
            this->field.setPosition(this->field.getPosition().x + this->field.getSize().x, this->field.getPosition().y);
        }
        this->field.setPosition(0.f, this->field.getPosition().y + this->field.getSize().y);
    }
}

void Game::initText()
{
    endGameText.setFont(font);
    endGameText.setCharacterSize(40);
    endGameText.setFillColor(sf::Color::Red);
    endGameText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    endGameText.setOutlineColor(sf::Color::Black);
    endGameText.setOutlineThickness(5.f);
    gameText.setFont(font);
    gameText.setCharacterSize(18);
    gameText.setFillColor(sf::Color::Green);
    gameText.setPosition(200.f, 900.f);

}
Game::Game(int size, int mode, int movToWin)
{
    this->Size = size;
    this->Mode = mode;
    this->MovToWin = movToWin;
    this->initVar();
    this->initWindow();
    this->initFields();
    this->initText();
}

Game::~Game()
{
    delete this->window;
}

const bool Game::running()
{
    return this->window->isOpen();
}

const bool& Game::getEndGame()const
{
    return this->endGame;
}

int Game::checkWinner()
{
    int countx = 0;
    int counto = 0;
    int counte = 0;

    //poziom
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            if (plansza[j][i] == 'x') {
                countx++;
                counto = 0;
                counte -= 1;
            }
            if (countx == MovToWin && counto == 0 && counte <= 0) {
                return 10;
            }
            if (plansza[j][i] == 'o') {
                counto++;
                countx = 0;
                counte -= 1;
            }
            if (counto == MovToWin && countx == 0 && counte <= 0) {
                return -10;
            }
            if(plansza[j][i] == 'e')
                counte = MovToWin;
        }

        countx = 0;
        counto = 0;
        counte = 0;
    }

    countx = 0;
    counto = 0;
    counte = 0;

    //pion
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            if (plansza[i][j] == 'x') {
                countx++;
                counto = 0;
                counte -= 1;
            }
            if (countx == MovToWin && counto == 0 && counte <= 0) {
                return 10;
            }
            if (plansza[i][j] == 'o') {
                counto++;
                countx = 0;
                counte -= 1;
            }
            if (counto == MovToWin && countx == 0 && counte <= 0) {
                return -10;
            }
            if (plansza[i][j] == 'e')
                counte = MovToWin;
        }
        countx = 0;
        counto = 0;
        counte = 0;
    }

    countx = 0;
    counto = 0;
    counte = 0;
    //jedna przekatna
    int j = 0;

    for(int i = 0; i < Size; i++) {
        if (plansza[i][j] == 'x') {
            countx++;
            counto = 0;
            counte -= 1;
        }
        if (countx == MovToWin && counto == 0 && counte <= 0) {
            return 10;
        }
        if (plansza[i][j] == 'o') {
            counto++;
            countx = 0;
            counte -= 1;
        }
        if (counto == MovToWin && countx == 0 && counte <= 0) {
            return -10;
        }
        if (plansza[i][j] == 'e')
            counte = MovToWin;

        j++;
    }
    countx = 0;
    counto = 0;
    counte = 0;
    //druga przekatna
    j = Size - 1;
    for(int i = 0; i < Size; i++) {
        if (plansza[i][j] == 'x') {
            countx++;
            counto = 0;
            counte -= 1;
        }
        if (countx == MovToWin && counto == 0 && counte <= 0) {
            return 10;
        }
        if (plansza[i][j] == 'o') {
            counto++;
            countx = 0;
            counte -= 1;
        }
        if (counto == MovToWin && countx == 0 && counte <= 0) {

            return -10;
        }
        if (plansza[i][j] == 'e')
            counte = MovToWin;
        j--;
    }
    return 0;
}

bool Game::isMovesleft()
{
    for (int i = 0; i < Size; i++)
        for (int j = 0; j < Size; j++)
            if (plansza[i][j] == 'e')
                return true;

    return false;
}

int Game::MinMax(int depth, bool isMax, char player, int alpha, int beta)
{
    char op;

    if(player == 'x') op = 'o';

    if(player == 'o') op = 'x';

    int score = checkWinner();

    if (score == 10) {
        if(player == 'o')
            return -10 + depth;
        else if(player == 'x')
            return 10 - depth;
    }

    if (score == -10) {
        if(player == 'x')
            return -10 + depth;
        else if(player == 'o')
            return 10 - depth;
    }

    if (isMovesleft() == false)
        return 0;

    if (depth == MaxDepth)
        return 0;
    if (isMax) {
        int best = -1000;
        for (int i = 0; i < Size; i++) {
            for (int j = 0; j < Size; j++) {
                if (plansza[i][j] == 'e') {
                    plansza[i][j] = player;
                    best = std::max( best, MinMax(depth + 1, false, player, alpha, beta) );
                    plansza[i][j] = 'e';
                    alpha = std::max(best, alpha);
                    if (alpha >= beta) {
                        break;
                    }
                }
            }
        }
        return best;
    }

    else {
        int best = 1000;
        for (int i = 0; i < Size; i++) {
            for (int j = 0; j < Size; j++) {
                if (plansza[i][j] == 'e') {
                    plansza[i][j] = op;
                    best = std::min(best, MinMax(depth + 1, true, player, alpha, beta));
                    plansza[i][j] = 'e';

                    if (alpha >= beta) {
                        break;
                    }

                }
            }
        }
        return best;
    }
}


std::vector<int> Game::FindBestMove(char player)
{
    int bestVal = -1000;
    std::vector<int> bestmove;
    bestmove.push_back(-1);
    bestmove.push_back(-1);

    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            if (plansza[i][j] == 'e') {
                plansza[i][j] = player;
                int moveVal = MinMax(0, false, player, INT_MIN, INT_MAX);
                plansza[i][j] = 'e';
                if (moveVal > bestVal) {
                    bestmove[0] = i;
                    bestmove[1] = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestmove;
}
void Game::pollEvents()
{
    while(this->window->pollEvent(event)) {
        switch(this->event.type) {
        case sf::Event::Closed:
            this->window->close();
            break;

        case sf::Event::KeyPressed:
            if(this->event.key.code == sf::Keyboard::Escape)
                this->window->close();

            break;
        }
    }
}

void Game::updateMousePos()
{
    this->mousePosWin = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWin);
}

void Game::updateOX()
{
    if (Mode == 3) {
        for(unsigned int i = 0; i < this->fields.size(); i++) {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if(this->fields[i].getGlobalBounds().contains(this->mousePosView)) {

                    if(pola[i] == 'e') {

                        if(turn == 'x') {
                            x.setPosition(this->fields[i].getPosition().x + (90.f / Size), this->fields[i].getPosition().y + (90.f / Size));
                            gameSigns.push_back(x);
                            turn = 'o';
                            pola[i] = 'x';
                            div_t wynik = div( i, Size );
                            plansza[wynik.quot][wynik.rem] = 'x';


                        } else if(turn == 'o') {
                            o.setPosition(this->fields[i].getPosition().x + (90.f / Size), this->fields[i].getPosition().y + (90.f / Size));
                            gameSigns.push_back(o);
                            turn = 'x';
                            pola[i] = 'o';
                            div_t wynik = div( i, Size );
                            plansza[wynik.quot][wynik.rem] = 'o';
                        }

                    }
                }
            }
        }
    } else if(Mode == 2) {
        if (turn == 'o') {
            std::vector<int> vec = FindBestMove('o');
            plansza[vec[0]][vec[1]] = 'o';
            o.setPosition(this->fields[(vec[0]*Size + vec[1])].getPosition().x + (90.f / Size), this->fields[(vec[0]*Size + vec[1])].getPosition().y + (90.f / Size));
            gameSigns.push_back(o);
            turn = 'x';
            pola[(vec[0]*Size + vec[1])] = 'o';
        } else if(turn == 'x') {
            for(unsigned int i = 0; i < this->fields.size(); i++) {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if(this->fields[i].getGlobalBounds().contains(this->mousePosView)) {
                        if(pola[i] == 'e') {
                            x.setPosition(this->fields[i].getPosition().x + (90.f / Size), this->fields[i].getPosition().y + (90.f / Size));
                            gameSigns.push_back(x);
                            turn = 'o';
                            pola[i] = 'x';
                            div_t wynik = div( i, Size );
                            plansza[wynik.quot][wynik.rem] = 'x';
                        }
                    }
                }
            }
        }
    } else if(Mode == 1) {
        if (turn == 'x') {
            std::vector<int> vec = FindBestMove('x');
            plansza[vec[0]][vec[1]] = 'x';
            x.setPosition(this->fields[(vec[0]*Size + vec[1])].getPosition().x + (90.f / Size), this->fields[(vec[0]*Size + vec[1])].getPosition().y + (90.f / Size));
            gameSigns.push_back(x);
            turn = 'o';
            pola[(vec[0]*Size + vec[1])] = 'x';
        } else if(turn == 'o') {
            for(unsigned int i = 0; i < this->fields.size(); i++) {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if(this->fields[i].getGlobalBounds().contains(this->mousePosView)) {
                        if(pola[i] == 'e') {
                            o.setPosition(this->fields[i].getPosition().x + (90.f / Size), this->fields[i].getPosition().y + (90.f / Size));
                            gameSigns.push_back(o);
                            turn = 'x';
                            pola[i] = 'o';
                            div_t wynik = div( i, Size );
                            plansza[wynik.quot][wynik.rem] = 'o';
                        }
                    }
                }
            }
        }
    }

}

void Game::updateWinner()
{
    int Win;
    std::stringstream s;
    Win = checkWinner();

    if(Win == 10) {
        endGame = true;

        if(Mode == 1) {
            s << "Gre wygrywa komputer [X] Przegrales" << std::endl << "Nacisnij ESCAPE, aby wyjsc z gry";
        } else {
            s << "Gre wygrywa gracz [X] Gratulacje!" << std::endl << "Nacisnij ESCAPE, aby wyjsc z gry";
        }


    } else if(Win == -10) {
        endGame = true;

        if(Mode == 2) {
            s << "Gre wygrywa komputer [0] Przegrales" << std::endl << "Nacisnij ESCAPE, aby wyjsc z gry";
        } else {
            s << "Gre wygrywa gracz [0] Gratulacje!" << std::endl << "Nacisnij ESCAPE, aby wyjsc z gry";
        }
    } else if(!isMovesleft()) {
        endGame = true;
        s << "Remis. Brak dostepnych ruchow." << std::endl << "Nacisnij ESCAPE, aby wyjsc z gry";
    }

    endGameText.setString(s.str());
    sf::FloatRect textRect = endGameText.getLocalBounds();
    endGameText.setOrigin(textRect.width / 2, textRect.height / 2);
    endGameText.setPosition(sf::Vector2f(900.f / 2.0f, 930.f / 2.0f));

}
void Game::updateText()
{
    std::stringstream ss;

    if(Mode == 1) {
        ss << "Mode - Gracz [O] vs Komputer [X]. Zaczyna gracz. Enjoy! " << std::endl
           << "Plansza o wymiarach [" << Size << "x" << Size << "] # Ilosc znakow wygrywajacyh:" << MovToWin;
    } else if(Mode == 2) {
        ss << "Mode - Gracz [X] vs Komputer [O]. Zaczyna komputer. Enjoy! " << std::endl
           << "Plansza o wymiarach [" << Size << "x" << Size << "] # Ilosc znakow wygrywajacyh:" << MovToWin;
    } else if(Mode == 3) {
        ss << "Mode - Gracz [O] vs Gracz [X]. Zaczyna gracz 'O'. Enjoy! " << std::endl
           << "Plansza o wymiarach [" << Size << "x" << Size << "] # Ilosc znakow wygrywajacyh:" << MovToWin;
    }

    gameText.setString(ss.str());

}
void Game::update()
{
    this->pollEvents();

    if(!endGame) {
        this->updateText();
        this->updateMousePos();
        this->updateOX();

    }

    this->updateWinner();


}
void Game::renderFields()
{
    for(auto&e : this->fields) {
        this->window->draw(e);
    }
}

void Game::renderOX()
{
    for(auto&e : gameSigns) {
        window->draw(e);
    }
}

void Game::render()
{

    this->renderFields();
    this->renderOX();
    window->draw(gameText);

    if(endGame == true)
        window->draw(endGameText);

    this->window->display();
}
