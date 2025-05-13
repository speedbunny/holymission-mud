inherit "/obj/armour";

reset(arg) {

   ::reset(arg);
   if (!arg) {
     set_name("robe");
     set_short("The royal robe of the queen of Denmark");
     set_long("This is the royal robe of the queen of Denmark.  It is dark purple in color \n"+
                "to signify royalty nad is lined with warm fur.\n");
     set_ac(5);
     set_size(3);
     set_type("armor");
     set_value(1000);
     set_weight(4);
  }
}
