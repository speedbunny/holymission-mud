inherit "/obj/armour";

void reset(int flag) {

  ::reset(flag);
  if (flag == 0) {
        set_name("talisman");
        set_short("A jade talisman");
        set_long("A jade talisman said to protect and bring about good luck.\n");
        set_ac(1);
        set_type("amulet");
        set_size("any");
        set_value(47);
        set_weight(1);
  }
}
