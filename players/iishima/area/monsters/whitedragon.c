inherit "obj/monster";

void reset(int arg){
::reset(arg);
if (arg) return;
set_name("white dragon");
set_race("dragon");
set_short("White dragon");
set_ac(7);
set_wc(12);
set_alias("dragon");
set_long("This white dragon has long, sharp teeth and huge evil eyes.\n");
set_level(16);
set_chance(15);
set_hp(240);
set_gender(1);
}
