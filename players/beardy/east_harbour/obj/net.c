inherit "obj/thing";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("net");

    set_short("fishing net");
    set_long("It's a fishing net. Do you like fishing ?\n");

    set_value(10);
    set_weight(1);
  }
}
