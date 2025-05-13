inherit "/obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return 1;
   set_type("leg");
   set_name("sune-ate");
   set_alias("suneate");
   set_ac(1); 
   set_short("A pair of Sune-Ate");
   set_long("This is a pair of shin guards, extending from the ankle to\n"+
      "the knees.  It is made of splints of metal wrapped around the leg.\n");
   set_value(150);
   set_weight(5);
   return 1;
}


