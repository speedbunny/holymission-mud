inherit "obj/monster";

void reset(int arg){
::reset(arg);
if (arg) return;
set_name("large bear");
set_race("bear");
set_short("A large bear");
set_wc(2);
set_alias("bear");
set_long("A large black bear.  He looks angry and dangerous.\n");
set_level(10);
set_hp(140);
set_gender(1);
}

