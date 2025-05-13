inherit "obj/container";

reset(arg) {
    ::reset(arg);
    if (!arg) {
      set_weight(1);
      set_max_weight(6);
      set_value(12);
      set_name("bag");
      set_long("A bag.\n");
      set_can_close(1);
    }
}
 
