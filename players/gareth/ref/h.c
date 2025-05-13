#include "/players/waldo/guild/defs.h"
#include "/sys/levels.h"
#define COST 100
#define LEVEL 17

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
        ME("Cast haste at whom?\n");
        return 1;
	}
      if(!living(who)) 
      {
        ME("Not likely, I'm afraid they aren't alive.\n");
        return 1;
	}
      }
    if(who->haste_shad()) 
    {
      ME("But, there is no point!\n");
      return 1;
      }

  ME("You cast haste at "+CAP(who->QRNAM)+".\n");
  TP->restore_spell_points(-COST);
  say(TPQN+" utters 'run run run' and points at "+CAP(who->QRNAM)+".\n");
  duration=( (TP->QSTR/5) + (who->QSTR/5) ) * (TP->QLVL);
  if (TPWIZ)
    ME("WIZ INFO: HASTE TIMER: "+duration+".\n");
  shad=CLONE("/players/waldo/guild/bin/shadows/haste");
  shad->start_shadow(who,duration);
  return 1;
}
