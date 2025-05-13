inherit "obj/monster";
object money;
void reset(int arg) {
    ::reset(arg);
    if(!arg){
	set_name("blue blob");
	set_race("blob");
	set_short("Blue blob");
	set_long("Some blue slime has dripped off the walls and formed into a monster!\n");
	set_alias("blob");
	set_level(19);
	set_al(-50);
	set_ac(9);
	set_wc(20);
	money = clone_object("obj/money.c");
	money->set_money(500);
	transfer(money,this_object());
    }
}
