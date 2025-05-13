inherit "obj/monster";

#include "/obj/obj_defs.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("blue dragon");
  set_no_steal(1);
  set_level(42);
  set_hp(1300);
  set_wc(31);
  set_alt_name("blue");
  set_short("A big blue dragon");
  set_long("You see a big blue dragon.  It looks extremely dangerous.  "+
           "Its fierce talons glimmer evily from constant sharpening "+
           "against the volcanic rocks of the island.  A slow hissing "+
           "noise escapes from its throat, evidence of the power which "+
           "is contained within the dragon's massive body.\n");
  set_race("dragon");
  set_size(5);
  set_al(-800);
  set_ac(9);
  add_money(3448);
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
    if(random(7))
      ::attack();
    i--;
  }

  if(::attack() && !random(3)) {
    vic = all_inventory(ENV(TO));
    for(i=0, sz=sizeof(vic); i<sz; i++) {
      if(living(vic[i]) && (vic[i] != TO)) {
        vic[i]->hit_player(70+random(50));
        TELLR(ENV(TO), "The blue dragon breathes a "+
              "cloud of electric bolts into the area!\n");
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
  if(ele  && intp(ele) && (int)ele == (int)2)
     return ::hit_player(0, kind, ele);
     return ::hit_player(dam, kind, ele);
}
