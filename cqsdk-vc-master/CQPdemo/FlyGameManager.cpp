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
	gameCmd["��ʼ��Ϸ"] = XX_CALLBACK_1(FlyGameManager::onStartGame, this);
}

void FlyGameManager::onStartGame(int64_t qid)
{
	if (gameState != FlyGameState::None)
		return;
	gameState = FlyGameState::Start;
	CQ_sendGroupMsg(gAcCode, gID, "��ʼ��������Ϸ,�ȴ���Ҽ���,1���������˼��� ���Զ��ر���Ϸ");
}

void FlyGameManager::onJoinGame(int64_t qid)
{
	this->joinPlayer(qid);
}
