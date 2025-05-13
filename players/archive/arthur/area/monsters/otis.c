#include "/players/arthur/defs/ardefs.h"
inherit "obj/monster"
;

reset(arg) {
   ::reset(arg);
   if(!arg) {
   set_name("Armageddon");
   set_alias("armageddon");
   set_alt_name("Armageddon");
   set_level(1);
   set_race("Armageddon");
    set_short("Armageddon the game crasher");
   set_al(1);
   set_long("This bird looks like it belongs to Tuppence.\n");
    set_spell_dam(random(10));
   set_chance(10);
   set_spell_mess1("The bird pecks you!\n");
   set_spell_mess2("PECK PECK\nYou are pecked on the head by Otis.\n");
}
}
