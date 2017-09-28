#include "Manager.h"



Manager::Manager()
{
	janela = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Musician's War");

	imgMenu.m_textura.loadFromFile("Assets/LogoMenu.png");
	imgMenu.m_rect.setTexture(&imgMenu.m_textura);
	imgMenu.dimensaoImgFonte = { 0,0,450,250 };
	imgMenu.m_rect.setTextureRect(imgMenu.dimensaoImgFonte);
	imgMenu.m_rect.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	imgMenu.m_rect.setPosition(0, 0);

	somMenu.music.openFromFile("Assets/MusicaJao.wav");
	somMenu.music.play();
	somMenu.music.setPlayingOffset(sf::seconds(10));
	somMenu.music.setLoop(true);

	imgJogar.m_textura.loadFromFile("Assets/Jogar.png");
	imgJogar.m_rect.setTexture(&imgJogar.m_textura);
	imgJogar.dimensaoImgFonte = { 0,0,300,150 };
	imgJogar.m_rect.setTextureRect(imgJogar.dimensaoImgFonte);
	imgJogar.m_rect.setSize(sf::Vector2f(300, 150));
	imgJogar.m_rect.setPosition(100, 558);

	imgCJogar.m_textura.loadFromFile("Assets/ComoJogar.png");
	imgCJogar.m_rect.setTexture(&imgCJogar.m_textura);
	imgCJogar.dimensaoImgFonte = { 0,0,300,150 };
	imgCJogar.m_rect.setTextureRect(imgCJogar.dimensaoImgFonte);
	imgCJogar.m_rect.setSize(sf::Vector2f(300, 150));
	imgCJogar.m_rect.setPosition(900, 558);

	imgJogo.m_textura.loadFromFile("Assets/Cenario.png");
	imgJogo.m_rect.setTexture(&imgJogo.m_textura);
	imgJogo.dimensaoImgFonte = { 0,0,100,100 };
	imgJogo.m_rect.setTextureRect(imgJogo.dimensaoImgFonte);
	imgJogo.m_rect.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	imgJogo.m_rect.setPosition(0, 0);


	imgJose1.m_textura.loadFromFile("Assets/Joseparado.png");
	imgJose1.m_rect.setTexture(&imgJose1.m_textura);
	imgJose1.dimensaoImgFonte = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
	imgJose1.m_rect.setTextureRect(imgJose1.dimensaoImgFonte);
	imgJose1.m_rect.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	imgJose1.m_rect.setPosition(0, 0);
	imgJose1.m_rect.setPosition(0, 500);

}


	Manager::~Manager()
	{
		delete janela;
	}

void Manager::Programa()
{
	while (quit == false)
	{
		Inputs();
		Update();
		Render();
	}
}

void Manager::Inputs()
{
	while (janela->pollEvent(eventos))
	{
		posicaoMouse = sf::Mouse::getPosition(*janela);
		switch (eventos.type)
		{
		case sf::Event::Closed:
			quit = true;
			break;
		case sf::Event::KeyPressed:
			InputTeclado();
			break;
		case sf::Event::MouseButtonPressed:
			MouseClicado();
			break;
		case sf::Event::MouseMoved:
			MouseMovido();
			break;
		}
	}
}

void Manager::Update()
{
	switch (estadoTela)
	{
	case MENU:
		UpdateMenu();
		break;
		
	case JOGO:
		UpdateJogo();
		break;

	case GAMEOVER:
		UpdateGameOver();
		break;
	}
}

void Manager::Render()
{
	janela->clear();
	switch (estadoTela)
	{
	case MENU:
		RenderMenu();
		break;

	case JOGO:
		RenderJogo();
		break;

	case GAMEOVER:
		RenderGameOver();
		break;
	}
	janela->display();
}

void Manager::UpdateMenu()
{

}

void Manager::UpdateJogo()
{

}

void Manager::UpdateGameOver()
{

}

void Manager::RenderMenu()
{
	janela->draw(imgMenu.m_rect);
	janela->draw(imgJogar.m_rect);
	janela->draw(imgCJogar.m_rect);
	if (clock.getElapsedTime().asSeconds() > 0.2f) {
		if (imgMenu.dimensaoImgFonte.top == 500)
			imgMenu.dimensaoImgFonte.top = 0;
		else
			imgMenu.dimensaoImgFonte.top += 250;

		imgMenu.m_rect.setTextureRect(imgMenu.dimensaoImgFonte);
		clock.restart();

	}

}

void Manager::RenderJogo()
{
	janela->draw(imgJogo.m_rect);
	janela->draw(imgJose1.m_rect);
	janela->draw(imgRicardao.m_rect);
	janela->draw(ataqueJ.m_rect);
}

void Manager::RenderGameOver()
{

}

void Manager::InputTeclado()
{
	switch (eventos.key.code)
	{
		case sf::Keyboard::Escape:
			if (estadoTela == MENU) 
				quit = true;
			if (estadoTela == JOGO) {
				somJogo.music.stop();
				m = 0;
				somMenu.music.play();
				somMenu.music.setPlayingOffset(sf::seconds(10));
				somMenu.music.setLoop(true);
				estadoTela = MENU;
			}
			break;

		case sf::Keyboard::Return:
			if (estadoTela == MENU) {

				somMenu.music.stop();
				estadoTela = JOGO;
				somJogo.music.openFromFile("Assets/Um ritmo legal.wav");
				somJogo.music.play();
				somJogo.music.setLoop(true);
			}
			break;


		case sf::Keyboard::P:
			if (estadoTela == MENU) {
				if (m == 0) {
					somMenu.music.pause();
					m = 1;
				}
				else {
					somMenu.music.play();
					m = 0;
				}
			}
			break;


		case sf::Keyboard::D:
			if (estadoTela == JOGO) {
				if (imgJose1.dimensaoImgFonte.left <= -1180) 
					imgJose1.dimensaoImgFonte.left -= 0;
				else {
					if (t == 0) {
						imgJose1.m_textura.loadFromFile("Assets/Joseandando1.png");
						imgJose1.dimensaoImgFonte.left -= 8;
					}
					if (t == 1) {
						imgJose1.m_textura.loadFromFile("Assets/Joseandando2.png");
						imgJose1.dimensaoImgFonte.left -= 8;
					}
					if (t == 2) {
						imgJose1.m_textura.loadFromFile("Assets/Joseandando3.png");
						imgJose1.dimensaoImgFonte.left -= 8;
					}
					if (t == 3) {
						imgJose1.m_textura.loadFromFile("Assets/Joseandando2.png");
						imgJose1.dimensaoImgFonte.left -= 8;
					}
					if (clock.getElapsedTime().asSeconds() > 0.1f) {
						if (t == 3)
							t = 0;
						else
							t += 1;
						imgJose1.m_rect.setTextureRect(imgJose1.dimensaoImgFonte);
						clock.restart();
					}
				}
				imgJose1.m_rect.setTextureRect(imgJose1.dimensaoImgFonte);
				break;
			}

		case sf::Keyboard::A:
			if (estadoTela == JOGO) {
				if (imgJose1.dimensaoImgFonte.left >= 50) 
					imgJose1.dimensaoImgFonte.left += 0;
				else {
					if (t == 0) {
						imgJose1.m_textura.loadFromFile("Assets/Joseandando4.png");
						imgJose1.dimensaoImgFonte.left += 8;
					}
					if (t == 1) {
						imgJose1.m_textura.loadFromFile("Assets/Joseandando5.png");
						imgJose1.dimensaoImgFonte.left += 8;
					}
					if (t == 2) {
						imgJose1.m_textura.loadFromFile("Assets/Joseandando6.png");
						imgJose1.dimensaoImgFonte.left += 8;
					}
					if (t == 3) {
						imgJose1.m_textura.loadFromFile("Assets/Joseandando5.png");
						imgJose1.dimensaoImgFonte.left += 8;
					}
					if (clock.getElapsedTime().asSeconds() > 0.1f) {
						if (t == 3)
							t = 0;
						else
							t += 1;
						imgJose1.m_rect.setTextureRect(imgJose1.dimensaoImgFonte);
						clock.restart();
					}
				}
				imgJose1.m_rect.setTextureRect(imgJose1.dimensaoImgFonte);
				break;
			}		
	}
}

void Manager::MouseClicado()
{
	switch (eventos.mouseButton.button)
	{
	case sf::Mouse::Left: //Mouse Botao Esquerdo Pressionado
		ataqueJ.m_textura.loadFromFile("Assets/Nota 2.png");
		ataqueJ.m_rect.setTexture(&ataqueJ.m_textura);
		ataqueJ.dimensaoImgFonte = { 0,0,32,32 };
		ataqueJ.m_rect.setTextureRect(ataqueJ.dimensaoImgFonte);
		ataqueJ.m_rect.setSize(sf::Vector2f(32,32));
		ataqueJ.m_rect.setPosition(imgJose1.m_rect.getPosition());
		break;	

	case sf::Mouse::Right: //Mouse Botao Direito Pressionado
		break;
	}
}

void Manager::MouseMovido()
{
}
