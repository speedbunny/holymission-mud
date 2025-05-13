inherit "obj/container";

reset(arg) {
    ::reset(arg);
    if (!arg) {
      set_weight(1);
      set_max_weight(18);
      set_value(35);
      set_name("suitcase");
      set_alias("rucksack");
      set_long("A suitcase, with belts to wear it on your back.\n");
      set_can_close(1);
    }
}

