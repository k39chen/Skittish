//====================================================================================
// @Title:      NODE
//------------------------------------------------------------------------------------
// @Location:   /engine/include/node.h
// @Author:     Kevin Chen
// @Rights:     Copyright(c) 2012 DragonToe Studios
//------------------------------------------------------------------------------------
// @Notes:
//
//====================================================================================
#ifndef __NODE_H__
#define __NODE_H__

#include <string>
#include <vector>
#include "../../global.h"
#include "option.h"

// node states
enum eNodeState {BAD, NEUTRAL, FINISH};

// default first node to start adventure
static const int START_NODE_INDEX = 0;

class cNode
{
	eNodeState mState;

	int mNodeIndex;

	std::string mBanner;
	std::string mParagraph;
	std::vector<cOption> mOptions;

public:
	cNode();
	~cNode();

	// getters
	eNodeState State();
	
	// setters
	void NodeIndex(int newNodeIndex);
	void State(eNodeState newState);
	void Banner(std::string newBanner);
	void Paragraph(std::string newParagraph);
	void Options(std::vector<cOption> newOptions);

	// console output of node info
	void Draw();

	// returns index of next node to go to
	int Choose();
};

#endif