inherit "obj/monster";
object money;
void reset(int arg) {
    ::reset(arg);
    if(!arg){
	set_name("evil bat");
	set_race("bat");
	set_short("Evil bat");
	set_long("An evil bat with one red and one yellow eye.\n");
	set_alias("bat");
	set_aggressive(1);
	set_level(18);
	set_wc(19);
	set_ac(8);
	set_al(-400);
	money = clone_object("obj/monster.c");
	money->set_money(500);
	transfer(money,this_object());
    }
}
