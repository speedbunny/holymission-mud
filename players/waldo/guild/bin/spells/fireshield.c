/*
	Fireshield Spell
	(c) 1996 Waldo
*/

#include "/players/waldo/guild/defs.h"
#include "/sys/levels.h"
#define COST 50
#define LEVEL 2

int main(string str) 
{
    object who,shad;
    int new_ac,duration,level;

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

if ( (str) && (str!=TP->query_real_name()) )
  {
    ME("You can only cast this at yourself.\n");
    return 1;
    }

  who = TP;

  if(who->fshield_shad()) 
    {
      ME("But, there is a spell of this kind already active!\n");
      return 1;
      }

  ME("You utter the words 'fireshield'.\n");
  TP->restore_spell_points(-COST);
  say(TPQN+" utters some words and points at themselves.\n");
  duration = (TP->QWIS + who->QWIS) * (TP->QDEX);
  duration = duration / 3 ;
  if (TPWIZ)
    ME("WIZ INFO: Fireshield TIMER: "+duration+".\n");
  shad=CLONE(SHAD+"fshield");
  shad->start_shadow(who,duration);
  return 1;
}

