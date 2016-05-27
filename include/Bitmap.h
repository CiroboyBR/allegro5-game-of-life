/* 
 * File:   Bitmap.h
 * Author: aalmunia
 *
 * Created on May 27, 2016, 10:23 AM
 */

#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <stdio.h>
#include <allegro5/allegro.h>

class Bitmap {
public:
    Bitmap();
    Bitmap(const Bitmap& orig);
    Bitmap(std::string sFilePath, std::string sExtension);
    void fromFile(std::string sFilePath);
    void randomBitmap();
    ALLEGRO_BITMAP* randomBitmap();
    void toFile(std::string sFilePath);
    void toFile(std::string sFilePath, std::string sExtension);
    void setDefaultExtension(std::string sExtension);
    std::string getDefaultExtension();
    virtual ~Bitmap();
private:
    ALLEGRO_BITMAP *pBitmap;
    std::string sDefaultExtension;
};

#endif /* BITMAP_H */

