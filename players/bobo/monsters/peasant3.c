inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("peasant");
   set_level(3);
   set_wc(6);
   set_ac(1);
   set_al(40);
   set_gender(1);
   set_race("human");
   set_short("Peasant");
   set_long("This is an average looking guy who has heard of the Father's\n"+
            "grief and has stopped to look for his child.\n");
   add_money(50);
}

