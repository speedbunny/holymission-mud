inherit "obj/monster";
object money;
void reset(int arg) {
    ::reset(arg);
    if(!arg){
	set_name("Silver spider");
	set_race("spider");
	set_short("Silver spider");
	set_long("A big silver spider, watch out he looks mean.\n");
	set_alias("spider");
	set_level(17);
	set_al(-200);
	set_ac(8);
	set_wc(17);
	money = clone_object("obj/money.c");
	money->set_money(800);
transfer(money,this_object());
    }
}
