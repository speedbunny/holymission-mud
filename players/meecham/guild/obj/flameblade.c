inherit "obj/weapon";
#include "func.c"

int level;

void reset(status arg) {
  if (arg) return;
  ::reset(arg);
  set_name("flameblade");
  set_alt_name("FlameBlade");
  set_alias("blade");
  set_weight(4);
  set_type(1);
  set_short("A flaming blade");
  set_long("A sword totally made of fire.\n");
  set_class(0);
// Mangla
  set_two_handed();
  set_hit_func(TO);
}       

wield(arg) {
  if (!TP->query_npc() && TP->query_guild() != 2) {
    write("You don't manage to hold the sword and it burns you hard.\n");
    TP->hit_player(20,7);
    return (1);
  }
  switch(LVL(TP)) {
    case 1..5     : set_class(7);  break;
    case 6..10    : set_class(9);  break;
    case 11..15   : set_class(11); break;
    case 16..19   : set_class(13); break;
    case 20..24   : set_class(15); break;
    case 25..28   : set_class(17); break;
    case 29       : set_class(19); break;
    case 30..1000 : set_class(20); break;
    default       : set_class(0);  break;
  }
  if (LLVL(TP)) set_class(weapon_class() + LVL(TP) / 3);      
  return (::wield(arg));
}

void dest_me() {
  destruct(TO);
  return;
}

int un_wield(){
  if(TP) write("The flaming sword disappears.\n");        
  call_out("dest_me",2);
  return 1;
}

void drop() {
  un_wield();
}

void set_level(int lvl) { level = lvl; }

/*
 * weapon_hit bonus is same as level
 * and legend_level/2
 */
int hit(object vic) {
   if (level < 30) return level;
   else return ((level-30)/2+30);
}
