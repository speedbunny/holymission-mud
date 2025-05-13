inherit "/obj/thing";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("branch");
    set_short("A dry branch");
    set_long("A dry branch that will burn well.\n");
    set_weight(1);
    set_value(10);
  }
}
