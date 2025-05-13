#include "/players/arthur/defs/ardefs.h"
inherit "obj/monster"
;
object cane;

reset(arg) {
   ::reset(arg);
   if(!arg) {
   set_name("A very old lady");
   set_alias("lady");
   set_alt_name("a very old lady");
    set_level(1000);
  add_money(1000000000);
   set_race("human");
   set_short("A very old lady");
   set_al(100000);
   set_long("She looks very old, possably even your grandmother.\n"+
   "You don't think that beating on a poor defenssless old woman could be worth\n"+
   "much, except for the few pennies that she has saved for her burial.\n");
   set_spell_dam(random(100));
   set_chance(10);
   set_spell_mess1("The old lady catches "+TPN+" around the neck with her cane.\n");
   set_spell_mess2("You are choked by the old lady's cane!\n");
   cane=clone_object(AOBJ+"cane");
   move_object(cane,this_object());
   init_command("wield cane");
}
}
