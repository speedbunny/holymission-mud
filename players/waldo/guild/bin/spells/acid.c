/*
	Acid Arrow Spell
	(c) Waldo 1996
*/
#include "/sys/levels.h"
#include "/players/waldo/guild/defs.h"
#define LEVEL 1
#define COST 80

int main(string target) 
{
  object whom;
  int dam;

  if ( TP->QLVL < LEVEL )
  {
    write("You can't cast this spell yet.\n");
    return 1;
    }

  if ( TP->QSP < COST )
  {
    write ("You are too mentally fatigued to do that.\n");
    return 1;
    }

  if(!target) 
    whom=TP->query_attack();
    else 
    whom=present(target, ENV(TP));

  if(!whom) 
  {
    if(!target) 
      write("Do what to whom?!\n");
      else 
      write("Oh dear, they don't seem to be here.\n");
    return 1;
    }
  if(whom==TP) 
  {
    write("You don't want to do that.\n");
    return 1;
    }

  if(!living(whom)) 
  {
    write(CAP(target)+" is not a living thing.\n");
    return 1;
    }
// OKay so we actually cast the spell :)
  write("You utter the words 'acid acid acid'.\n");
  say(TP->QNAME+" utters 'drip drip drip'.\n");

  dam = 40+random(35)+5; // total damage before ac adjustment

  whom->hit_player(1);
  whom->hit_player(dam,5,({2,12}));
  TP->restore_spell_points( -COST); // Adjust spell points
  if (TP->query_immortal()) // Return damage to immortals
  {
    write("WIZINFO : Damage = "+dam+"\n");
    }
  return 1;
}

