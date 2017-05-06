#pragma once
#include "cqp.h"
#include "stdafx.h"
#include "util.h"
class MyMain
{
public:
	~MyMain();
	static MyMain * getInstance();
	static void destroyInstance();
	void setAcCode(int ac);
	//收到私聊消息
	void onRecPrivateMsg(int32_t subType, int32_t sendTime, int64_t fromQQ, const char *msg, int32_t font);
	//收到群聊消息
	void onRecGroupMsg(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char *fromAnonymous, const char *msg, int32_t font);
private:
	//发送私聊消息
	void sendPrivateMsg(const char *msg, int64_t qqid); 
	//发送群聊消息
	void sendGroupMsg(const char *msg, int64_t qqid);
	int acCode = 0;
	void loadMenuConfig();
	void xLog(const char *msg);
	void xLog(int64_t qqid, const char *msg);
	FILE * logF=nullptr;
	char logBuf[10 * 1024];
};
