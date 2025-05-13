inherit "obj/food";

reset (arg) {
   ::reset (arg);
   if (!arg) {
      set_name("steak");
      set_short("Gorgurack steak");
      set_alias("steak");
      set_long("Large piece of well cooked meat off the gorgurack.\n");
      set_value(0);
      set_weight(2);
   }
}

