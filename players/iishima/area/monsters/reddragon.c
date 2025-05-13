inherit "obj/monster";

void reset(int arg){
::reset(arg);
if (arg) return;
set_name("red dragon");
set_race("dragon");
set_short("Red dragon");
set_ac(4);
set_wc(6);
set_alias("dragon");
set_long("This red dragon has long, sharp teeth and huge evil eyes.\n");
set_level(15);
set_chance(15);
set_hp(220);
set_gender(1);
}
