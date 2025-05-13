inherit "obj/monster";
object money;
void reset(int arg) {
    ::reset(arg);
    if(!arg){
	set_name("shadow creeper");
	set_aggressive(1);
	set_race("creep");
	set_short("Shadow creeper");
	set_long("This is a shadow creeper, he creeps out of the shadows to feast\n"+
	  "on the living.\n");
	set_alias("creeper");
	set_level(22);
	set_al(-500);
	set_ac(11);
	set_wc(25);
	money = clone_object("obj/money.c");
	money->set_money(800);
	transfer(money,this_object());
    }
}
