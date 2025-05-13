inherit "obj/monster";
object money;
void reset(int arg) {
::reset(arg);
if(!arg) {
set_name("master mage");
set_race("human");
set_short("Master mage");
set_long("This master mage looks like he has been wielding magic for a very\n"+
	 "long time. You had better not attack him.\n");
set_alias("mage");
set_level(20);
set_al(-200);
set_ac(10);
set_wc(19);
set_spell_mess1("Master mage hits his attacker with a pink ray!\n");
set_spell_mess2("Master mage hits you with a HUGE pink ray!\n");
set_chance(40);
set_spell_dam(20);
money = clone_object("obj/money.c");
money->set_money(2000);
transfer(money,this_object());
}
}
