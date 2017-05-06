#pragma once
#include "cqp.h"
#include "stdafx.h"
#include "util.h"
#include "FlyGameManager.h"
class MyMain
{
public:
	~MyMain();
	static MyMain * getInstance();
	static void destroyInstance();
	void setAcCode(int ac);
	//�յ�˽����Ϣ
	void onRecPrivateMsg(int32_t subType, int32_t sendTime, int64_t fromQQ, const char *msg, int32_t font);
	//�յ�Ⱥ����Ϣ
	void onRecGroupMsg(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char *fromAnonymous, const char *msg, int32_t font);
private:
	MyMain(){};
	//����˽����Ϣ
	void sendPrivateMsg(const char *msg, int64_t qqid); 
	//����Ⱥ����Ϣ
	void sendGroupMsg(const char *msg, int64_t qqid);
	int acCode = 0;
	void loadMenuConfig();
private://
	FlyGameManager fgm;
};
