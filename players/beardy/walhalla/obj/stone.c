inherit "obj/thing";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("stone");

    set_short("large stone");
    set_long("It's a large heavy stone.\n");

    set_weight(6);
  }
}
