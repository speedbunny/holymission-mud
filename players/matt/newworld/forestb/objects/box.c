inherit "/obj/container";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("box");
  set_alias("small box");
  set_short("A small box");
  set_long("A small box that once was ornately crafted but has now " +
	   "decayed.\n");
  set_max_weight(1);
  set_can_close(1);
  set_closed();
  set_can_get(1);
}
