#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>


#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1280

#define MENU 0
#define JOGO 1
#define GAMEOVER 2

struct Base {
	sf::Texture m_textura;
	sf::RectangleShape m_rect;
	sf::IntRect dimensaoImgFonte;
	sf::Music music;
};

class Manager
{
private: //AQUI VOCÊ CRIA AS VARIÁVEIS
	sf::RenderWindow *janela = nullptr;
	sf::Vector2i posicaoMouse;
	sf::Event eventos;
	sf::Clock clock;
	
	Base imgMenu, somMenu, imgJogar, imgCJogar, imgJogo, imgJose1, imgRicardao, somJogo, ataqueJ;
	int m = 0, t = 0, r = 0, p = 2;
	short estadoTela = MENU;
	bool quit = false;

public:
	Manager();
	~Manager();

	void Programa();

	void Inputs();
	void Update();
	void Render();

	void UpdateMenu();
	void UpdateJogo();
	void UpdateGameOver();

	void RenderMenu();
	void RenderJogo();
	void RenderGameOver();

	void InputTeclado();
	void MouseClicado();
	void MouseMovido();
};

