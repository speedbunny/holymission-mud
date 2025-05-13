inherit "obj/monster";
#include "/players/tuppence/include/defs.h"
object money;
void reset(int arg) {
::reset(arg) ;
if(!arg) {
set_name("silthar");
set_race("monster");
set_short("Silthar the moat monster");
set_long("Silthar sits here guarding the entrance to her nest. She will let no\n"+
	 "one pass. You had better leave before she attacks you!\n");
set_alias("silthar");
set_level(80);
set_al(-700);
set_ac(18);
set_wc(30);
money = clone_object("obj/money.c");
money->set_money(5000);
transfer(money,this_object());
set_spell_mess1("Silthar breaths acid breath at her attacker!\n");
set_spell_mess2("Silthar breaths acid breath at you!\n");
set_chance(30);
set_spell_dam(30);
}
}
void init() {
::init();
add_action("_portal","portal");
}
_portal() {
write("You try to enter the portal but silthar stops you!\n");
return 1;
}
