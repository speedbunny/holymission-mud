inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("bird");
   set_level(20);
   set_wc(30);
   set_ac(11);
   set_al(0);
   set_gender(1);
   set_race("omen");
   set_short("Bird");
   set_long("This is a large jet black bird.  It is unlike any other bird\n"+
            "in the area.  It's plumage seems to absorb light, its black\n"+
            "eyes seem to be looking at everything, and it's black beak\n"+
            "has decaying flesh rotting from its last meal.\n");
}
