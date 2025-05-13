inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("trout");
set_race("fish");
set_short("A trout");
set_long(
"A river trout swims strongly against the current, its supple form propelled "+
"forward my its powerful tail.  As the sun hits it from above its sides seem "+
"to shine like a rainbow.  All of a sudden, he jumps out of the water to catch "+
"a water strider.\n");
set_level(9);
set_wc(10);
set_ac(5);
set_size(2);
set_al(-50);
}

