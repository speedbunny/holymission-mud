inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
    if (!arg) {
      
      set_name("cloak");
      set_alias("thieves cloak");
      set_type("cloak");
      set_ac(1);
      set_size(0);
      set_weight(1);
      set_value(100);
      set_short("A thieves cloak");
      set_long("A cloak made specially for thieves.\n");
	}
}
