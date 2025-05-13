inherit "/obj/armour";

void reset(int flag) {

  ::reset(flag);
  if (flag == 0) {
        set_name("brasses");
        set_short("Brasses");
        set_long("A charm worn put on horses to ward off the evil eye.\n");
        set_ac(1);
        set_size(4);
        set_type("amulet");
        set_value(47);
        set_weight(1);
  }
}
