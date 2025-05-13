inherit "/obj/treasure";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("red cocoon");
  set_alias("cocoon");
  set_short("A red cocoon");
  set_long("The cocoon of a red demon, preparing for life in the Holy Mission.\n");
}

