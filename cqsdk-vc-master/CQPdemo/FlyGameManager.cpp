#include "stdafx.h"
#include "FlyGameManager.h"
void FlyGameManager::joinPlayer(int64_t qqid)
{
	for (Player p:players)
	{
		if (p.getQQid() == qqid)
		{
			sendGameGroupMsg(stringFromat("���:%lld�Ѽ�����Ϸ,�����ظ�����",qqid));
			return;
		}
	}
	players.push_back(Player(qqid));
	sendGameGroupMsg(stringFromat("���:%lld������Ϸ�ɹ�", qqid));
}

void FlyGameManager::onRecCmd(std::string cmd,int64_t qid)
{
	std::map<std::string, XX_Callback_INT64>::iterator ite = gameCmd.find(cmd);
	if (ite != gameCmd.end())
		ite->second(qid);
}

void FlyGameManager::initCmd()
{
	gameCmd["��ʼ��Ϸ"] = XX_CALLBACK_1(FlyGameManager::onStartGame, this);
	gameCmd["����"] = XX_CALLBACK_1(FlyGameManager::onJoinGame, this);
}

void FlyGameManager::onStartGame(int64_t qid)
{
	if (gameState != FlyGameState::None)
		return;
	gameState = FlyGameState::Start;
	CQ_sendGroupMsg(gAcCode, gID, "��ʼ��������Ϸ,�ȴ���Ҽ���,1���������˼��� ���Զ��ر���Ϸ��������Ϸ ���� ����");
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
