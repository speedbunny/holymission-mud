inherit "/obj/container";

void reset(int arg) {
  ::reset(arg);
  if (!arg) {
    set_name("serving tray");
    set_alias("tray");
    set_max_weight(6);
    set_short("A silver serving tray");
    set_long("A highly polished silver serving tray.\n");
    set_value(0);
    set_weight(1);
  }
}


