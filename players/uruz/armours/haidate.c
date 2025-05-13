inherit "/obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return 1;
   set_type("hip");
   set_name("haidate");
   set_ac(1); 
   set_short("An Haidate skirt");
   set_long("The haidate is a laced apron that protects the thighs and\n"+
      "knees.  Large plates guard the front and sides.\n");
   set_value(750);
   set_weight(10);
   return 1;
}


