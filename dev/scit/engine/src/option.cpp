//====================================================================================
// @Title:      OPTION
//------------------------------------------------------------------------------------
// @Location:   /engine/src/option.cpp
// @Author:     Kevin Chen
// @Rights:     Copyright(c) 2012 DragonToe Studios
//------------------------------------------------------------------------------------
// @Notes:
//
//====================================================================================
#include "../include/option.h"

cOption::cOption(std::string rText, int rNextNodeIndex)
{
	text = rText;
	nextNodeIndex = rNextNodeIndex;
}