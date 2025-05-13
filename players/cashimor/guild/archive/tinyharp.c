inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("harp");
    set_short("A tiny silver harp");
    set_long("This is the brooch of membership of Taliesin.\n");
    set_ac(0);
    set_type("brooch");
    set_value(0);
    set_weight(0);
    set_info("The brooch Harp of the Guild of Bards.");
  }
}
