inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("servant");
   set_level(8);
   set_wc(10);
   set_ac(2);
   set_al(0);
   set_gender(1);
   set_race("human");
   set_short("Servant");
   set_long("This poor soul is an indentured servant, and has been for who\n"+
            "knows how long.  He is in raggy clothing that has several\n"+
            "holes in it.  He is rushing off somewhere.\n");
}
