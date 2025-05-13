inherit "obj/monster";

#include "/obj/obj_defs.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("black dragon");
  set_no_steal(1);
  set_level(18);
  set_wc(19);
  set_alt_name("black");
  set_short("A big black dragon");
  set_long("You see a big black dragon.  It looks extremly dangerous.  "+
           "Green ichor dribbles slowly from its open, fanged mouth.  A "+
           "hideous half-grin seems to adorn its visage.  Slowly, its long "+
           "black tongue licks slowly across its scaly lips, as if "+
           "pondering how you'll taste.\n");
  set_race("dragon");
  set_size(5);
  set_al(-600);
  set_ac(6);
  add_money(508);
  if(objectp(ENV())) {
    TELLR(ENV(), "Suddenly a big dark shadow lands next to you.\n");
  }
}


int attack() {
  object *vic;
  int    i, sz;

  i = 1;

  while(i) {
    if(random(6))
      ::attack();
    i--;
  }

  if(::attack() && !random(3)) {
    vic = all_inventory(ENV(TO));
    for(i=0, sz=sizeof(vic); i<sz; i++) {
      if(living(vic[i]) && (vic[i] != TO)) {
        vic[i]->hit_player(50+random(50));
        TELLR(ENV(TO), "The black dragon breathes an "+
              "acidic cloud into the area!\n");
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
