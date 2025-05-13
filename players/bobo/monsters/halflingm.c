inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("halfling mother");
   set_alias("mother");
   set_level(6);
   set_wc(8);
   set_ac(2);
   set_al(50);
   set_gender(2);
   set_race("halfling");
   set_short("Mother");
   set_long("The halfling mother is busy in her little home taking care\n"+
            "of everything.  Her little aprom hiding all the tools she "+
            "uses.\n");
   add_money(75);
}
