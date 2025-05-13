inherit "/obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return 1;
   set_type("boots");
   set_name("war boots");
   set_alias("boots");
   set_ac(1); 
   set_short("A pair of Samurai war boots");
   set_long("These boots are reinforced with metal plates and steel toes.\n"+
      "Samurai wear them as part of their riding gear.\n");
   set_value(250);
   set_weight(5);
   return 1;
}


