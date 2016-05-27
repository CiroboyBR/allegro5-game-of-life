/* 
 * File:   main.cpp
 * Author: aalmunia
 *
 * Created on May 26, 2016, 2:01 PM
 */

#include <cstdlib>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "include/Application.h"
#include "include/Bitmap.h"

int main(int argc, char** argv) {
    
    /**
     * IMPORTANT: We must invoke al_install_* / al_init_* before we begin using 
     * ALLEGRO objects, otherwise we get a Segmentation Fault on trying to call
     * al_load_bitmap() and others.
     * Find out why, i would like to encapsulate the bootstrapping of the library
     * somehow.
     */
    
    al_init();
    al_install_mouse();
    al_install_keyboard();
    al_init_image_addon();
    
    std::string sName = "Allegro 5 test application";
    Application *oApp = new Application(500, 500, sName);
    
    std::string sBitmapName = "/home/aalmunia/CodeTesting/cpp/Life/resources/lena512.bmp";
    std::string sExtension = ".bmp";
    Bitmap *oBitmap = new Bitmap();
    oBitmap->setDefaultExtension(sExtension);
    oBitmap->fromFile(sBitmapName);
    oBitmap->toFile("/home/aalmunia/CodeTesting/cpp/Life/girl.bmp");
    
    // Once here, the eternal loop starts and does not end until we exit the program
    oApp->initApp();
}

