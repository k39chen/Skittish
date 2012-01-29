//====================================================================================
// @Title:      GAME
//------------------------------------------------------------------------------------
// @Location:   /engine/include/game.h
// @Author:     Kevin Chen
// @Rights:     Copyright(c) 2012 DragonToe Studios
//------------------------------------------------------------------------------------
// @Notes:
//
//====================================================================================
#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include <string>
#include "node.h"
#include "../../global.h"

class cGame
{
	std::string mProjDir;

	std::string mTitle;
	std::string mAuthor;
	std::string mVersion;

	bool mLoop;
	int mCurrentNodeIndex;

	void LoadProject();
	void LoadInfo();
	void LoadNodes();

	std::vector<cNode> Nodes;

public:
	cGame();
	virtual ~cGame();

	virtual void Start();
	virtual void Run();
	virtual void Win();
	virtual void Lose();
	virtual void Exit();

	virtual void Hud();

	virtual void BeginInterface();
	virtual void WinInterface();
	virtual void LoseInterface();
	virtual void QuitInterface();
};

#endif