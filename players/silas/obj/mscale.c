inherit "/obj/treasure";

reset(arg) {
  if (arg) return 1;
  set_id("scale");
  set_short("mermaid scale");
  set_long("This is a shiny scale from a mermaid. It might be worth something.\n");
  set_value(400);
  set_weight(1);
  return 1;
}

