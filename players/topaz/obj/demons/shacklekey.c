inherit "obj/treasure";

reset(arg) {
  if(arg) return;
    set_id("key");
    set_alias("shackle key");
    set_short("An iron key");
    set_long("Looks like it would unlock shackles or something.\n");
    set_value(50);
    set_weight(1);
}
