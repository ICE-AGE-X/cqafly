#pragma once
#include <functional>
#include "cqp.h"
#define CC_SYNTHESIZE(varType, varName, funName)\
protected: varType varName;\
public: virtual varType get##funName(void) const { return varName; }\
public: virtual void set##funName(varType var){ varName = var; }

#ifdef _MSC_VER 
#define sprintf sprintf_s
//#define  fopen fopen_s
#endif // !_MSC_VER 

#include <vector>
#include <map>
#include "timer.h"

typedef std::function<void(int64_t)> XX_Callback_INT64;
typedef std::function<void()> XX_Callback_NONE;
#define XX_CALLBACK_0(__selector__,__target__, ...) std::bind(&__selector__,__target__, ##__VA_ARGS__)
#define XX_CALLBACK_1(__selector__,__target__, ...) std::bind(&__selector__,__target__, std::placeholders::_1, ##__VA_ARGS__)

static void xLog(const char * msg)
{

	FILE* logF = fopen("xlog.txt", "a");
	fwrite(msg, strlen(msg), 1, logF);
	fclose(logF);
	logF = nullptr;
}
static char logBuffer[10 * 1024];

static const char * stringFromat(const char *format, int64_t id)
{
	memset(logBuffer, 0, 10 * 1024);
	sprintf(logBuffer, format, id);
	return logBuffer;
}
static void xLog(int64_t qqid, const char * msg)
{
	memset(logBuffer, 0, 10 * 1024);
	sprintf(logBuffer, "%lld::%s\n", qqid, msg);
	xLog(logBuffer);
}