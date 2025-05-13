#include "/sys/levels.h"
#include "/players/waldo/guild/defs.h"
#define LEVEL 8
#define COST 50
int main(string str) 
{
  object obj,weaker;
  int cost,duration;

  if(TP->QLVL < LEVEL) 
  {
    ME("You do not have the knowledge to cast this spell.\n");
    return 1;
    }

  if(TP->QSP < COST) 
  {
    ME("You are too mentally fatigued to do that.\n");
    return 1;
    }

  if (!str)
  {
    ME("Whom do want to hold ?\n");
    return 1;
    }
  else

  if(!obj = HERE(str,ENV(TP))) 
  {
    ME("That is not here.\n");
    return 1;
    }

  if(!living(obj)) 
  {
    ME("That is not a living thing.\n");
    return 1;
    }

  if(obj->query_player()) 
  {
    ME("You cannot use this on players.\n");
    return 1;
    }

  duration = (TP->QCHA) - (obj->QCHA);

  if (duration < 3) 
    duration = 3;
  obj->hold(TP,duration);
  write("You hold "+str+".\n");
  ADDSP(-cost);
  return 1;
}

