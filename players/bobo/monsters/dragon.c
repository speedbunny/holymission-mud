inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("The Dragon");
   set_alias("dragon");
   set_level(35);
   set_wc(45);
   set_ac(20);
   set_al(-100);
   set_gender(1);
   set_race("human");
   set_short("Dragon");
   set_long("Standing before you is the mighty Dragon.  He is clothed in\n"+
            "a silk Gi that is multi colored and has oriental writing on\n"+
            "it.  He looks very menacing.\n");
   add_money(5000);
}

