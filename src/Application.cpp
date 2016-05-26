/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Application.cpp
 * Author: aalmunia
 * 
 * Created on May 26, 2016, 2:14 PM
 */

#include "../include/Application.h"

Application::Application() {
}

Application::Application(const Application& orig) {
}

Application::Application(unsigned int iWidth, unsigned int iHeight, std::string sName) {
    this->iWindowWidth = iWidth;
    this->iWindowHeight = iHeight;
    this->sWindowName = sName;
}

Application::Application(unsigned int iWidth, unsigned int iHeight, char* sName) {
    if(sName == NULL) {
        // throw ERROR
    } else {
        this->sWindowName = std::string(sName);
        this->iWindowWidth = iWidth;
        this->iWindowHeight = iHeight;
    }
}

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

bool Application::isAppInit() {
    return bInit;
}

void Application::initApp() {
    al_init();
    al_install_mouse();
    al_install_keyboard();
    
    this->pDisplay = al_create_display(this->iWindowWidth, this->iWindowHeight);
    if(this->pDisplay != NULL) {
        al_set_window_title(this->pDisplay, this->sWindowName.c_str());
        this->bInit = true;
        this->initColors();
        // ALLEGRO_BITMAP *oBitmap = al_create_bitmap(250, 250);
        al_clear_to_color(this->colRed);
        std::cout << "Initialized OK" << std::endl;
        while(true) {
            // al_clear_to_color(this->colRed);
            al_flip_display();
            /* al_clear_to_color(this->colBlue);
            al_flip_display();
            al_clear_to_color(this->colGreen);
            al_flip_display(); */
        }
    }
}

void Application::initColors() {
    this->colRed = al_map_rgb(255, 0, 0);
    this->colGreen = al_map_rgb(0, 255, 0);
    this->colBlue = al_map_rgb(0, 0, 255);
}

Application::~Application() {
    if(this->pDisplay != NULL) {
        al_destroy_display(this->pDisplay);
    }
}

