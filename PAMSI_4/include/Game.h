#ifndef GAME_H
#define GAME_H
#include<iostream>
#include<vector>
#include <algorithm>
#include<sstream>
#include<SFML/Graphics.hpp>
#include<climits>


class Game
{

private:
    sf::RenderWindow* window;
    sf::Event event;
    sf::Texture tekstura1, tekstura2;
    sf::Sprite x, o;
    sf::RectangleShape field;
    sf::Font font;
    sf::Text endGameText, gameText;
    std::vector<sf::RectangleShape> fields;
    int Size, Mode, MovToWin, MaxDepth;
    sf::Vector2i mousePosWin;
    sf::Vector2f mousePosView;
    std::vector<sf::Sprite> gameSigns;
    bool endGame;
    char turn;
    std::vector<std::vector<char>> plansza;
    std::vector<char> pola;

    void initOX();
    void initVar();
    void initWindow();
    void initFields();
    void initText();

public:
    Game(int size, int mode, int movToWin);
    virtual ~Game();
    const bool running();
    const bool & getEndGame() const;
    int checkWinner();
    bool isMovesleft();
    int MinMax(int depth, bool isMax, char player, int alpha, int beta);
    std::vector<int> FindBestMove(char player);
    void pollEvents();
    void updateMousePos();
    void updateOX();
    void updateWinner();
    void updateText();
    void update();
    void renderFields();
    void renderOX();
    void render();


};

#endif // GAME_H
