inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("ant");
set_race("animal");
set_short("An ant");
set_long(
"A black ant.  It's six little legs are in constant motion as it moves "+
"around the area.  Its antennae move back and forth as it searches for "+
"food.\n"
  );
set_level(1);
set_wc(1);
set_ac(0);
set_size(1); 
}

