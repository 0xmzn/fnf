#include <SFML/Graphics.hpp>
using namespace sf;
const unsigned int WIDTH = 1024;
const unsigned int HEIGHT = 768;
const float WID = 512;
const float HEI = 384;

// 1 --> easy | 500 --> medium | 999 --> hard
int gameLevel = 0;


// Function to handle Events
void handleEvent(RenderWindow& window, Event& event)
{
    while(window.pollEvent(event))
    {
        switch (event.type)
        {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if(Keyboard::isKeyPressed(Keyboard::E)) gameLevel += 1;
                else if (Keyboard::isKeyPressed(Keyboard::M)) gameLevel += 500;
                else if (Keyboard::isKeyPressed(Keyboard::H)) gameLevel += 999;
                else if (Keyboard::isKeyPressed(Keyboard::Escape)) gameLevel = 0;
                else if (Keyboard::isKeyPressed(Keyboard::Q)) window.close();
                break;
        }
    }
}

// Fuction to display the Title in the Main Menu
void displayTitle(RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("font.ttf")){}
    Text title;
    title.setFont(font);
    title.setOutlineThickness(5);
    title.setOutlineColor(Color::Black);
    title.setString("FLAPPY BIRD");
    title.setCharacterSize(130);
    title.setFillColor(Color::White);
    title.setPosition(WID - 365, HEI - 300);
    window.draw(title);
}

// Function to display Menu
void displayMenu(RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("font.ttf")){}
    Text text;
    text.setFont(font);
    text.setOutlineThickness(3);
    text.setOutlineColor(Color::Black);
    text.setString("  E FOR EASY\n\nM FOR MEDIUM\n\n  H FOR HARD");
    text.setCharacterSize(50);
    text.setFillColor(Color::White);
    text.setPosition(WID - 170, HEI - 100);
    window.draw(text);
}

// Function to display Background
// We could add a string parameter to the function to chose which bg to draw
void displayBg(RenderWindow& window)
{
    Texture backgroundImage;
    backgroundImage.loadFromFile("bg.png");
    Sprite bg(backgroundImage);
    window.draw(bg);
}

// Function to display the bird in the main menu
void displayIntroBird(RenderWindow& window)
{
    Texture bird;
    bird.loadFromFile("bird.png");
    Sprite flappyBird(bird);
    flappyBird.setPosition(WID - 50, HEI + 200);
    flappyBird.setScale(3.0f, 3.0f);
    window.draw(flappyBird);
}

int main()
{
    // Create a window
    RenderWindow window(VideoMode(WIDTH,HEIGHT), "SFML" , Style::Close);

    // Game Loop
    while(window.isOpen())
    {
        Event event{};
        handleEvent(window, event);

        // Case easy
        if( gameLevel == 1)
        {

        }
        // Case Medium
        else if(gameLevel == 500)
        {

        }
        // Case Hard
        else if(gameLevel == 999)
        {

        }
        // Case user pressed escape it returns to the main menu
        else if (gameLevel == 0)
        {
            window.clear();
            displayBg(window);
            displayTitle(window);
            displayMenu(window);
            displayIntroBird(window);
            window.display();
        }
    }
    return 0;
}

