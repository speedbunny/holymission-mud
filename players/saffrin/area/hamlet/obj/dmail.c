inherit "/obj/armour";

reset(arg) {

  ::reset(arg);
  if (!arg) {
     set_name("chainmail");
     set_short("Denmark Army's chainmail");
     set_long("The offical chainmail of the Denmark army.  It is gray in color and has double\n"+
                    "links along the front.\n");
     set_ac(2);
     set_type("armor");
     set_value(1000);
     set_weight(4);
  }
}
