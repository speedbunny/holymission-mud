inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("toucan");
   set_level(8);
   set_wc(10);
   set_ac(2);
   set_al(0);
   set_gender(1);
   set_race("bird");
   set_short("Toucan");
   set_long("The toucan is a large multi colored bird.  Its bill alone is\n"+
            "yellow, orange, green, and black.  It appears to be very strong\n"+
            "and dexterous.\n");
}
