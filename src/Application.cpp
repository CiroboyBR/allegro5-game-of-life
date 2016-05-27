/* 
 * File:   Application.cpp
 * Author: aalmunia
 * 
 * Created on May 26, 2016, 2:14 PM
 */

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/Application.h"

/**
 * Default empty constructor
 */
Application::Application() {
}

/**
 * Default copy-constructor
 * @param orig The Application object to be copied
 */
Application::Application(const Application& orig) {
}

/**
 * Constructor for Application class.
 * @param iWidth Width of the window
 * @param iHeight Height of the window
 * @param sName Title of the window
 */
Application::Application(unsigned int iWidth, unsigned int iHeight, std::string sName) {
    this->iWindowWidth = iWidth;
    this->iWindowHeight = iHeight;
    this->sWindowName = sName;
}

/**
 * Another constructor, uses char* instead of std::string for the name param
 * @param iWidth Width of the window
 * @param iHeight Height of the window
 * @param sName Title to show in the window
 */
Application::Application(unsigned int iWidth, unsigned int iHeight, char* sName) {
    if(sName == NULL) {
        // throw ERROR
    } else {
        this->sWindowName = std::string(sName);
        this->iWindowWidth = iWidth;
        this->iWindowHeight = iHeight;
    }
}

/**
 * This methods tells us if all of the internal objects of the Application class
 * have been initialized and the class is ready to be used.
 * @return true/false
 */
bool Application::isAppReady() {
    bool bReady = true;
    if(this->iWindowWidth == 0) {
        bReady = false;
    }
    if(this->iWindowHeight == 0) {
        bReady = false;
    }
    if(this->sWindowName.empty() == true) {
        bReady = false;
    }
    return bReady;
}

/**
 * When the application has been launched and the window has been created, this
 * method returns true, and false otherwise
 * @return true/false
 */
bool Application::isAppInit() {
    return bInit;
}

/**
 * Method that initializes the Allegro library, along with the rest of the objects
 * needed to use the class.
 */
void Application::initApp() {
    
    /* al_init();
    al_install_mouse();
    al_install_keyboard();
    al_init_image_addon(); */
    
    /* std::string sFilePath = "/home/aalmunia/CodeTesting/cpp/Life/resources/mysha.pcx";
    
    ALLEGRO_BITMAP *pBitmap = al_load_bitmap(sFilePath.c_str());
    if(!pBitmap) {
        std::cout << "The file " << sFilePath << " has not been loaded correctly" << std::endl;
    } else {
        std::cout << "The file " << sFilePath << " has been correctly opened" << std::endl;
    } */
    
    this->pDisplay = al_create_display(this->iWindowWidth, this->iWindowHeight);
    
    
    
    if(this->pDisplay != NULL) {
        al_set_window_title(this->pDisplay, this->sWindowName.c_str());
        this->bInit = true;
        this->initColors();        
        al_clear_to_color(this->colRed);
        std::cout << "Initialized OK" << std::endl;
        while(true) {
            al_flip_display();            
        }
    }
}

/**
 * This method initializes the color objects we will be using in the application
 */
void Application::initColors() {
    this->colRed = al_map_rgb(255, 0, 0);
    this->colGreen = al_map_rgb(0, 255, 0);
    this->colBlue = al_map_rgb(0, 0, 255);
}

/**
 * Application destructor (~ctor)
 */
Application::~Application() {
    if(this->pDisplay != NULL) {
        al_destroy_display(this->pDisplay);
    }
}