inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("peasant");
   set_level(3);
   set_wc(5);
   set_ac(2);
   set_al(25);
   set_gender(1);
   set_race("human");
   set_short("Peasant");
   set_long("This peasant is a fat slob of a man.  His clothing is stained\n"+
            "and his gut is hanging out of his tunic.  He is also a coward\n"+
            "as he is looking for anywhere he can to hide.\n");
   add_money(25);
}

