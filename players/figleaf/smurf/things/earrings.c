inherit"obj/armour";

void reset(int arg) {

  ::reset(arg);
    if (arg)return;
    set_name("earrings");
    set_type("ear");
    set_short("Smurfette's earrings");
    set_long("A beautiful pair of diamond earrings.\n");
    set_weight(1);
    set_ac(0);
    set_value(84);
}
