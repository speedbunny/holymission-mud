inherit "/obj/treasure";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("violet cocoon");
  set_alias("cocoon");
  set_short("A violet cocoon");
  set_long("The cocoon of a violet demon, preparing for life in the Holy Mission.\n");
}
