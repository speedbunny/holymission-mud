#include "/sys/levels.h"
#include "/players/waldo/guild/defs.h"
#define LEVEL 1
#define COST 30

int main(string target) 
{
  object whom;
  int dam;
  int missile_dam;
  int missiles;

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

  if(!target) 
    whom=TP->query_attack();
    else 
    whom=present(target, ENV(TP));

  if(!whom) 
  {
    if(!target) 
      write("missile whom?!\n");
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
// OKay so we actually cast the spell :)
  if (TP->QLVL==1 || TP->QLVL==2)
    missiles=2;
  if (TP->QLVL==3 || TP->QLVL==4)
    missiles=4;
  if (TP->QLVL==5 || TP->QLVL==6)
    missiles=6;
  if (TP->QLVL==7 || TP->QLVL==8)
    missiles=8;
  if (TP->QLVL>=9)
    missiles=10;

  write("You send a series of "+missiles+" missiles at your attacker.\n");

  missile_dam = random(15)+10;
  dam = (missile_dam * missiles); // total damage

  if(whom->query_hp()<dam)
    dam=whom->query_hp()+1;
  whom->hit_player(1);
  whom->hit_player(dam,5,({2,12}));
  TP->restore_spell_points( -COST);
  if (TP->query_immortal())
  {
    write("WIZINFO : Damage = "+dam+"\n");
    }
  return 1;
}
