inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Monster");
    set_alias("A Monster");
    set_alt_name("A monster");
    set_race("monster");
    short_desc="Monster";
    long_desc="A MEAN monster.\n";
    set_aggressive(0);
    set_level(1);
    set_wc(1);
    set_ac(1);
    set_al(100);
    set_hp(100);
    move_object(clone_object(PATH + "basicarmour"),this_object());
    move_object(clone_object(PATH + "basicweapon"),this_object());
    command("wear armour");
    command("wield weapon");
  }
  return 1;
}

init(){
  ::init();

TO->set_invis();
return 1;
}
