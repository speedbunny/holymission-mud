inherit "obj/monster";

#include "/obj/obj_defs.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("steel dragon");
  set_no_steal(1);
  set_level(12);
  set_wc(16);
  set_alt_name("steel");
  set_short("A tiny steel dragon");
  set_long("You see a tiny steel dragon.  It looks extremly dangerous.  "+
           "A corrosive black ooze slowly leaks from one nostril, sending "+
           "up a wisp of greasy smoke which is all that remains of whatever "+
           "it touched.  Leathery wings rustle in irritation at your "+
           "presence.\n");
  set_race("dragon");
  set_size(5);
  set_al(-100);
  set_ac(5);
  add_money(288);
#if 0
// 190198: Sauron: Removed. Replace when monster_died() does something.
  set_dead_ob(TO);
#endif
  if(objectp(ENV())) {
    TELLR(ENV(), "Suddenly a big dark shadow lands next to you.\n");
  }
}

int monster_died(object ob) {
}

int attack() {
  object *vic;
  int    i, sz;

  i = 1;

  while(i) {
    if(random(2))
      ::attack();
    i--;
  }

  if(::attack() && !random(3)) {
    vic = all_inventory(ENV(TO));
    for(i=0, sz=sizeof(vic); i<sz; i++) {
      if(living(vic[i]) && (vic[i] != TO)) {
        vic[i]->hit_player(20+random(20));
        vic[i]->add_poison(16);
        TELLR(ENV(TO), "The steel dragon breathes a "+
              "blast of glowing, poisonous stones into the area!\n");
        return 1;
      }
    }
  }
  return 0;
}

int run_away() {
  return 0;
}

varargs mixed hit_player(int dam, int kind, mixed *ele) {
  if(ele && (int)9 == (int)ele)
     return ::hit_player(0, kind, ele);
     return ::hit_player(dam, kind, ele);
}
