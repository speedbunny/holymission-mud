inherit "obj/monster";

void reset(int arg){
::reset(arg);
if (arg) return;
set_name("bear");
set_race("bear");
set_short("A bear");
set_alias("bear");
set_long("A small black bear.  He looks friendly but he also looks dangerous.\n");
set_level(4);
set_hp(80);
}
