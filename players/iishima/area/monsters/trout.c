inherit "obj/monster";

void reset(int arg){
::reset(arg);
if (arg) return;
set_name("trout");
set_race("fish");
set_short("A trout");
set_alias("trout");
set_long("A beautiful trout.\n");
set_level(2);
set_hp(60);
}
