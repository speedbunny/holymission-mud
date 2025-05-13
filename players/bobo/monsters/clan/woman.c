inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("lizard");
   set_level(5);
   set_wc(7);
   set_ac(1);
   set_al(0);
   set_gender(1);
   set_race("lizard");
   set_short("Lizard");
   set_long("This is a large green lizard.  He has a tough spiney hide and\n"+
            "a long prehensile tail.\n");
}
