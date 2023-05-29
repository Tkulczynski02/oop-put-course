#include <SFML/Graphics.hpp> //additional library, which is required to open an jpg/png files
#include <iostream>
#include <stdexcept>

using namespace std;

class ArtGallery {
protected: 
    sf::RenderWindow window; //window to render and open my art objects in my window

public:
    virtual void display() = 0; //clear virtual function. It must be implemented in subclass

    ArtGallery(const string& title, unsigned int width, unsigned int height)
        : window(sf::VideoMode(width, height), title) { //this function constructs an art gallery object and creates a render window with a title, height and width that will be used to create the art object.
    }//VideoMode specifies the screen size and bits per pixel.

    void run() {
        try {
            while (window.isOpen()) {
                sf::Event event;//stores information about events
                while (window.pollEvent(event)) { //fetches the next event from the window's event queue. If any event is available, the inner loop will execute.
                    if (event.type == sf::Event::Closed) {//if type of event is equal to Event::Closed, it closes the window, which we can see in the next line
                        window.close();
                    }//The main purpose of this loop is to check for events such as clicking a window close button that may occur while the program is running. The loop executes as long as the window is open
                }

                window.clear(sf::Color::White); //declaring color of our window
                display();
                window.display(); //call to earlier line, and displaying the window to show our art objects
            }
        } catch (const std::exception& e) {
           cerr << "Exception occurred: " << e.what() << endl; //seeking for and throwing our "exception"
        }
    }
};

class Painting : public ArtGallery { //inheritance
private:
    sf::Texture texture1;
    sf::Sprite sprite1;
    sf::Texture texture2;
    sf::Sprite sprite2;
    sf::Texture texture3;
    sf::Sprite sprite3;
    sf::Texture texture4;
    sf::Sprite sprite4;
    sf::Texture texture5;
    sf::Sprite sprite5;
    sf::Texture texture6;
    sf::Sprite sprite6;
    sf::Texture texture7;
    sf::Sprite sprite7;
    sf::Texture texture8;
    sf::Sprite sprite8;
    sf::Texture texture9;
    sf::Sprite sprite9;
    sf::Texture texture10; //10 objects that are storing inner textures that will be loaded from the appropriate image file in code later
    sf::Sprite sprite10; // 10 sprites that will be used to display 10 different textures on the screen

public:
    Painting(const string& title, unsigned int width, unsigned int height, const string& imageFile1, const string& imageFile2, const string& imageFile3, const string& imageFile4, const string& imageFile5, const string& imageFile6, const string& imageFile7, const string& imageFile8, const string& imageFile9, const string& imageFile10)
        : ArtGallery(title, width, height) { //this is the constructor of the Painting class and is responsible for initializing the class object. When creating a Painting object, the following arguments are taken: title, width, height, imageFile1 etc. These arguments are passed to the ArtGallery base class constructor by initializing with a list ArtGallery(title,width and height)
        
	if (!texture1.loadFromFile(imageFile1)) {
            throw runtime_error("Failed to load image file: " + imageFile1);
        }
        if (!texture2.loadFromFile(imageFile2)) {
            throw runtime_error("Failed to load image file: " + imageFile2);
        }
	if (!texture3.loadFromFile(imageFile3)) {
	    throw runtime_error("Failed to load image file: " + imageFile3);
	}
	if (!texture4.loadFromFile(imageFile4)) {
            throw runtime_error("Failed to load image file: " + imageFile4);
        }
        if (!texture5.loadFromFile(imageFile5)) {
            throw runtime_error("Failed to load image file: " + imageFile5);
        }
        if (!texture6.loadFromFile(imageFile6)) {
            throw runtime_error("Failed to load image file: " + imageFile6);
        }
        if (!texture7.loadFromFile(imageFile7)) {
            throw runtime_error("Failed to load image file: " + imageFile7);
        }
        if (!texture8.loadFromFile(imageFile8)) {
            throw runtime_error("Failed to load image file: " + imageFile8);
        }
        if (!texture9.loadFromFile(imageFile9)) {
            throw runtime_error("Failed to load image file: " + imageFile9);
        }
	if (!texture10.loadFromFile(imageFile10)) { //The loadFromFile() method loads an image from a file and assigns it to a texture.
            throw runtime_error("Failed to load image file: " + imageFile10); //If the file loading operation fails (f.e. file not found), a runtime_error exception is thrown with an appropriate message.
        }
		
        sprite1.setTexture(texture1);
        sprite1.setPosition(0, 0);

        sprite2.setTexture(texture2);
        sprite2.setPosition(200, 0);
        
        sprite3.setTexture(texture3);
        sprite3.setPosition(400, 0);
        
        sprite4.setTexture(texture4);
        sprite4.setPosition(600, 0);
        
        sprite5.setTexture(texture5);
        sprite5.setPosition(830, 0);
        
        sprite6.setTexture(texture6);
        sprite6.setPosition(0, 300);

	sprite7.setTexture(texture7);
        sprite7.setPosition(200, 300);
        
        sprite8.setTexture(texture8);
        sprite8.setPosition(430, 300);
        
        sprite9.setTexture(texture9);
        sprite9.setPosition(630, 300);
        
        sprite10.setTexture(texture10);
        sprite10.setPosition(810, 300); //getting textures from 10 previous ifs and if theres not a single error, setting positions in our window for 10 different pictures, for them to not be all over themselves
    }
        

    virtual void display() override { //display() is a virtual method of the Painting class that has been declared as a pure virtual function in the ArtGallery base class. In the Painting class, this method has been override.The display() function is responsible for displaying images (sprites) in the graphics window
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite3);
        window.draw(sprite4);
        window.draw(sprite5);
        window.draw(sprite6);
        window.draw(sprite7);
        window.draw(sprite8);
        window.draw(sprite9);
        window.draw(sprite10);
    } //In effect, calling this method will display all ten sprites (images) on the screen in the graphics window.
};

int main() {
	cout<<"Troche informacji o jednym z najlepszych malarzy wspolczesnej Polski"<<endl;
	cout<<"Zdzislaw Beksinski urodzony 24 lutego 1929 w Sanoku, a zmarly 21 lutego 2005 w Warszawie. Polski inzynier, architekt,   malarz, rzezbiarz, fotograf, rysownik i artysta fantastyczny poslugujacy sie tez grafika komputerowa"<<endl;
	cout<<"Jako mlody artysta zajmowal sie fotografia, wygrywajac szereg konkursow miedzynarodowych. Dzis Beksinski jest rzadziej  kojarzony z czarno-bialymi zdjeciami, jednak to wlasnie od nich zaczal swoja kariera. Jego fotografie przedstawialy ludz-kie postacie, czesto w niecodziennych pozach - skulone, jakby zaleknione modelki byly owiniete sznurkami, ich ciala    byly zdeformowane lub tak skadrowane, ze bylo widac tylko ich fragmenty. Czesto role modelki na fotografiach odgrywala  jego zona Zofia."<<endl;
   	cout<<"Okolo 1964 roku zaczal malowac. W polowie lat 60. wskazowek udzielal mu sanocki malarz Tadeusz Turkowski, ponadto Beksinski kontaktowal sie z innym sanockim malarzem Bronislawem Naczasem. Zdecydowanie zerwal wowczas z awangarda i w pelni oddal sie malarstwu fantastycznemu, wizjonerskiemu, figuratywnemu, starannie malowanemu farba olejna na plycie pilsniowej. Nigdy nie dawal swoim obrazom tytulow, uznajac, ze kazdy widz moze je interpretowac w dowolny sposob. Pierwszy okres tego malarstwa, pod wplywem mistycyzmu wschodniego, ktoremu wowczas Beksinski holdowal, byl pelen symboli, tajemniczych   tresci i katastroficznej, pelnej grozy atmosfery. Podczas tworzenia obrazow malarskich stosowal jednoczesne sluchanie   muzyki. Artysta tworzyl przy muzyce, glownie neoromantycznej. W jego pracowni w Sanoku znajdowalo sie wiele urzadzen    audio (np. magnetofon)."<<endl;
    try {
        Painting painting("C++ Art Gallery for Zdzislaw Beksinski", 1000, 600, "image1.jpg", "image2.jpg", "image3.jpg", "image4.jpg", "image5.jpg", "image6.jpg", "image7.jpg", "image8.jpg", "image9.jpg", "image10.jpg"); //This code fragment creates a Painting object named painting and initializes it with the Painting constructor, which are: the title, width and height of the window, and 10 paintings
        painting.run(); //painting calls for the most important function in our code, run(), which: controlls closing and opening the window, clears the window content, calls the display() method on the painting object, which draws images (sprites) in the window, and displays the window content
    } catch (const exception& e) {
        cerr << "Exception occurred: " << e.what() << endl;
        return 1;
    }

    return 0;
}

