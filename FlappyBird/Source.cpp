#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>

//variable declaration
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCREEN_TITLE "Flappy Bird"
#define BIRDSIZE 30
#define PIPE_WIDTH 100
#define PIPE_HEIGHT 400
#define COLOR_BACKGROUND sf::Color(255, 255, 255)
#define GRAVITY 1
#define JUMP -15



int speed = 0;
int scores = 0;
bool falling = false;
bool gameOver = false;
bool started = false;
int birdPosX = SCREEN_WIDTH / 4;
int birdPosY = SCREEN_HEIGHT / 2;   

struct Pipe
{
    int x;
    int y;
    int width = PIPE_WIDTH;
    int height = PIPE_HEIGHT;
};

//bird
sf::Texture birdImage1;
sf::Texture birdImage2;
sf::RectangleShape bird(sf::Vector2f(BIRDSIZE, BIRDSIZE));

//storing the pipes
std::vector<Pipe> pipes;



//drawing the bird
void drawBird(sf::RenderWindow& window)
{
	bird.setFillColor(sf::Color::Green);
	bird.setPosition(birdPosX, birdPosY);
	window.draw(bird);
}


void checkOutOfBound()
{
	if (birdPosY < 0) {
		birdPosY = 0;
	}
	if (birdPosY > SCREEN_HEIGHT - BIRDSIZE) {
        gameOver = true;
	}
}

void checkCollision() {
	for (int i = 0; i < pipes.size(); i++) {
		if (birdPosX + BIRDSIZE > pipes[i].x && birdPosX < pipes[i].x + PIPE_WIDTH) {
			if (birdPosY < pipes[i].y + PIPE_HEIGHT || birdPosY + BIRDSIZE > pipes[i].y + PIPE_HEIGHT + 200) {
				gameOver = true;
			}
		}
	}
}


void drawPipes(sf::RenderWindow& window) {

    for (int i = 0; i < pipes.size(); i++) {

        sf::RectangleShape pipeUp(sf::Vector2f(pipes[i].width, pipes[i].height));
        pipeUp.setFillColor(sf::Color::Red);
        pipeUp.setPosition(pipes[i].x, pipes[i].y);
        window.draw(pipeUp);
        sf::RectangleShape pipeDown(sf::Vector2f(pipes[i].width, pipes[i].height));
        pipeDown.setFillColor(sf::Color::Red);
        pipeDown.setPosition(pipes[i].x, pipes[i].y + pipes[i].height + 200);
        window.draw(pipeDown);
    }
}


void removePipes() {
    for (int i = 0; i < pipes.size(); ++i) {
        if (pipes.size() > 0 && pipes[i].x < -PIPE_WIDTH) {
            pipes.erase(pipes.begin() + i);
        }
    }
}

void updatePipes() {
    for (int i = 0; i < pipes.size(); i++) {
        pipes[i].x -= 5;
    }
    removePipes();
}

void loadImages() {
	if (!birdImage1.loadFromFile("jumpingUpp.png")) {
		std::cout << "Error loading bird image" << std::endl;
	}
	if (!birdImage2.loadFromFile("jumpingUp.png")) {
		std::cout << "Error loading bird image" << std::endl;
	}
}



int main()
{
    loadImages();

	sf::Sprite birdSprite;

    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        if (speed < 0) {
			birdSprite.setTexture(birdImage1);
		}
        else {
            birdSprite.setTexture(birdImage2);
        }

        sf::Time elapsed = clock.getElapsedTime();
        if (elapsed.asSeconds() > 1.5 && started) {
            Pipe pipe;
            pipe.x = SCREEN_WIDTH;
            pipe.y = rand() % (SCREEN_HEIGHT - 400) - 300;
            pipes.push_back(pipe);
            clock.restart();
            scores++;

            std::cout << scores << std::endl;
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    speed = JUMP;g
                    falling = true;
                    if (!started) {
                        started = true;
                    }
                }
            }
        }

        if (falling) {
            speed += GRAVITY;
            birdPosY += speed;
        }

        if (gameOver) {
            birdPosY = SCREEN_HEIGHT / 2;
            pipes.clear();
            falling = false;
            gameOver = false;
            started = false;
            scores = 0;
        }

        if (started) {
            checkCollision();
            checkOutOfBound();
            updatePipes();
        }

        window.clear(COLOR_BACKGROUND);
        
        drawPipes(window);
		birdSprite.setPosition(birdPosX, birdPosY);
		window.draw(birdSprite);
        window.display();
    }

    return 0;
}

