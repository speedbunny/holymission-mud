inherit"obj/armour";

void reset(int arg) {
    
  ::reset(arg);
    if (arg)return;
    set_name("robe");
    set_type("armour");
    set_short("Gargamel's robe");
    set_long("A dirty, patched black robe.\n");
    set_weight(1);
    set_ac(1);
    set_size("medium");
    set_value(54);
}
