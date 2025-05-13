inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
    set_name("jacket");
    set_type("armour");
    set_ac(2);
    set_size(2);
    set_short("A warm foxfur-jacket");
    set_alias("foxfur-jacket");
    set_long("A beautiful red jacket made from fox-fur.\n");
    set_value(40);
    set_weight(1);
  return 1;
}
