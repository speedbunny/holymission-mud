inherit "obj/monster";
object money;
void reset(int arg) {
::reset(arg);
if(!arg) {
set_name("charmed ivy");
set_aggressive(1);
set_race("plant");
set_short("Charmed ivy");
set_long("A magical charmed ivy.\n");
set_alias("ivy");
set_level(17);
set_al(-400);
set_ac(8);
set_wc(18);
money = clone_object("obj/money.c");
money->set_money(700);
transfer(money,this_object());
}
}
