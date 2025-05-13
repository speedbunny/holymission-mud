inherit "obj/weapon";
#include "/players/turbo/defs.h"
int i;

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("psi sword");
    set_alias("psi blade");
    set_read("This is the psi-sword of Mishra.  Urza and I alone may wield"+
             " this supreme weapon.  All others shall be cursed!\n");
    set_alt_name("sword");
    set_short("The Psi-sword of Mishra");
    set_long(
      "This is the Psi-sword of Mishra, one of the greatest artificers ever."+
      " It is said that only the twins could wield this weapon safely. "+
     "\n");
    set_class(25);
    set_light(1);
    set_hit_func(TO);
    set_weight(0);
    set_value(0);
    }


weapon_hit(attacker) 
{
    int i, dam;
    string tothem;
    i=random(10);
    switch(i) 
    {
      case 0:
        tothem=TPN+" slashes you with the psi-sword!";
	dam=55; break;
      case 1:
	tothem=TPN+" makes a quick triple slash!";
	dam=60; break;
      case 2:
	tothem=TPN+" hits 3 times and exclaims ' All who oppose us will die!'";
	dam=65; break;
      case 3:
	tothem=TPN+" hits 3 times and says ' You call that a weapon? HA !'";
	dam=70; break;
      case 4:
	tothem="As "+TPN+" swings 3 times and says 'CHILD, GO HOME!'";
	dam=75; break;
      case 5:
	tothem=TPN+" releases the blade and STILL hits!";
	dam=80; break;
      case 6:
	tothem="The blade strikes 3 times, flashing brilliantly with each strike!";
	dam=85; break;
      case 7:
        tothem=TPN+" laughs as he beats mercilessly upon his opponent!";
	dam=90; break;
      case 8:
        tothem=TPN+" moves so fast you barley see him hit SIX TIMES!";
      	dam=95; break;
      case 9:
        tothem="Hello. My name is "+TPN+", you attacked me. Prepare to die!";
	dam=200; break;
      default:
	return 0; break;
      }
    say(tothem+"\n");
    if (TPWIZ) write("Al-Akbar whispers: "+dam+" damage!\n");
    return dam;
}

drop()
{
  write("As the sword leaves its master's grasp, it fades into nothing");
  DEST(TO);
  return 1;
  }
