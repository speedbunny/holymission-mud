inherit "/obj/armour";

reset(arg) {

   ::reset(arg);
   if (!arg) {
     set_name("cape");
     set_short("Fortinbras's cape");
     set_long("This long flowing cape is the cape of the prince of Norway.  It is lined with \n"+
                "ermine fur to keep the prince warm.\n");
     set_ac(5);
     set_size(3);
     set_type("armor");
     set_value(1000);
     set_weight(4);
  }
}
