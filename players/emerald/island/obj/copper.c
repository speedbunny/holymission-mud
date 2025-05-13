inherit "obj/monster";

#include "/obj/obj_defs.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("copper dragon");
  set_no_steal(1);
  set_level(36);
  set_wc(28);
  set_alt_name("copper");
  set_hp(1200);
  set_short("A huge copper dragon");
  set_long("You see a huge copper dragon.  It looks extremly dangerous.  "+
           "It regards you with the nonchalant gaze of a creature who knows "+
           "that nothing on this world can possibly harm it.  A reddish "+
           "sheen glows from within its coppery scales, giving them the "+
           "lustre of a fire-polish.\n");
  set_race("dragon");
  set_size(5);
  set_al(200);
  set_ac(8);
  add_money(2592);
  set_dead_ob(TO);
  if(objectp(ENV())) {
    TELLR(ENV(), "Suddenly a big dark shadow lands next to you.\n");
  }
}

int monster_died(object ob) {
  object necklace;

  TELLR(ENV(), "As the dragon breathes its last breath, it disappears into\n"+
               "the shadows.  Only its scales remain, formed into a\n"+
               "glinting necklace.\n");
  necklace=clone_object("/players/emerald/island/obj/necklace");
  move_object(necklace,ENV());
  destruct(TO);
  return 1;
}

int attack() {
  object *vic;
  int    i, sz;

  i = 3;

  while(i) {
    if(random(12))
      ::attack();
    i--;
  }

  if(::attack() && !random(3)) {
    vic = all_inventory(ENV(TO));
    for(i=0, sz=sizeof(vic); i<sz; i++) {
      if(living(vic[i]) && (vic[i] != TO)) {
        vic[i]->hit_player(72+random(40));
        vic[i]->add_poison(36);
        TELLR(ENV(TO), "The copper dragon breathes a "+
              "cloud of cyanide into the area!\n");
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
  if(ele && intp(ele) && (int)ele == (int)9)
     return ::hit_player(0, kind, ele);
     return ::hit_player(dam, kind, ele);
}
