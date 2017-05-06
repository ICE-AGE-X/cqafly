#pragma once
#include "util.h"
#include "Player.h"
enum FlyGameState
{
	None=0,
	Start,
	Join,
	Gaming,
	End
};

class FlyGameManager
{
public:
	FlyGameManager(int64_t gid,int ac)
	{
		gameState = FlyGameState::None;
		gAcCode = ac;
	}
public:
	CC_SYNTHESIZE(FlyGameState, gameState, GameState);
	CC_SYNTHESIZE(int64_t, gID, GroupId);
	CC_SYNTHESIZE(int, gAcCode, AcCode);
	std::vector<Player> & getPlayers() { return players; };
	void joinPlayer(int64_t qqid);
	void onRecCmd(std::string cmd,int64_t qid);
	void initCmd();
private:
	std::vector<Player> players;
	std::map<std::string, XX_Callback_INT64> gameCmd;
private://func
	void onStartGame(int64_t qid);
	void onJoinGame(int64_t qid);
};
