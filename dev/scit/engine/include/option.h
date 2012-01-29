//====================================================================================
// @Title:      OPTION
//------------------------------------------------------------------------------------
// @Location:   /engine/include/option.h
// @Author:     Kevin Chen
// @Rights:     Copyright(c) 2012 DragonToe Studios
//------------------------------------------------------------------------------------
// @Notes:
//
//====================================================================================
#ifndef __OPTION_H__
#define __OPTION_H__

#include <string>

struct cOption
{
	std::string text;
	int nextNodeIndex;

	cOption(std::string rText, int rNextNodeIndex);
};

#endif