inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("crab");
set_race("crab");
set_short("A sea crab");
set_long("A sea crab. It is small and lightgray\nand looks very hungry.\n");
set_level(2);
set_wc(random(7)+1);
set_ac(3);
set_size(2);     
}

