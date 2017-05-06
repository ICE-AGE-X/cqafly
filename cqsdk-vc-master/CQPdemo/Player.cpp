#include "stdafx.h"
#include "Player.h"

Player::Player(int pos, PlayerState ps, int64_t qqid)
{
	currentPos = pos;
	pState = ps;
	mQqid = qqid;
}
