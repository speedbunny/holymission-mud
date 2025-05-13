inherit "/obj/treasure";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("indigo cocoon");
  set_alias("cocoon");
  set_short("A indigo cocoon");
  set_long("The cocoon of a indigo demon, preparing for life in the Holy Mission.\n");
}
