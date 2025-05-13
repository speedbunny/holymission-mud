inherit "obj/monster";
reset(arg) {
   ::reset (arg);
   if(arg) return;
   set_name("dragon guard");
   set_alias("guard");
   set_level(20);
   set_wc(30);
   set_ac(11);
   set_al(0);
   set_gender(1);
   set_race("human");
   set_short("Guard");
   set_long("The guard is wearing a white Karate Gi and is heavily muscled.\n"+
            "He looks passive, but also powerful at the same time.\n");
   add_money(1000);
}

void init() {
   ::init();
   add_action("_north","north");
}

_north() {
write("The guard stops you from going north.\n"+
      "The guard says: Hey, you're not allowed back there.\n");
   return 1;
}
