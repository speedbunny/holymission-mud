inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("seahorse");
    set_alias("fish");
    set_level(5);
    set_short("A black seahorse");
    set_long("A cute little black seahorse.\n");
}
