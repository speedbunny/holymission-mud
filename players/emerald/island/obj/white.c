inherit "obj/monster";

#include "/obj/obj_defs.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("white dragon");
  set_no_steal(1);
  set_level(30);
  set_wc(25);
  set_alt_name("white");
  set_hp(900);
  set_short("A huge white dragon");
  set_long("You see a huge white dragon.  It looks extremly dangerous.  "+
           "Frosty breath coils lazily out of its two great nostrils.  "+
           "Chilly green eyes gaze at your puny form, while the light "+
           "glints evilly off its sharp talons.\n");
  set_race("dragon");
  set_size(5);
  set_al(-150);
  set_ac(7);
  add_money(1800);
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

  i = 2;

  while(i) {
    if(random(10))
      ::attack();
    i--;
  }

  if(::attack() && !random(3)) {
    vic = all_inventory(ENV(TO));
    for(i=0, sz=sizeof(vic); i<sz; i++) {
      if(living(vic[i]) && (vic[i] != TO)) {
        vic[i]->hit_player(60+random(60));
        TELLR(ENV(TO), "The white dragon breathes a "+
              "storm of ice crystals into the area!\n");
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
  if(ele && (int)3 == (int)ele)
     return ::hit_player(0, kind, ele);
     return ::hit_player(dam, kind, ele);
}

