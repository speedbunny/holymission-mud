inherit "/obj/armour";

void reset(int flag) {

  ::reset(flag);
  if (flag == 0) {
        set_name("wreath");
        set_short("A wreath of roses");
        set_long("A wreath of beautiful roses with cream ribbons trailing from it.\n");
        set_ac(1);
        set_type("helmet");
        set_size(3);
        set_value(47);
        set_weight(1);
  }
}
