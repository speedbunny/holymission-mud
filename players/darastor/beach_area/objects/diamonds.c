inherit "/obj/treasure";
reset(arg) {
  ::reset(arg);
  if(!arg) {
     set_name("diamonds");
     set_alias("stones");
     set_short("Some diamonds");
     set_long("A handful of diamonds. They must be very"
9
+             "valuable to the right person.\n");
     set_value(1000);
     set_weight(1);
   }
  }
