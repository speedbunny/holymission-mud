#include "/players/arthur/defs/ardefs.h"
inherit "obj/monster";
object cane;

reset(arg) {
   ::reset(arg);
   if(!arg) {
   set_name("A Tyrantisorous Rex");
   set_alias("rex");
   set_alt_name("A Tyrantisorous Rex");
   set_level(30);
   add_money(1000+random(2000));
   set_race("dino");
   set_wc(50);
   set_ac(200);
   set_hp(10000);
   set_short("A Tyrantisorous Rex");
   set_long("Watch where you walk! You may be stepped on smashing you to a bloody pulp\n"+
   "The fealing of power comming from the Rex almost makes you run out of this\n"+
   "room without seeing anything else.\n");
   set_spell_dam(random(100));
   set_chance(20);

   set_spell_mess2("The Tyrantisorous Takes a giant bite out of you!");
}
}
