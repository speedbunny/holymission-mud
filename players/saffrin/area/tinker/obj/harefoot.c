inherit "/obj/armour";

void reset(int flag) {

  ::reset(flag);
  if (flag == 0) {
        set_name("foot");
        set_short("A hare's foot");
        set_long("A hare's foot is carried for good luck and protection.\n");
        set_ac(1);
        set_size("any");
        set_type("other");
        set_value(47);
        set_weight(1);
  }
}
