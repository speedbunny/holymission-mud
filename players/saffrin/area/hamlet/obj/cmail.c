inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
     set_name("chainmail");
     set_short("Courtier's chainmail");
     set_long("Chainmail that was woven from the finest gold to best suit the flashy courtier, \n"+
                "who known for his tacky tastes.\n");
     set_ac(3);
     set_size(3);
     set_type("armor");
     set_value(1000);
     set_weight(4);
  }
}
