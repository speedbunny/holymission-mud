inherit "obj/container";

reset(arg) {
    ::reset(arg);
    if (!arg) {
      set_weight(1);
      set_max_weight(6);
      set_value(12);
      set_name("skeleton");
      set_long("A battered and charred skeleton.\n");
      set_can_close(1);
    }
}
 
