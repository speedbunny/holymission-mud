inherit"obj/weapon";

reset(arg)
{ if(!arg)
  { set_id("broom");
    set_name("broom");
    set_alt_name("maidbroom");
    set_alias("broom");
    
    set_short("maid's broom");
    set_long("A new broom sweeps clean, and\n"+
              "this is a new one.\n");
    set_type(1);
    set_class(8);
    set_value(400);

    set_weight(1);
    
  }
}
