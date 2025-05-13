
inherit "obj/weapon";
#include "/players/izekiel/defs.h"
string name;

reset(arg){
  ::reset(arg);
  if(arg) return;

  set_name("sword of Yoshimitsu");
  set_alt_name("sword of yoshimitsu");
  set_alias("sword");
  set_class(14);
  set_value(500);
  set_weight(3);
  set_short("sword of Yoshimitsu");
  set_long(
   "A strange looking sword, made of a metal that looks rather foriegn. \n"+
   "There is a faint blue glow which appears to be emanating from within \n"+
   "the sword itself. The ivory hilt is inscripted with the letter 'Y'.\n");
  set_hit_func(TO);
}


int weapon_hit(object A)
{
  name = A->query_name();

  if((INT + DEX) > 48 && (random(60)) > 48){
  write("You manage to penetrate "+name+"'s defenses and score a "+
     "CRITICAL HIT!!\n");
  say(TPN+" breaks through "+name+"'s defenses and lands a CRITICAL HIT!\n");
  return random(40);
  }
}
