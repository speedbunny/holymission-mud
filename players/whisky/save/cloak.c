inherit "obj/armour";

  reset(arg) {
  
    ::reset(arg);
    
  if (arg) return;
  
  set_name("fcloak");
  set_alias("cloak");
  set_short("A funny cloak");
  set_long("A funny blue cloak.\n");
  set_weight(1);
  set_value(40);
  set_type("cloak");
  set_ac(0);
  
  }
  
  
