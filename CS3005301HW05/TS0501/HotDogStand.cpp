#include "HotDogStand.h"
#include <iostream>
#define ID_LENGTH 10

int HotDogStand::totalSellAmount = 0;

HotDogStand::HotDogStand()
{
	hotDogSellAmount = 0;
	standId = (char*)malloc(sizeof(char) * ID_LENGTH);
	memset(standId, 0, sizeof(char) * ID_LENGTH);
}

HotDogStand::HotDogStand(const char * id)
{
	standId = (char*)malloc(sizeof(char) * ID_LENGTH);
	memset(standId, 0, sizeof(char) * ID_LENGTH);
	hotDogSellAmount = 0;
	for (int i = 0; id[i] != '\0' && i < ID_LENGTH - 1; ++i) standId[i] = id[i];
}

HotDogStand::HotDogStand(const char * id, int amount)
{
	hotDogSellAmount = amount;
	totalSellAmount += amount;
	standId = (char*)malloc(sizeof(char) * ID_LENGTH);
	memset(standId, 0, sizeof(char) * ID_LENGTH);
	for (int i = 0; id[i] != '\0' && i < ID_LENGTH - 1; ++i) standId[i] = id[i];
}


HotDogStand::~HotDogStand()
{
}

void HotDogStand::justSold()
{
	hotDogSellAmount += 1;
	totalSellAmount += 1;
}

void HotDogStand::print()
{
	std::cout << standId << " " << hotDogSellAmount << std::endl;
}

int HotDogStand::thisStandSoldAmount()
{
	return hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount()
{
		return totalSellAmount;
}
