inherit "obj/monster";
void reset(int arg) {
::reset(arg);
if(!arg){
set_name("red monk");
set_race("human");
set_short("Red monk");
set_long("This red monk dwells in the magic of fire. There is a golden glow\n"+
	 "around him.\n");
set_alias("monk");
set_level(17);
set_al(400);
set_ac(8);
set_wc(18);
set_spell_mess1("Red monk hits his attacker with a big circle of fire.\n");
set_spell_mess2("Red monk hits you with a big circle of fire!\n");
set_chance(30);
set_spell_dam(17);
}
}
