inherit "obj/thing";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("chain");
    set_alias("chain");

    set_short("a chain");
    set_long("This chain is build for catching pleople.\n"+
             "You lots of hairs and blood-spills on it\n"+
	     "showing the use of it.\n");

    set_value(100);
    set_weight(2);
  }
}
