inherit "obj/weapon";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("The Rod of Demons");
  set_short("The Rod of Demons");
  set_long("This rod seems to give off strange power.\n" +
           "It is nearly 2 meters long and is pretty heavy.\n" +
           "There are exotic looking runes inscribed on the rod.\n" +
           "This weapon feels very good in your hands.\n");
  set_alias("rod");
  set_alt_name("rod of demons");
  set_read("You can't read the runes, but you think it says\n" +
           "something about awesome power!!\n");
  set_class(20);
  set_value(6000);
  set_weight(6);
  set_hit_func(this_object());
}
weapon_hit(attacker) {
  if(attacker->id("demon")) {
  write("Your rod won't hit the demon!\n");
  return (-1000);
  }
  else {
  int rnd_hit,rnd_dam;
  rnd_hit=random(25);
  switch(rnd_hit)
  {
    case 0:
      write("\The rod gets warm in your hands!  You feel your opponent\n\
getting weaker.\n");
      say("The rod in "+TPN+"'s heats up!\n");
      rnd_dam=40+random(21);
      TP->restore_hit_points(rnd_dam);
      return (rnd_dam);
      break;
 
    case 1:
      write("The rod flashes with dark power!\n");
      say(TPN+"'s rod flashes with dark power!\n");
      rnd_dam=45+random(16);
      printf("You did an INSANE amount of damage to %s.\n",attacker->query_name());
      tell_object(attacker,TPN+" did an INSANE amount of damage to you.\n");
      attacker->hit_player(rnd_dam);
      return (rnd_dam);
      break;
  }
  return 0;
}
 
}
