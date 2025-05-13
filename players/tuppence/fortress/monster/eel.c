inherit "obj/monster";
object money;
void reset(int arg) {
::reset(arg);
if(!arg) {
set_name("electric eel");
set_race("eel");
set_short("Electric eel");
set_long("This Electric eel seems to glow with electrical energy.\n");
set_alias("eel");
set_level(20);
set_al(-200);
set_ac(10);
set_wc(25);
set_spell_mess1("Eel snaps his tail at his attacker!\n");
set_spell_mess2("Eel snaps lightning bolts at you with his tail!\n");
set_chance(30);
set_spell_dam(20);
money = clone_object("obj/money.c");
money->set_money(2500);
transfer(money,this_object());
}
}
