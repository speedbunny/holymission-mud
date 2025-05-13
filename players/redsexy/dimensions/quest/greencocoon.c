inherit "/obj/treasure";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("green cocoon");
  set_alias("cocoon");
  set_short("A green cocoon");
  set_long("The cocoon of a green demon, preparing for life in the Holy Mission.\n");
}
