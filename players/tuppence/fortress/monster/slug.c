inherit "obj/monster";
object money;
void reset(int arg) {
::reset(arg);
if(!arg) {
set_name("Spotted slug");
set_race("slug");
set_short("Spotted slug");
set_long("A BIG spotted slug sticks to the fortress wall and looks at you with\n"+
	 "it's big blue eyes.\n");
set_alias("slug");
set_level(18);
set_al(300);
set_ac(6);
set_wc(19);
money = clone_object("obj/money.c");
money->set_money(1000);
transfer(money,this_object());
}
}
