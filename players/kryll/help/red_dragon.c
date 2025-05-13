inherit "obj/monster";
 
#include "/obj/obj_defs.h"
 
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  set_name("red dragon");
  set_no_steal(1);
  set_level(35);
  set_wc(24);
  set_alt_name("red");
  set_short("A big red dragon");
  set_long("You see a big red dragon.  It looks extremly dangerous.\n");
  set_race("dragon");
  set_size(5);
  set_al(-1000);
  set_ac(12);
  add_money(2450);
  set_dead_ob(TO);
  if(objectp(ENV())) {
    TELLR(ENV(), "Suddenly a big dark shadow lands next to you.\n");
  }
}
 
int monster_died(object ob) {
  object scroll;
 
// Please do not use whisky's items...they will eventually be gone.
// For now give the monster nothing, or maybe a weapon or armour.
  scroll=clone_object("/players/whisky/obj/firesh_scroll");
  move_object(scroll,ENV());
  return 0;
}
 
int attack() {
  object *vic;
  int    i, sz;
 
  i = 3;
 
  while(i) {
    if(random(5))
      ::attack();
    i--;
  }
 
  if(::attack() && !random(3)) {
    vic = all_inventory(ENV(TO));
 
    for(i=0, sz=sizeof(vic); i<sz; i++) {
      if(living(vic[i]) && (vic[i] != TO)) {
        vic[i]->hit_player(27+random(7));
        TELLR(ENV(TO), "The red dragon breathes a "+
              "a blast of fire into the area!\n");
        return 1;
      }
    }
  }
  return 0;
}
 
int run_away() {
  return 0;
}
 
// This will have to be changed when hit_player changes.
// Just letting you know now.
varargs mixed hit_player(int dam, int kind, mixed *ele) {
  if(ele && (int)1 == (int)ele)
     return ::hit_player(0, kind, ele);
     return ::hit_player(dam, kind, ele);
}
