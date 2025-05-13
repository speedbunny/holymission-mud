/*
	Armour Spell
	(c) 1996 Waldo
*/

#include "/players/waldo/guild/defs.h"
#include "/sys/levels.h"
#define COST 50
#define LEVEL 2

int main(string str) 
{
    object who,shad;
  int new_ac;
  int duration;
  int level;

  if (TP->QLVL < LEVEL)
  {
    ME("You can't cast this spell yet.\n");
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
	ME("Cast armour at whom?\n");
	return 1;
	}
      if(!living(who)) 
      {
	ME("Not likely, I'm afraid they aren't alive.\n");
	return 1;
	}
      }
    if(who->armour_shad()) 
    {
      ME("But, there is no point!\n");
      return 1;
      }

  ME("You utter the words 'armour' at "+CAP(who->QRNAM)+".\n");
  TP->restore_spell_points(-COST);
  say(TPQN+" utters some words and points at "+CAP(who->QRNAM)+".\n");
  new_ac = (TP->QINT/4 + who->QINT/4);
  duration = (this_player()->query_wis() + who->query_wis() );
  duration = duration * (this_player()->query_dex() );
  duration=duration / 3;
  if (TPWIZ)
    ME("WIZ INFO: AC increase: "+new_ac+" TIMER: "+duration+".\n");
  shad=CLONE(SHAD+"armour");
  shad->start_shadow(who,duration,new_ac);
  return 1;
}

