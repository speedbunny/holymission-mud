inherit "/obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return 1;
   set_type("helmet");
   set_name("kabuto");
   set_ac(2); 
   set_short("A great Kabuto");
   set_long("The Kabuto War Helm is the preferred headgear of the \n"+
      "Samurai.  It is highly ornate.\n");
   set_value(1000);
   set_weight(8);
   return 1;
}


