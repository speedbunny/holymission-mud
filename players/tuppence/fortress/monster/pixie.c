inherit "obj/monster";
object money;
void reset(int arg) {
    ::reset(arg);
    if(!arg) {
	set_name("evil pixie");
	set_aggressive(1);
	set_race("pixie");
	set_short("Evil pixie");
	set_long("This little evil pixie doesnt seem to like that you have entered here.\n");
	set_alias("pixie");
	set_level(17);
	set_al(-400);
	set_ac(8);
	set_wc(15);
	set_spell_mess1("Pixie throws some pixie dust up in the air.\n");
	set_spell_mess2("Pixie throws some dust into the air and in your eyes!\n");
	set_chance(30);
	set_spell_dam(15);
	money = clone_object("obj/money.c");
	money->set_money(1000);
	transfer(money,this_object());
    }
}
