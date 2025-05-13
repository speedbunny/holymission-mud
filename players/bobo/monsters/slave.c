inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("slave");
   set_level(1);
   set_wc(5);
   set_ac(0);
   set_al(50);
   set_gender(1);
   set_race("human");
   set_short("Slave");
   set_long("This is one of the slaves of the colliseum.  This miserable\n"+
            "excuse for a man is scared stiffless and would really like to "+
            "rescued.\n");
   add_money(10);
}

