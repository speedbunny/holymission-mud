#include "/players/waldo/guild/defs.h"
#include "/sys/levels.h"
#define COST 100
#define LEVEL 7

int main(string str) {
    object who,shad;
    int new_str,duration,level;

  if (TP->QLVL < LEVEL)
  {
    ME("You can't do that yet.\n");
    return 1;
    }

  if (TP->QSP < COST)
  {
    ME("You can't summon enough energy.\n");
    return 1;
    }

  if(!str) 
    who=TP;
    else 
    {
      who=HERE(str,ENV(TP));
      if(!who) 
      {
        ME("Cast strength at whom?\n");
        return 1;
	}
      if(!living(who)) 
      {
        ME("Not likely, I'm afraid they aren't alive.\n");
        return 1;
	}
      }
    if(who->strength_shad()) 
    {
      ME("But, there is no point!\n");
      return 1;
      }

  ME("You cast strength at "+CAP(who->QRNAM)+".\n");
  TP->restore_spell_points(-COST);
  say(TPQN+" utters some words and points at "+CAP(who->QRNAM)+".\n");
  new_str = 10 + (TP->QSTR/3);
  if ( new_str > 30 ) new_str=30;
  duration=( (TP->QINT/3) + (TP->QWIS/3) ) * 10;
  if (TPWIZ)
    ME("WIZ INFO: STR increase: "+new_str+" TIMER: "+duration+".\n");
  shad=CLONE("/players/waldo/guild/bin/shadows/strength");
  shad->start_shadow(who,duration,new_str);
  return 1;
}
