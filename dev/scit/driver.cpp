//====================================================================================
// @Title:      DRIVER
//------------------------------------------------------------------------------------
// @Location:   /driver.cpp
// @Author:     Kevin Chen
// @Rights:     Copyright(c) 2012 DragonToe Studios
//------------------------------------------------------------------------------------
// @Notes:
//
//====================================================================================
#include <iostream>
#include <cstdlib>
#include <string>
#include "driver.h"

using namespace std;

int main(int argc, char *argv[])
{
	cGame *Game = new cGame();

	Game->Start();

	return 0;
}