inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("vulture");
set_race("bird");
set_short("An evil vulture");
set_long("An evil vulture. He is looking for lunch.\n");
set_level(20);
set_wc(18);
set_ac(3);
set_gender(1);
set_hp(query_hp()+1000);
set_size(3);
set_al(-90);
}

