inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("mother duck");
set_alias("duck");
set_race("animal");
set_short("A Mother duck");
set_long(
"A small mother duck is frantically bopping about the room in search "+
"of her ducklings.  Her yellow feathers appear ruffled and she has a "+
"wild look in her eyes.  She occasionally quacks and clacks her beak.\n");
set_level(3);
set_gender(2);
set_wc(9);
set_ac(1);
set_size(2); 
set_aggressive(1);   
}

