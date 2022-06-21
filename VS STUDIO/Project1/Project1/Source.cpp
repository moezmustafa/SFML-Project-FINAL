//fucking SFML
#include<iostream>

#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf; 

int WindowWidth = 800;
int WindowHeight = 600;




class PlayerClass {


public : 

    bool PlayerFaceRight;

    float xValue;
    float yValue;
    float xPos; 
    float yPos;
        
    PlayerClass() {
            
   
            cout << "You are inside the player class of this code " << endl;

            PlayerFaceRight = true;
            xPos = 0; 
            yPos = 0;
            xValue = 0; 
            yValue = 0; 

        }

    void Update( bool PlayerUp, bool PlayerDown, bool PlayerRight, bool PlayerLeft  )
    {
        if (PlayerRight)
        {
            PlayerFaceRight = true; 

            xValue = -2;
        }
        if (PlayerLeft)
        {
            PlayerFaceRight = false;
            xValue = 2;
        }

        if (PlayerUp)
        {
            yValue = -2;
        }
        if (PlayerDown)
        {
            yValue = 2;
        }


        if (!(PlayerRight || PlayerLeft))
        {
            xValue = 0;
        }
        if(!(PlayerUp || PlayerDown))
        {
            yValue = 0;
        }

        xPos += xValue;
        yPos += yValue;

       // cout << xValue << endl;
       // cout << yValue << endl;

        cout << xPos << endl;
        cout << yPos << endl;


    }
        
};


int main()
{



    RenderWindow window(VideoMode(WindowWidth,WindowHeight), "SFML works!");
   // CircleShape shape(100.f);
    //shape.setFillColor(Color::Blue);

    bool PlayerUp, PlayerDown, PlayerLeft, PlayerRight;
    PlayerClass PlayerObject;




    // Loading The Texture Files 
    Texture apple;
    apple.loadFromFile("C:/Users/moeez/Desktop/SFML Project FINAL/VS STUDIO/Project1/Project1/apple.png");
    Sprite appleSprite(apple);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        /*window.clear();
        window.draw(apple);
        window.display();*/


        //While shit is being pressed 
        //While shit is being pressed 
        //While shit is being pressed 
        if (Keyboard::isKeyPressed(Keyboard::Right)) PlayerRight = true;
        if (Keyboard::isKeyPressed(Keyboard::Left)) PlayerLeft = true;
        if (Keyboard::isKeyPressed(Keyboard::Up)) PlayerUp = true;
        if (Keyboard::isKeyPressed(Keyboard::Down)) PlayerDown = true;

        //While shit is not being pressed
        //While shit is not being pressed
        //While shit is not being pressed
        if (!(Keyboard::isKeyPressed(Keyboard::Right))) PlayerRight = false;
        if (!(Keyboard::isKeyPressed(Keyboard::Left))) PlayerLeft = false;
        if (!(Keyboard::isKeyPressed(Keyboard::Up))) PlayerUp = false;
        if (!(Keyboard::isKeyPressed(Keyboard::Down))) PlayerDown = false;



        PlayerObject.Update(PlayerUp, PlayerDown, PlayerLeft, PlayerRight );


        //INPUT TESTER CODE LINES XD i hate this 
        //INPUT TESTER CODE LINES XD i hate this 
        //INPUT TESTER CODE LINES XD i hate this 
       /* cout << PlayerDown << endl;
        cout << PlayerUp << endl;
        cout << PlayerRight << endl;
        cout << PlayerLeft << endl;*/
        //INPUT TESTER CODE LINES XD i hate this 
        //INPUT TESTER CODE LINES XD i hate this 
        //INPUT TESTER CODE LINES XD i hate this 




        


        //clearing the screen 
        window.clear();
        
        window.draw(appleSprite);
        appleSprite.move(Vector2f(PlayerObject.xValue,PlayerObject.yValue));
        //Draw the sprite 
        

        //update the window
        window.display();
    }

    return 0;
}