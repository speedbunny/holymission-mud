inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("crab");
set_race("crab");
set_short("A sea crab");
set_long(
"A tiny hermit crab scurries around the area, dodging between your feet "+
"several times as he appears to be looking for something.  It is small "+
"and light gray.  It seems to be very hungry.\n");
set_level(2);
set_wc(random(7)+1);
set_ac(3);
set_size(2);     
}

