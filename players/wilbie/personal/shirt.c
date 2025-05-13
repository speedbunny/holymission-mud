inherit "obj/armour";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("shirt");

   set_type("armour");
   set_short("A Holy Mission T-Shirt");
   set_long("This is a really nice Holy Mission T-Shirt.  It's made "+
            "of 100% cotton.\n");
   set_ac(0);
   set_weight(1);
   set_value(0);
}
