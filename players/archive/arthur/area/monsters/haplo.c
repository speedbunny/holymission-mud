#include "/players/arthur/defs/ardefs.h"
inherit "obj/monster"
;

reset(arg) {
   ::reset(arg);
   if(!arg) {
   set_name("Haplo");
   set_alias("haplo");
   set_alt_name("haplo");
   set_level(1);
   set_race("human");
    set_short("Haplo");
   set_al(1);
   set_long("This looks like Haplo, Yep Haplo.\n");
    set_spell_dam(random(10));
   set_chance(10);
   set_spell_mess1("Haplo slaps you!\n");
   set_spell_mess2("Slap!\nYou are slaped by Haplo.\n");
}
}
