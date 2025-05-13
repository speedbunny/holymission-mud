inherit "/obj/treasure";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("blue cocoon");
  set_alias("cocoon");
  set_short("A blue cocoon");
  set_long("The cocoon of a blue demon, preparing for life in the Holy Mission.\n");
}
