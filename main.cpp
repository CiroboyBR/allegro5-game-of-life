/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: aalmunia
 *
 * Created on May 26, 2016, 2:01 PM
 */

#include <cstdlib>
#include "include/Application.h"

int main(int argc, char** argv) {
    std::string sName = "Allegro 5 test application";
    Application *oApp = new Application(500, 500, sName);
    oApp->initApp();
}

