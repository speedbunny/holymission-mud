inherit "obj/container";

reset(arg) {
    ::reset(arg);
    if (!arg) {
      set_weight(1);
      set_max_weight(15);
      set_value(35);
 set_name("cloth pouch");
      set_alias("pouch");
      set_long("A cloth puch to go onto your belt.\n");
      set_can_close(1);
    }
}

