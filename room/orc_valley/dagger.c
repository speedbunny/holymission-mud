inherit "/obj/weapon";

#include "/obj/lw.h"

int charges;

void reset(int arg) {
  charges = 8;
  ::reset(arg);
  if(arg) return;

  set_name("poison dagger");
  set_alias("dagger");
  set_short("A poison dagger");
  set_class(11);
  set_hit_func(this_object());
  set_type(2);
}

void long() {
  string tmp;

  tmp = "A poison dagger. ";
  switch(charges) {
    case 0:
      tmp += "It looks as if there is no poison on it.\n";
      break;
    case 1..3:
      tmp += "It looks as if there is some poison left on it.\n";
      break;
    case 4..6:
      tmp += "It looks pretty well smeared with poison.\n";
      break;
    default:
      tmp += "It looks a superb weapon, but only if you're a thief!\n";
      break;
  }
  writelw(tmp);
}

int query_value() { return 500 + charges * 30; }

int weapon_hit(object ob) {
  if(!charges || random(4) || wielded_by->query_real_guild()!=1)
    return 0;

  if(environment(ob)->query_property("no_fight")) {
    write("You cannot use the weapon's ability here.\n");
    return 0;
  }

  charges--;
  writelw("You sneak past " + ob->query_name() +
          "'s defences and stab him with the dagger!\n");
  ob->add_poison(5);
  return 10+random(charges*15);
}
