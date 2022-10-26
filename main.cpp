#include "Minesweeper.h"
#include "MSTextBoardView.h"
#include "MinesweeperBoard.h"
#include "Variables.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>

int main()
{
    sf::Font FONT;
    FONT.loadFromFile("arial.ttf");
    int etap = 0, zapis = 0;
    int width = 10, height = 10, level = 3;
    time_t start, end;

    Minesweeper m1(10, 10, 2);

    sf::Texture texture1; sf::Sprite one; texture1.loadFromFile("Sprites\\one.png"); one.setTexture(texture1);
    sf::Texture texture2; sf::Sprite two; texture2.loadFromFile("Sprites\\two.png"); two.setTexture(texture2);
    sf::Texture texture3;sf::Sprite three; texture3.loadFromFile("Sprites\\three.png"); three.setTexture(texture3);
    sf::Texture texture4;sf::Sprite four; texture4.loadFromFile("Sprites\\four.png"); four.setTexture(texture4);
    sf::Texture texture5;sf::Sprite five; texture5.loadFromFile("Sprites\\five.png"); five.setTexture(texture5);
    sf::Texture texture6;sf::Sprite six; texture6.loadFromFile("Sprites\\six.png"); six.setTexture(texture6);
    sf::Texture texture7;sf::Sprite seven; texture7.loadFromFile("Sprites\\seven.png"); seven.setTexture(texture7);
    sf::Texture texture8;sf::Sprite eight; texture8.loadFromFile("Sprites\\eight.png"); eight.setTexture(texture8);
    sf::Texture texture9;sf::Sprite close; texture9.loadFromFile("Sprites\\zamkniete.png"); close.setTexture(texture9);
    sf::Texture texture10;sf::Sprite settings; texture10.loadFromFile("Sprites\\ustawienia.png"); settings.setTexture(texture10);
    sf::Texture texture11;sf::Sprite Flag; texture11.loadFromFile("Sprites\\flaga.png"); Flag.setTexture(texture11);
    sf::Texture texture12;sf::Sprite clear; texture12.loadFromFile("Sprites\\puste.png"); clear.setTexture(texture12);
    sf::Texture texture13;sf::Sprite Back; texture13.loadFromFile("Sprites\\Cofnij.png"); Back.setTexture(texture13);
    sf::Texture texture14;sf::Sprite LastScore; texture14.loadFromFile("Sprites\\Wyniki.png"); LastScore.setTexture(texture14);
    sf::Texture texture15;sf::Sprite Mina; texture15.loadFromFile("Sprites\\mina.png"); Mina.setTexture(texture15);
    sf::Texture texture16;sf::Sprite Stopka; texture16.loadFromFile("Sprites\\stopka.png"); Stopka.setTexture(texture16);


    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

            if (event.type == sf::Event::Resized)
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }

            if(event.type==sf::Event::MouseButtonPressed)
            {
                switch (event.mouseButton.button)
                {
                    case sf::Mouse::Left: {
                        if(etap == 1)
                        {
                            int width1 = sf::Mouse::getPosition(window).x / ROZMIAR;
                            int height1 = sf::Mouse::getPosition(window).y / ROZMIAR;
                            if(m1.GetGameField(width1, height1).hasMine == true) etap = 3;
                            m1.RevelFields(width1, height1);
                            if(m1.getReveledField() == m1.getWidth()*m1.getHeight()-m1.getBombs()) etap = 4;
                        }
                        if(etap == 0) {
                            int width1 = sf::Mouse::getPosition(window).x;
                            int height1 = sf::Mouse::getPosition(window).y;
                            if (width1 > 0 && width1 < 500 * ROZMIAR_START) {
                                if (height1 > 0 && height1 < 100 * ROZMIAR_START) {
                                    m1.setWidth(width);
                                    m1.setHeight(height);
                                    m1.setLevel(level);
                                    m1.setBombs();
                                    m1.GenereteMines();
                                    m1.countMines();
                                    etap = 1;
                                    start = clock();
                                }
                            }

                            if(width1 > 0 && width1 < 250*ROZMIAR_START)
                            {
                                if(height1 > 150*ROZMIAR_START && height1 < 250*ROZMIAR_START)
                                {
                                    if(level > MIN_LEVEL) level--;
                                }
                                if(height1 > 300*ROZMIAR_START && height1 < 400*ROZMIAR_START)
                                {
                                    if(width > MIN_WIDTH) width--;
                                }
                                if(height1 > 450*ROZMIAR_START && height1 < 550*ROZMIAR_START)
                                {
                                    if(height > MIN_HEIGHT) height--;
                                }
                            }
                            else if(width1>250*ROZMIAR_START && width1 < 500*ROZMIAR_START)
                            {
                                if(height1 > 150*ROZMIAR_START && height1 < 250*ROZMIAR_START)
                                {
                                    if(level < MAX_LEVEL) level++;
                                }
                                if(height1 > 300*ROZMIAR_START && height1 < 400*ROZMIAR_START)
                                {
                                    if(width < MAX_WIDTH) width++;
                                }
                                if(height1 > 450*ROZMIAR_START && height1 < 550*ROZMIAR_START)
                                {
                                    if(height < MAX_WIDTH) height++;
                                }
                            }
                            if(width1>0 && width1 < 500*ROZMIAR_START)
                            {
                                if(height1 > 550)
                                {
                                    etap = 5;
                                }
                            }

                        }

                        if(etap == 5)
                        {
                            int width1 = sf::Mouse::getPosition(window).x;
                            int height1 = sf::Mouse::getPosition(window).y;
                            if(width1>0 && width1 < 297*1.5)
                            {
                                if(height1 <30)
                                {
                                    etap = 0;
                                }
                            }
                        }

                        break;
                    }
                    case sf::Mouse::Right: {
                        if(etap == 1)
                        {
                            int width1 = sf::Mouse::getPosition(window).x / ROZMIAR;
                            int height1 = sf::Mouse::getPosition(window).y / ROZMIAR;
                            m1.setFlag(width1, height1);
                        }
                        break;
                    }

                }
            }

        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        if(etap == 5)
        {
            window.setSize(sf::Vector2u(1000*ROZMIAR_START, 500*ROZMIAR_START));
            sf::Texture texture17;
            texture17.loadFromFile("Sprites\\cofnij.png");
            sf::Sprite cofnij;
            cofnij.setTexture(texture17);
            cofnij.setPosition(0, 0);
            cofnij.setScale(1.5,1);

            std::fstream plik;
            plik.open("baza.txt", std::ios::in);
            if(plik.good()==true)
            {
                int iteracja = 0;
                std::string linia, linia1, linia2, linia3;
                while(!plik.eof())
                {
                    std::getline(plik, linia);
                    std::getline(plik, linia1);
                    std::getline(plik, linia2);
                    std::getline(plik, linia3);
                    sf::Text text("Szerokosc: " + linia + " Wysokosc: " + linia1 + " Level: " + linia2 + " Czas: " + linia3, FONT, 30);
                    iteracja++;
                    text.setPosition(0, 30+iteracja * 40);
                    window.draw(text);
                }
            }

            window.draw(cofnij);
        }

        if(etap == 3 || etap == 4)
        {
            sf::Font FONT;
            FONT.loadFromFile("arial.ttf");

            if(etap == 3){ sf::Text text("Przegrales", FONT, 30); window.draw(text);}
            if(etap == 4){ sf::Text text("Wygrales", FONT, 30); window.draw(text);}

            if(etap == 4 && zapis == 0)
            {
                end = clock();
                double czas1;
                czas1 = (double)(end-start)/CLOCKS_PER_SEC;
                std::string czas_str = std::to_string(czas1);
                czas_str.resize(4);
                std::fstream plik;
                plik.open("baza.txt", std::ios::out | std::ios::app);
                if(plik.good()==true)
                {
                    plik << std::endl;
                    plik << m1.getWidth();
                    plik << std::endl;
                    plik << m1.getHeight();
                    plik << std::endl;
                    plik << m1.getLevel();
                    plik << std::endl;
                    plik << czas_str;
                }
                zapis = 1;
                plik.close();
            }


        }

        if(etap == 0)
        {
            sf::Sprite actual;
            window.setSize(sf::Vector2u(500, 666));
            actual.setTexture(texture10);
            actual.setScale(sf::Vector2f(ROZMIAR_START, ROZMIAR_START));
            window.draw(actual);

            sf::Font FONT;
            FONT.loadFromFile("arial.ttf");
            sf::Text LEVEL(std::to_string(level), FONT, 50);   LEVEL.setPosition(sf::Vector2f(200*ROZMIAR_START, 170*ROZMIAR_START));
            sf::Text WIDTH(std::to_string(width), FONT, 50); WIDTH.setPosition(sf::Vector2f(200*ROZMIAR_START, 320*ROZMIAR_START));
            sf::Text HEIGHT(std::to_string(height), FONT, 50); HEIGHT.setPosition(sf::Vector2f(200*ROZMIAR_START, 480*ROZMIAR_START));

            window.draw(LEVEL);
            window.draw(WIDTH);
            window.draw(HEIGHT);

        }

        if(etap==1)
        {
        window.setSize(sf::Vector2u(m1.getWidth()*ROZMIAR, m1.getHeight()*ROZMIAR + 50));
        for(int i=0; i<m1.getWidth(); i++)
        {
            for(int j=0; j<m1.getHeight(); j++)
            {
                sf::Sprite actual;
                if(m1.GetGameField(i, j).hasFlag == true) actual.setTexture(texture11);
                else if(m1.GetGameField(i, j).isReveled == false) actual.setTexture(texture9);
                else if(m1.GetGameField(i, j).isReveled == true)
                {
                    if(m1.GetGameField(i, j).bombsArround == -1) actual.setTexture(texture15);
                    if(m1.GetGameField(i, j).bombsArround == 0) actual.setTexture(texture12);
                    if(m1.GetGameField(i, j).bombsArround == 1) actual.setTexture(texture1);
                    if(m1.GetGameField(i, j).bombsArround == 2) actual.setTexture(texture2);
                    if(m1.GetGameField(i, j).bombsArround == 3) actual.setTexture(texture3);
                    if(m1.GetGameField(i, j).bombsArround == 4) actual.setTexture(texture4);
                    if(m1.GetGameField(i, j).bombsArround == 5) actual.setTexture(texture5);
                    if(m1.GetGameField(i, j).bombsArround == 6) actual.setTexture(texture6);
                    if(m1.GetGameField(i, j).bombsArround == 7) actual.setTexture(texture7);
                    if(m1.GetGameField(i, j).bombsArround == 8) actual.setTexture(texture8);
                }

                float dzielnik = ROZMIAR/20;
                float positionx = i*ROZMIAR;
                float positiony = j*ROZMIAR;

                actual.scale(dzielnik, dzielnik);
                actual.setPosition(sf::Vector2f(positionx, positiony));
                window.draw(actual);
            }
        }
        end = clock();
        Stopka.setPosition(0, m1.getHeight()*ROZMIAR);
        Stopka.setScale(0.2*m1.getWidth(), 1);
        window.draw(Stopka);

        double czas1;
        czas1 = (double)(end-start)/CLOCKS_PER_SEC;
        std::string czas_str = std::to_string(czas1);
        czas_str.resize(4);

        sf::Text czas("Czas: " + czas_str, FONT, 40);
        czas.setPosition(50, m1.getHeight()*ROZMIAR);
        window.draw(czas);
    }
        window.display();
    }

    return 0;
}
