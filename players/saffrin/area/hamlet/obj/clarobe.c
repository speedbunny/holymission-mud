inherit "/obj/armour";

reset(arg) {

  ::reset(arg);
  if (!arg) {
     set_name("robe");
     set_short("The royal robe of the king of Denmark");
     set_long("This is the royal robe of the king of Denmark.  It is dark purple in color to signfy\n"+
                "royalty.  There is fur lining the inside of the robe\n");
     set_ac(5);
     set_size(3);
     set_type("armor");
     set_value(1000);
     set_weight(4);
  }
}
