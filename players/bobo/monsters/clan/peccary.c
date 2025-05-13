inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("peccary");
   set_level(6);
   set_wc(8);
   set_ac(2);
   set_al(0);
   set_gender(1);
   set_race("pig");
   set_short("Peaccary");
   set_long("The peccary is a large wild pig.  It is four feet long and has\n"+
            "large bristley fur covering much of its body.\n");
}
