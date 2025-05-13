inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("peasant");
   set_level(2);
   set_wc(6);
   set_ac(1);
   set_al(25);
   set_gender(1);
   set_race("human");
   set_short("Peasant");
   set_long("The peasant is running for his life.  What he thought would be\n"+
            "good fun has turned into disaster.  He is wearing tattered rags.\n");
   add_money(25);
}

