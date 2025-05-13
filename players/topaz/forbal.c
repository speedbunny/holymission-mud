inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Monster");
    set_alias("A Monster");
    set_alt_name("A monster");
    set_race("monster");
    short_desc="A mean monster";
    long_desc="A MEAN monster.\n";
    set_aggressive(0);
    set_level(1);
    set_wc(1);
    set_ac(1);
    set_al(100);
    set_hp(2000);
    move_object(clone_object(PATH + "b/basicarmour"),this_object());
    move_object(clone_object(PATH + "b/basicweapon"),this_object());
    command("wear armour");
    command("wield weapon");
  }
  return 1;
}

attack() {
 if(this_object()->query_attack()) {
  say("The Monster says: You idiot!  You can't attack me here!\n");
  say("The monsters disappears!\n");
  move_object(this_object(),"/players/topaz/workroom");
  return 1;
 }
 ::attack();
}
