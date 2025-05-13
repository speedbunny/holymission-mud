inherit "obj/armour";

  reset(arg) {
    ::reset(arg);
    
  if (arg) return;
  
  set_name("fhat");
  set_alias("hat");
  set_short("A funny hat");
  set_long("A really funny, red hat.\n");
  set_type("helmet");
  set_ac(0);
  set_weight(1);
  set_value(40);
  }
  
  drop() {
    write("Your hat vanishes.\n");
    destruct(this_object());
    return 1;
    }
    
