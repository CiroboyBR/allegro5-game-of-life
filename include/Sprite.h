/* 
 * File:   Sprite.h
 * Author: aalmunia
 *
 * Created on May 27, 2016, 10:32 AM
 */

#include "Bitmap.h"

#ifndef SPRITE_H
#define SPRITE_H

class Sprite : Bitmap {
public:
    Sprite();
    Sprite(const Sprite& orig);
    virtual ~Sprite();
private:

};

#endif /* SPRITE_H */

