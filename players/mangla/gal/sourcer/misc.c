#include "misc.h"

int check_coins(object who, int ammount)
{
	if(who->query_money() < ammount)
		return 0;
	who->add_money(-ammount);
	return ammount;
}
