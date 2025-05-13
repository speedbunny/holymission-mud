inherit "obj/monster";
object money;
void reset(int arg) {
    ::reset(arg);
    if(!arg){
	set_name("rat");
	set_race("rat");
	set_aggressive(1);
	set_short("A red rat");
	set_long("A big red rat, with yellow piercing eyes.\n");
	set_alias("rat");
	set_level(15);
	set_al(-15);
	set_ac(6);
	set_wc(16);
	money = clone_object("obj/money.c");
	money->set_money(50);
	transfer(money,this_object());
    }
}
