inherit "/obj/weapon";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("club");
set_short("Big Wooden Club");
  set_long("This is Charlie's big wooden club.\n");
set_class(200);
set_value(10050);
  set_weight(5);
  set_info("club (created by Someone using Uranus' Wand)");
  return 1;
}

query_objmaker() { return 1; }
