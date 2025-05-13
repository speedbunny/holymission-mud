inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("halfling father");
   set_alias("father");
   set_level(9);
   set_wc(11);
   set_ac(3);
   set_al(0);
   set_gender(1);
   set_race("halfling");
   set_short("Father");
   set_long("This halfling man is very tired but appears to be happy in\n"+
            "his little home.  He is cleaned up and is sitting at the table.\n");
   add_money(90);
}

