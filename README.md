This project is an implementation of John Horton Conway's Game of life.
It uses Allegro5 and C++11. The Allegro code has been thoroughly encapsulated
No dealing with C-like functions no more.


#Compile with Allegro 5.0.10 + MinGW command-line

g++ -c main.cpp src/Application.cpp src/Bitmap.cpp src/Sprite.cpp

g++ main.o Application.o Sprite.o Bitmap.o -o game -lallegro-5.0.10-mt -lallegro_image-5.0.10-mt
