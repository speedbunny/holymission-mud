inherit "/obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return 1;
   set_type("arm");
   set_name("kote");
   set_ac(1); 
   set_short("A pair of Kote");
   set_long("A pair of armored sleeves that reach from the shoulders to\n"+
      "to the backs of the hands.\n");
   set_value(500);
   set_weight(5);
   return 1;
}


