//====================================================================================
// @Title:      INTERFACE
//------------------------------------------------------------------------------------
// @Location:   /engine/src/interface.cpp
// @Author:     Kevin Chen
// @Rights:     Copyright(c) 2012 DragonToe Studios
//------------------------------------------------------------------------------------
// @Notes:
//
//====================================================================================
#include <iostream>
#include "../include/interface.h"

namespace Interface
{
	void Separator(char c)
	{
		for (int i=0; i<CONSOLE_WIDTH; i++)
		{
			std::cout << c;
		}
	}

	void Paragraph(std::string text)
	{
		std::cout << text;
	}

	int Options(std::vector<cOption> options)
	{
		for (unsigned int i=0; i<options.size(); i++)
		{
			std::cout << i + 1 << "> " << options[i].text << std::endl;
		}

		Separator('=');

		std::cout << "Make your choice:" << std::endl;

		int choice_index = INVALID_INPUT;
		while ((choice_index = PollInput(options)) == INVALID_INPUT);

		return choice_index;
	}
	
	int PollInput(std::vector<cOption> options)
	{
		int choice_index;

		std::cout << "> ";

		std::cin >> choice_index;

		if (std::cin.fail() || choice_index < 0 || (unsigned int)choice_index > options.size())
		{
			std::cout << "Invalid choice" << std::endl;
			
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			return INVALID_INPUT;
		}
		return choice_index;
	}

	std::string CenterText(std::string text)
	{
		std::string ret = "";

		int buffer = (CONSOLE_WIDTH - text.length()) / 2;

		for (int i=0; i<buffer; i++)
		{
			ret += " ";
		}
		return ret + text;
	}

	void LineBreak(int num)
	{
		for (int i=0; i<num; i++) std::cout << std::endl;
	}

	std::string LetterSpacing(std::string text, int spaces)
	{
		std::string ret = "";
		std::string space = "";
		
		for (int i=0; i<spaces; i++) 
		{
			space += " ";
		}

		for (unsigned int i=0; i<text.length(); i++)
		{
			ret = ret + text[i];
			if (i != text.length() - 1) ret = ret + space;
		}

		return ret;
	}

	void ClearScreen()
	{
		system("cls");
	}

	void PauseScreen()
	{
		system("pause");
	}
}