inherit "obj/treasure";

reset(arg) {
  if (!arg) {
    set_id("book");
    set_short("A leather-bound book");
    set_value(10);
  }
}

id_quest(str) { return str=="aristotele's book"; }
