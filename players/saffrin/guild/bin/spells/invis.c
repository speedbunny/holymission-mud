#include "/sys/levels.h"
#include "/players/waldo/guild/defs.h"
#define LEVEL 1
#define COST 30
int INVISED;

int main(string target) 
{
  object whom;
  int dur;

  if ( TP->QLVL < LEVEL )
  {
    write("You do not have the knowledge of this spell yet.\n");
    return 1;
    }

  if ( TP->QSP < COST )
  {
    write ("You are too mentally fatigued to do that.\n");
    return 1;
    }

  if (target!=TP->query_real_name())
  {
    write ("You can only cast this spell at yourself.\n");
    return 1;
    }

  if (INVISED)
  {
    write("But you are already invisible.\n");
    return 1;
    }

  write("You utter the words 'invisibility'.\n");
  say(TP->QNAME+" utters 'watch me go'.\n");

  TP->restore_spell_points(-COST);
  dur = TP->QINT * 3;
  TP->set_invis(TP->QLVL-1);
  INVISED=1;
  call_out("remove",dur);
  if (TP->query_immortal()) // Return damage to immortals
  {
    write("WIZINFO : Invis Duration = "+dur+"\n");
    }
  return 1;
}

remove()
{
  TP->set_vis();
  write("You shimmer back into the reality.\n");
  INVISED=0;
  }

