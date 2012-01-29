//====================================================================================
// @Title:      COMMON
//------------------------------------------------------------------------------------
// @Location:   /engine/include/common.h
// @Author:     Kevin Chen
// @Rights:     Copyright(c) 2012 DragonToe Studios
//------------------------------------------------------------------------------------
// @Notes:
//
//====================================================================================
#ifndef __COMMON_H__
#define __COMMON_H__

#include <string>

void trim(std::string &str);
void formatField(std::string field_name, std::string &str);
int toString(std::string strNum);

std::string lineWrap(std::string text);
std::string lineWrapParagraph(std::string text);

#endif