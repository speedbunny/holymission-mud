inherit "obj/monster";

#include "/obj/obj_defs.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("green dragon");
  set_no_steal(1);
  set_level(16);
  set_wc(18);
  set_alt_name("green");
  set_short("A small green dragon");
  set_hp(520);
  set_long("You see a small green dragon.  It looks extremly dangerous.  "+
           "A thin wisp of foul-smelling vapour constantly leaks from its "+
           "nostrils as is watches you with huge, blood-red eyes.\n");
  set_race("dragon");
  set_size(5);
  set_al(-600);
  set_ac(9);
  add_money(502);
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
    if(random(4))
      ::attack();
    i--;
  }

  if(::attack() && !random(3)) {
    vic = all_inventory(ENV(TO));
    for(i=0, sz=sizeof(vic); i<sz; i++) {
      if(living(vic[i]) && (vic[i] != TO)) {
        vic[i]->hit_player(30+random(30));
        vic[i]->add_poison(8);
        TELLR(ENV(TO), "The green dragon breathes a "+
              "green gas cloud into the area!\n");
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
  if(ele && intp(ele) && (int)ele == (int)4)
     return ::hit_player(0, kind, ele);
     return ::hit_player(dam, kind, ele);
}
