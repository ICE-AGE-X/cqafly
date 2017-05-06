#include "stdafx.h"
#include "FlyGameManager.h"
void FlyGameManager::joinPlayer(int64_t qqid)
{
	players.push_back(Player(qqid));
}

void FlyGameManager::onRecCmd(std::string cmd,int64_t qid)
{

}

void FlyGameManager::initCmd()
{
	gameCmd["开始游戏"] = XX_CALLBACK_1(FlyGameManager::onStartGame, this);
}

void FlyGameManager::onStartGame(int64_t qid)
{
	if (gameState != FlyGameState::None)
		return;
	gameState = FlyGameState::Start;
	CQ_sendGroupMsg(gAcCode, gID, "开始飞行棋游戏,等待玩家加入,1分钟内无人加入 将自动关闭游戏");
}

void FlyGameManager::onJoinGame(int64_t qid)
{
	this->joinPlayer(qid);
}
