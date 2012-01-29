//====================================================================================
// @Title:      COMMON
//------------------------------------------------------------------------------------
// @Location:   /engine/src/common.cpp
// @Author:     Kevin Chen
// @Rights:     Copyright(c) 2012 DragonToe Studios
//------------------------------------------------------------------------------------
// @Notes:
//
//====================================================================================
#include <iostream>
#include <vector>
#include <string>
#include "../include/common.h"
#include "../../global.h"

void trim(std::string &str)
{
	std::string::size_type pos = str.find_last_not_of(" \t");
	if (pos != (std::string::npos))
	{
		str.erase(pos + 1);
		pos = str.find_first_not_of(" \t");
		if (pos != (std::string::npos))
		{
			str.erase(0, pos);
		}
	}
	else str.erase(str.begin(), str.end());
}

void formatField(std::string field_name, std::string &str)
{
	str = str.substr(str.find(field_name) + std::string(field_name).length(), str.length());
	trim(str);
	str = str.substr(1, str.length()-2);
}

int toString(std::string strNum)
{
	return atoi(strNum.c_str());
}

std::string lineWrap(std::string text)
{
	std::string formattedText = "";

	while (text.find("@") != std::string::npos)
	{
		formattedText = formattedText + lineWrapParagraph(text.substr(0,text.find("@"))) + "\n";
		text = text.substr(text.find("@") + 1, text.length());
	}
	formattedText = formattedText + lineWrapParagraph(text);

	return formattedText;
}

std::string lineWrapParagraph(std::string text)
{
	std::vector<std::string> words;

	while (text.find(" ") != std::string::npos)
	{
		std::string word = text.substr(0, text.find(" "));
		trim(word);

		words.push_back(word);

		text = text.substr(text.find(" ") + 1, text.length());
	} words.push_back(text);

	std::string paragraph = "";
	std::string line = "";

	for each (std::string word in words)
	{
		if (line.length() + word.length() >= CONSOLE_WIDTH)
		{
			paragraph += line;
			if (line.length() + word.length() != CONSOLE_WIDTH) paragraph += "\n";

			line = word + " ";
		}
		else
		{
			line = line + word + " ";
		}
	}
	paragraph += line;
	if (line.length() != CONSOLE_WIDTH) paragraph += "\n";

	return paragraph;
}