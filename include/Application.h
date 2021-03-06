/* 
 * File:   Application.h
 * Author: aalmunia
 *
 * Created on May 26, 2016, 2:14 PM
 */

#include <allegro5/allegro.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

// Class 'Bitmap'
#include "Bitmap.h"

#ifndef APPLICATION_H
#define APPLICATION_H

class Application {
public:
    Application();
    Application(const Application& orig);
    Application(unsigned int iWidth, unsigned int iHeight, std::string sName);
    Application(unsigned int iWidth, unsigned int iHeight, char* sName);
    bool isAppReady();
    bool isAppInit();
    void initApp();
    virtual ~Application();
private:
    ALLEGRO_DISPLAY *pDisplay = NULL;
    unsigned int iWindowWidth = 0;
    unsigned int iWindowHeight = 0;
    std::string sWindowName;
    bool bInit = false;
    ALLEGRO_COLOR colRed;
    ALLEGRO_COLOR colGreen;
    ALLEGRO_COLOR colBlue;
    void initColors();
    std::vector<Bitmap> vecBitmaps;
};

#endif /* APPLICATION_H */

