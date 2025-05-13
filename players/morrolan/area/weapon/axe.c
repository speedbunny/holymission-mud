
inherit "obj/weapon";

void reset (int arg)
{
  ::reset();
  set_name("pole axe");
  set_short("Celtic Pole Axe");
  set_alias("axe");
  set_class(18);
  set_type("axe");
  set_weight(4);
  set_value(2000);
  set_long("An impressive medieval weapon with a blade\n"+
           "on one side, and a hook on the other (just incase yayou miss.\n");
 }
