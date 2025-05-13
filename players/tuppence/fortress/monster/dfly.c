inherit "obj/monster";
object money;
void reset(int arg) {
::reset(arg);
if(!arg){
set_name("dragon fly");
set_race("fly");
set_short("Small dragon fly");
set_long("A small red dragon fly buzzing around your head annoyingly, kill it!\n");
set_alias("fly");
set_level(8);
set_al(300);
set_ac(3);
set_wc(7);
money = clone_object("obj/money.c");
money->set_money(600);
transfer(money,this_object());
}
}
