inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
   ::reset(arg);
 if (arg) return;
 set_name("narguhl");
 set_level(3);
 set_aggressive(1);
 set_str(50);
 set_dex(50);
 set_hp(5);
 set_al(-999);
 set_gender(1);
 set_race("demon");
 set_short("A pulsing ball of energy");
 set_long("This is a Narghul.  It is a pulsating ball of pure evil "+
 "energy.\n");
 set_walk_chance(50);
 set_walk_limit("/players/wilbie/graveyard");
 set_wc(10);
 set_ac(1);
}
