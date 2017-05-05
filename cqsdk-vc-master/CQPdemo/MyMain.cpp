#include "stdafx.h"
#include "MyMain.h"

static MyMain * mInstance=nullptr;
MyMain::~MyMain()
{
	delete logF;
	logF = nullptr;
}
MyMain * MyMain::getInstance()
{
	if (mInstance == nullptr)
		mInstance = new MyMain();
	return mInstance;
}

void MyMain::destroyInstance()
{
	delete mInstance;
	mInstance = nullptr;
}

void MyMain::setAcCode(int ac)
{
	acCode = ac;
}

void MyMain::onRecPrivateMsg(int32_t subType, int32_t sendTime, int64_t fromQQ, const char * msg, int32_t font)
{
	xLog(fromQQ, msg);
	sendPrivateMsg(msg, fromQQ);
}

void MyMain::onRecGroupMsg(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char * fromAnonymous, const char * msg, int32_t font)
{
	sendGroupMsg(msg, fromGroup);
}

void MyMain::sendPrivateMsg(const char * msg, int64_t qqid)
{
	CQ_sendPrivateMsg(acCode, qqid, msg);
}

void MyMain::sendGroupMsg(const char * msg, int64_t qqgroup)
{
	CQ_sendGroupMsg(acCode, qqgroup, msg);
}

void MyMain::loadMenuConfig()
{
	FILE *f = fopen("test.json", "r");
	char buf[10 * 1024];
	fread(buf, 10 * 1024, 1, f);
	fclose(f);
}

void MyMain::xLog(const char * msg)
{
	if (logF == nullptr)
		logF = fopen("xlog.txt", "a");
	fwrite(msg, strlen(msg), 1, logF);
	fflush(logF);
}

void MyMain::xLog(int64_t qqid, const char * msg)
{
	memset(logBuf, 0, 10 * 1024);
	sprintf(logBuf, "%ld::", qqid);
	xLog(logBuf);
	sprintf(logBuf, "%s\n", msg);
	xLog(logBuf);
}
