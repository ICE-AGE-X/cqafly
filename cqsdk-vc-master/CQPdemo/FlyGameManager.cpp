#include "stdafx.h"
#include "FlyGameManager.h"
void FlyGameManager::joinPlayer(int64_t qqid)
{
	for (Player p:players)
	{
		if (p.getQQid() == qqid)
		{
			sendGameGroupMsg(stringFromat("玩家:%lld已加入游戏,不必重复加入",qqid));
			return;
		}
	}
	players.push_back(Player(qqid));
	sendGameGroupMsg(stringFromat("玩家:%lld加入游戏成功", qqid));
}

void FlyGameManager::onRecCmd(std::string cmd,int64_t qid)
{
	std::map<std::string, XX_Callback_INT64>::iterator ite = gameCmd.find(cmd);
	if (ite != gameCmd.end())
		ite->second(qid);
}

void FlyGameManager::initCmd()
{
	gameCmd["开始游戏"] = XX_CALLBACK_1(FlyGameManager::onStartGame, this);
	gameCmd["加入"] = XX_CALLBACK_1(FlyGameManager::onJoinGame, this);
}

void FlyGameManager::onStartGame(int64_t qid)
{
	if (gameState != FlyGameState::None)
		return;
	gameState = FlyGameState::Start;
	CQ_sendGroupMsg(gAcCode, gID, "开始飞行棋游戏,等待玩家加入,1分钟内无人加入 将自动关闭游戏，加入游戏 请输 加入");
	Timer t;
	t.SyncWait(1000*60, []() {
		xLog("test timer");
	});
	t.setTimerID(1);
	allTimer.push_back(t);
}

void FlyGameManager::onJoinGame(int64_t qid)
{
	if (gameState == FlyGameState::Start || gameState == FlyGameState::Join)
	{
		this->joinPlayer(qid);
	}
}

void FlyGameManager::stopTimer(int id)
{
	std::vector<Timer>::iterator ite = allTimer.begin();
	while (ite != allTimer.end())
	{
		if ((*ite).getTimerID()==id)
		{
			(*ite).Expire();
			//ite=allTimer.erase(ite);
			return;
		}
		else
			ite++;
	}

}

void FlyGameManager::sendGameGroupMsg(const char * msg)
{
	CQ_sendGroupMsg(gAcCode, gID, msg);
}
