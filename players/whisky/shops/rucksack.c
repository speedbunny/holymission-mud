inherit "obj/container";

reset(arg) {

  ::reset(arg);
  if (arg) return;
    set_name("rucksack");
    set_alias("sack");
    set_max_weight(15);
    set_short("A rucksack");
    set_long("What will a woodchuck do if a woodchuck chucks some wood.\n");
    set_value(25);
    set_weight(1);
}
