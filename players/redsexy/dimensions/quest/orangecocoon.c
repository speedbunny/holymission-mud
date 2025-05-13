inherit "/obj/treasure";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("orange cocoon");
  set_alias("cocoon");
  set_short("A orange cocoon");
  set_long("The cocoon of a orange demon, preparing for life in the Holy Mission.\n");
}
