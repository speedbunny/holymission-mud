#include "/players/arthur/defs/ardefs.h"
inherit "obj/monster";
object cane;

reset(arg) {
   ::reset(arg);
   if(!arg) {
   set_name("A Vlusa Raptor");
   set_alias("raptor");
   set_alt_name("A Vlus Raptor");
   set_level(30);
   add_money(250+random(200));
   set_race("dino");
   set_wc(20);
   set_ac(50);
   set_hp(3000);
   set_short("A Vlusa Raptor");
   set_long("This is a Huge Raptor. You have the feeling that it isn't a good\n"+
   "idea to hang around him for a long time.\n");
   set_spell_dam(random(100));
   set_chance(20);
   set_spell_mess1("The Raptor makes a side attack.");
   set_spell_mess2("The Raptor attacks you from the side.");
}
}
