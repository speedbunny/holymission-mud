inherit "/obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return 1;
   set_type("armor");
   set_name("hara-ate");
   set_alias("haraate");
   set_ac(2); 
   set_short("An Hara-ate");
   set_long("The hara-ate protects the front of the body down to the\n"+ 
      "thighs, but leaves the back open.\n");
   set_value(1000);
   set_weight(10);
   return 1;
}


