/* 
 * File:   Bitmap.cpp
 * Author: aalmunia
 * 
 * Created on May 27, 2016, 10:23 AM
 */

#include <iostream>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/Bitmap.h"

/**
 * @TODO: Take a look at how to call a constructor from another constructor
 * in order to always call the base constructor first and initialize the allegro_image
 * library and functionality.
 */

Bitmap::Bitmap() {
    al_init_image_addon();
}

Bitmap::Bitmap(const Bitmap& orig) {
}

void Bitmap::setDefaultExtension(std::string sExtension) {
    this->sDefaultExtension = sExtension;
}

void Bitmap::fromFile(std::string sFilePath) {
    
    std::cout << "El fichero a cargar es: " << sFilePath << std::endl;
    al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);
    
    this->pBitmap = al_load_bitmap(sFilePath.c_str());
    if(!this->pBitmap) {
        std::cout << "The file " << sFilePath << " has not been loaded correctly" << std::endl;
    } else {
        std::cout << "The file " << sFilePath << " has been correctly opened" << std::endl;
    }
}

void Bitmap::toFile(std::string sFilePath) {
    if(this->pBitmap == NULL) {
        std::cout << "pBitmap is NULL" << std::endl;
    } else {
        std::cout << "pBitmap is NOT NULL" << std::endl;
        if(!this->sDefaultExtension.empty()) {
            al_save_bitmap(sFilePath.c_str(), this->pBitmap);
            std::cout << "File has been saved as " << sFilePath << std::endl;
        }
    }
}

void Bitmap::randomBitmap() {
    
}

ALLEGRO_BITMAP* Bitmap::randomBitmap() {
    
}

Bitmap::~Bitmap() {
}

