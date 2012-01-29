//====================================================================================
// @Title:      GAME
//------------------------------------------------------------------------------------
// @Location:   /engine/src/game.cpp
// @Author:     Kevin Chen
// @Rights:     Copyright(c) 2012 DragonToe Studios
//------------------------------------------------------------------------------------
// @Notes:
//
//====================================================================================
#include <fstream>
#include "../include/game.h"
#include "../include/interface.h"
#include "../include/common.h"

cGame::cGame()
{
	mLoop = true;

	mProjDir = "data/";

	LoadProject();

	mCurrentNodeIndex = START_NODE_INDEX;
}

void cGame::LoadProject()
{
	std::ifstream in(mProjDir + "config.dat");

	std::string line;

	for (std::getline(in,line); !in.fail(); std::getline(in,line))
	{
		formatField("@project:", line);
		mProjDir += line;
	}
}

void cGame::LoadInfo()
{
	std::ifstream in(mProjDir + "/info.dat");

	std::string line;

	for (std::getline(in,line); !in.fail(); std::getline(in,line))
	{
		if (line.find("@title:") != std::string::npos)
		{
			formatField("@title:", line);
			mTitle = line;
		}
		if (line.find("@author:") != std::string::npos)
		{
			formatField("@author:", line);
			mAuthor = line;
		}
		if (line.find("@version:") != std::string::npos)
		{
			formatField("@version:", line);
			mVersion = line;
		}
	}
}

void cGame::LoadNodes()
{
	std::ifstream in(mProjDir + "/nodes.dat");

	std::vector<cOption> accOptions;
	std::string line;

	bool creating_node = false;
	bool parsing_options = false;

	for (std::getline(in,line); !in.fail(); std::getline(in,line))
	{
		trim(line);
		
		if (line == "{")	// start creating node
		{
			Nodes.push_back(cNode());
			creating_node = true;
			continue;
		}
		if (line == "}")	// stop creating node
		{
			creating_node = false;
			continue;
		}
		if (line == "[")
		{
			accOptions.clear();
			parsing_options = true;
			continue;
		}
		if (line == "]")
		{
			Nodes[Nodes.size() - 1].Options(accOptions);
			parsing_options = false;
			continue;
		}
		
		if (creating_node)
		{
			if (line.find("@nodeIndex:") != std::string::npos)
			{
				formatField("@nodeIndex:", line);
				Nodes[Nodes.size() - 1].NodeIndex(toString(line));
			}
			if (line.find("@state:") != std::string::npos)
			{
				formatField("@state:", line);
				Nodes[Nodes.size() - 1].State((eNodeState)toString(line));
			}
			if (line.find("@banner:") != std::string::npos)
			{
				formatField("@banner:", line);
				Nodes[Nodes.size() - 1].Banner(line);
			}
			if (line.find("@paragraph:") != std::string::npos)
			{
				formatField("@paragraph:", line);
				Nodes[Nodes.size() - 1].Paragraph(line);
			}

			if (parsing_options)
			{
				std::string option_text;
				int next_node_index;

				option_text = line.substr(1, line.find(",") - 2);
				
				line = line.substr(line.find(",") + 1, line.length());
				trim(line);

				next_node_index = toString(line);

				accOptions.push_back(cOption(option_text, next_node_index));
			}
		}
	}

	in.close();
}

void cGame::BeginInterface()
{
	Interface::Separator('=');

	std::cout << Interface::CenterText(Interface::LetterSpacing("~ " + mTitle + " ~", 1)) << std::endl;

	Interface::Separator('=');
	std::cout << Interface::CenterText("Author: " + mAuthor) << std::endl;
	std::cout << Interface::CenterText("Version: " + mVersion) << std::endl;

	Interface::Separator('-');

	for (int i=0; i<25; i++) std::cout << " ";
	Interface::PauseScreen();
	Interface::ClearScreen();
}

void cGame::WinInterface()
{
	Interface::Separator('=');

	std::cout << Interface::CenterText(Interface::LetterSpacing("YOU WIN!", 1)) << std::endl;

	Interface::Separator('=');

	for (int i=0; i<25; i++) std::cout << " ";
	Interface::PauseScreen();
	Interface::ClearScreen();
}

void cGame::LoseInterface()
{
	Interface::Separator('=');

	std::cout << Interface::CenterText(Interface::LetterSpacing("YOU LOSE!", 1)) << std::endl;

	Interface::Separator('=');

	for (int i=0; i<25; i++) std::cout << " ";
	Interface::PauseScreen();
	Interface::ClearScreen();
}

void cGame::QuitInterface()
{
	Interface::Separator('=');

	std::cout << Interface::CenterText(Interface::LetterSpacing("LEAVING GAME...", 1)) << std::endl;

	Interface::Separator('=');

	for (int i=0; i<25; i++) std::cout << " ";
	Interface::PauseScreen();
	Interface::ClearScreen();
}

void cGame::Hud()
{
	std::cout << "hud!" << std::endl;
}

void cGame::Start()
{
	LoadInfo();
	LoadNodes();

	BeginInterface();

	Run();
}

void cGame::Run()
{
	while (mLoop)
	{
		Nodes[mCurrentNodeIndex].Draw();

		int nextNodeIndex = Nodes[mCurrentNodeIndex].Choose();

		// process input
		if (nextNodeIndex != EXIT_LEVEL)
		{
			switch (Nodes[mCurrentNodeIndex].State())
			{
			case BAD:
				Lose();
				break;
			case FINISH:
				Win();
				break;
			default:
				mCurrentNodeIndex = nextNodeIndex;
				break;
			}
		}
		else
		{
			Exit();
			break;
		}

		// made it through this screen
		Interface::ClearScreen();
	}
}

void cGame::Win()
{
	Interface::ClearScreen();
	
	mCurrentNodeIndex = START_NODE_INDEX;

	WinInterface();

	Interface::PauseScreen();
}

void cGame::Lose()
{
	Interface::ClearScreen();
	
	mCurrentNodeIndex = START_NODE_INDEX;

	LoseInterface();

	Interface::PauseScreen();
}

void cGame::Exit()
{
	Interface::ClearScreen();
	
	mLoop = false;

	QuitInterface();
}

cGame::~cGame()
{
}