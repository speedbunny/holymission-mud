inherit "/obj/treasure";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("yellow cocoon");
  set_alias("cocoon");
  set_short("A yellow cocoon");
  set_long("The cocoon of a yellow demon, preparing for life in the Holy Mission.\n");
}
