//====================================================================================
// @Title:      INTERFACE
//------------------------------------------------------------------------------------
// @Location:   /engine/include/interface.h
// @Author:     Kevin Chen
// @Rights:     Copyright(c) 2012 DragonToe Studios
//------------------------------------------------------------------------------------
// @Notes:
//
//====================================================================================
#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <string>
#include <vector>
#include "../../global.h"
#include "option.h"

namespace Interface
{	
	void Separator(char c);
	void Paragraph(std::string text);
	
	// returns option index
	int Options(std::vector<cOption> options);

	// returns -1 if invalid input otherwise returns valid option index
	int PollInput(std::vector<cOption> options);

	// text align
	std::string CenterText(std::string text);

	// spacing
	void LineBreak(int num);
	std::string LetterSpacing(std::string text, int spaces);

	// change mechanic based off system type
	void ClearScreen();
	void PauseScreen();
}

#endif