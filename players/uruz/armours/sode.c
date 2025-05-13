inherit "/obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return 1;
   set_type("other");
   set_name("sode");
   set_ac(1); 
   set_short("A pair of Sode");
   set_long("This is a square piece of armor attached to the shoulders.\n"+
      "A Sode Jiruchi is tied on with the wearers family colors.\n");
   set_value(250);
   set_weight(3);
   return 1;
}


