inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("frog");
   set_level(3);
   set_wc(6);
   set_ac(1);
   set_al(0);
   set_gender(1);
   set_race("amphibian");
   set_short("Tree Frog");
   set_long("This is a small frog only about three inches long.  It is\n"+
            "yellow with red eyes.\n");
}
