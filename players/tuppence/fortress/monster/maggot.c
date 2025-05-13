inherit "obj/monster";
object money;
void reset(int arg) {
::reset(arg);
if(!arg) {
set_name("maggot");
set_race("bug");
set_short("Maggot");
set_long("A large maggot sits here.\n");
set_alias("maggot");
set_level(20);
set_al(-300);
set_ac(10);
set_wc(25);
money = clone_object("obj/money.c");
money->set_money(500);
transfer(money,this_object());
}
}
