inherit "obj/monster";

void reset(int arg){
::reset(arg);
if (arg) return;
set_name("huge bear");
set_race("bear");
set_short("A huge bear");
set_wc(5);
set_alias("bear");
set_long("A huge black bear. He has razor sharp teeth and looks hungry.\n");
set_level(11);
set_hp(155);
set_gender(1);
}

