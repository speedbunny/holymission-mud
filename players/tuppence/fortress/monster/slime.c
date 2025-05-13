inherit "obj/monster";
object money;
void reset(int arg) {
    ::reset(arg);
    if(!arg){
	set_name("slime");
	set_race("ooze");
	set_short("Big black slime");
	set_long("This is some big black slime with big spikes coming out of it.\n");
	set_alias("slime");
	set_level(18);
	set_al(-23);
	set_ac(8);
	set_wc(19);
	money = clone_object("obj/money.c");
	money->set_money(500);
	transfer(money,this_object());
    }
}
