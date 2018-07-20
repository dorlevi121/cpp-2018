#pragma once

#include "Player.h"
#include <typeinfo>

class Champion: public Player{

public:
    const string name() const override { return "Dor, Yarden and Sergey"; }
	const Coordinate play(const Board& board) override;
};