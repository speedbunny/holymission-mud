inherit "obj/monster";
object money;
void reset(int arg) {
::reset(arg);
if(!arg) {
set_name("pirhana");
set_aggressive(1);
set_race("fish");
set_short("Pirhana");
set_long("This pirhana may be small, but he packs a big bite!\n");
set_alias("pirhana");
set_level(19);
set_al(-600);
set_ac(9);
set_wc(20);
money = clone_object("obj/money.c");
money->set_money(500);
transfer(money,this_object());
}
}
