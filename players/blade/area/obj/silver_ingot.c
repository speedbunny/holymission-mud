inherit "obj/treasure";

reset(arg) {
  ::reset(arg);
    if(arg) return;
    set_name("silver ingot");
    set_alias("silver");
    set_short("silver ingot");
    set_long("A very heavy silver ingot which looks valuable.\n");
    set_weight(5);
  }
