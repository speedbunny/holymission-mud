inherit "/obj/armour";
 
reset(arg) {
  ::reset(arg);
  if(!arg) {
      set_name("T-shirt");
      set_id("T-shirt");
      set_alias("shirt");
      set_ac(1);
	  set_short("A Jackpot Junkie T-shirt");
      set_long("A dirty T-shirt from a Jackpot Junkie.\n");
      set_value(50);
      set_weight(1);
  }
}
