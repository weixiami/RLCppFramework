#pragma once

#include <random>


namespace rcf
{

static int random()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	return mt();
}


}

