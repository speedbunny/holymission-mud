inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("howler monkies");
   set_alias("monkies");
   set_alt_name("howlers");
   set_level(9);
   set_wc(11);
   set_ac(3);
   set_al(0);
   set_gender(1);
   set_race("monkey");
   set_short("Black Howler Monkies");
   set_long("This is a group of eight Black howler monkies.  Each of them\n"+
            "is approximately two feet tall and totally black.  Fur covers\n"+
            "their entire body, except for their mouth.\n");
}
