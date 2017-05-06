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

typedef std::function<void(int64_t)> XX_Callback_INT64;
typedef std::function<void()> XX_Callback_NONE;
#define XX_CALLBACK_0(__selector__,__target__, ...) std::bind(&__selector__,__target__, ##__VA_ARGS__)
#define XX_CALLBACK_1(__selector__,__target__, ...) std::bind(&__selector__,__target__, std::placeholders::_1, ##__VA_ARGS__)