inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  this_object()->set_name("jacket");
  this_object()->set_alias("jacket");
  this_object()->set_type("armour");
  this_object()->set_ac(2);
  this_object()->set_short("A special race jacket");
  this_object()->set_long("A jacket especially designed for your race.\n");
  this_object()->set_value(0);
  this_object()->set_weight(2);
  this_object()->set_info("jacket (created by Jug using Uranus' Wand)");
  return 1;
}

query_objmaker() { return 1; }

drop(silently) {
	::drop(silently);
    destruct(this_object());
    return 1;
}
