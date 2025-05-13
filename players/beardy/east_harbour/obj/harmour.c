inherit "obj/armour";

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_name("mail");
    set_alias("plate mail");

    set_short("plate mail");
    set_long("It's a normal good looking plate mail.\n");

    set_size(0);

    set_type("armour");
    set_ac(4);
    set_value(2000);
    set_weight(7);
  }
}
