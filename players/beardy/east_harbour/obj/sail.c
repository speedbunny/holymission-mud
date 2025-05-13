inherit "obj/thing";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("sail");
    set_alt_name("fock");

    set_short("a fock");
    set_long("It's a small sail used in front of the boats.\n");

    set_value(50);
    set_weight(5);
  }
}
