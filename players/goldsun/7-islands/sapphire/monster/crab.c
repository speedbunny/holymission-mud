inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("crab");
set_race("animal");
set_short("A sea crab");
set_long("A sea ugly crab.\n");
set_level(5);
set_wc(9);
set_ac(5);
set_size(2);
set_aggressive(1);
set_al(-50);
}

