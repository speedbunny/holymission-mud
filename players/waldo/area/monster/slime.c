inherit "obj/monster";
object money;
reset(arg){
    ::reset(arg);
    if(!arg){
	set_name("slime");
	set_race("ooze");
	set_short("Big black slime");
	set_long("This is some big black slime with big spikes coming out of it.\n");
	set_alias("slime");
set_level(2 + random(8) );
	set_al(-23);
	money = clone_object("obj/money.c");
money->set_money(query_level(this_object())*75);
	move_object(money,this_object());
    }
}
