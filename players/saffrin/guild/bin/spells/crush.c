#include "/sys/levels.h"
#include "/players/waldo/guild/defs.h"
#define COST 100
#define LEVEL 20

int main(string target) {

  object whom;
  int dam;

  if (TP->QLVL < LEVEL)
  {
    write("You don't know this spell yet.\n");
    return 1;
    }
  
  if (TP->QSP < COST)
  {
    write("You can't summon enough energy.\n");
    return 1;
    }
  
  TP->restore_spell_points(-COST);

  if(!target)
     whom=TP->query_attack();
     else 
     whom=present(target, ENV(TP));

  if(!whom) 
  {
    if(!target) 
      write("Crush whom?!\n");
      else 
      write("No "+ CAP(target) +" here.\n");
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

  dam =  100 + (random(TP->QLVL/3 + TP->QWIS));

  TELLRM(ENV(TP),TP->QNAME + " reaches up and forms a fist.\n",TP);
  ME("You form your hand to imitate the magical fist enclosing " +
        CAP(target) +".\n");

  TELLRM(ENV(TP),"You hear "+ CAP(target) +" scream in agony.\n",whom);
  TELL(whom,"You feel crushed in a giant fist!\n");

  if(whom->QHP<dam)
  whom->hit_player(1);
  whom->hit_player(dam,5,({2,12}));
  if (TP->QWIZ)
  {
    ME("Damage = "+dam+".\n");
    }
  return 1;
}
