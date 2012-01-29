//====================================================================================
// @Title:      NODE
//------------------------------------------------------------------------------------
// @Location:   /engine/src/node.cpp
// @Author:     Kevin Chen
// @Rights:     Copyright(c) 2012 DragonToe Studios
//------------------------------------------------------------------------------------
// @Notes:
//
//====================================================================================
#include <iostream>
#include "../include/node.h"
#include "../include/common.h"
#include "../include/interface.h"

cNode::cNode()
{
}

void cNode::Draw()
{
	Interface::Separator('=');

	std::cout << " * " << mBanner << std::endl;

	Interface::Separator('-');

	Interface::Paragraph(lineWrap(mParagraph));

	Interface::Separator('-');
}

int cNode::Choose()
{
	int choice_index = Interface::Options(mOptions);

	if (choice_index != EXIT_LEVEL)
	{
		return mOptions[choice_index - 1].nextNodeIndex;
	}
	else
	{
		return EXIT_LEVEL;
	}
}

cNode::~cNode()
{
}

eNodeState cNode::State()								{return mState;}

void cNode::NodeIndex(int newNodeIndex)					{mNodeIndex = newNodeIndex;}
void cNode::State(eNodeState newState)					{mState = newState;}
void cNode::Banner(std::string newBanner)				{mBanner = newBanner;}
void cNode::Paragraph(std::string newParagraph)			{mParagraph = newParagraph;}
void cNode::Options(std::vector<cOption> newOptions)	{mOptions = newOptions;}