inherit "obj/thing";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("rod");

    set_short("fishing rod");
    set_long("It is a small fishing rod.\n");

    set_value(30);
    set_weight(1);
  }
}
