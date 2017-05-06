#pragma once
#include <stdint.h>
#include "util.h"
enum PlayerState
{
	STOP = 0,
	NORMAL
};
class Player
{
public:
	//pos Î»ÖÃ£¬ps,×´Ì¬£¬qqºÅ
	Player(int pos,PlayerState ps,int64_t qqid);
	Player(int64_t qqid) { currentPos = 0; pState = PlayerState::NORMAL; mQqid = qqid; };
public://mem
	CC_SYNTHESIZE(int, currentPos, CurrentPos);
	CC_SYNTHESIZE(PlayerState, pState, PState);
	CC_SYNTHESIZE(int64_t, mQqid, QQid);
private:
	
};
