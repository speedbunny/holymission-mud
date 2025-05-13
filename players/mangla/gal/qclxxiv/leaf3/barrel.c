inherit "obj/container";

reset(arg) {
    ::reset(arg);
    if (!arg) {
      set_weight(5);
      set_max_weight(20);
      set_value(25);
      set_name("barrel");
      set_short("An old barrel");
      set_long("An old oaken barrel. It is open from the top.\n");
      set_can_close(0);
    }
}

