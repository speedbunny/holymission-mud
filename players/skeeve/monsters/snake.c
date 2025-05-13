inherit "/obj/monster";

#include "/players/skeeve/area.h"
#include "/players/skeeve/code.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("snake");
    set_alias("black snake");
    set_short("A black snake");
    set_long("It darts with it's tongue. Maybe it's a mamba?\n");
    set_race("reptile");
    set_level(16);
    set_hp(900);
    set_sp(0);
    set_al(-500);
    set_wc(16);
    set_ac(3);
    set_size(2);
    set_aggressive(0);
    set_no_steal();
    set_whimpy(-1);
  }
  if (!present("ruby",this_object())) {
    object ruby;
    transfer(ruby = clone_object("obj/treasure"),this_object());
    ruby->set_id("ruby");
    ruby->set_short("A ruby");
    ruby->set_long("A beautiful ruby. Worth selling!\n");
    ruby->set_value(900);
    ruby->set_weight(1);
  }
  ARMOUR("snake skin","snake_skin",this_object());    
}
