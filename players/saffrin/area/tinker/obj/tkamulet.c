inherit "/obj/armour";

void reset(int flag) {

   ::reset(flag);
   if (flag == 0) {
        set_name("amulet");
        set_short("A lapis lazuli amulet");
        set_long("An amulet of lapis lazuli which is said to protect its wearer.\n");
        set_ac(1);
        set_size("any");
        set_type("amulet");
        set_value(47);
        set_weight(1);
   }
}
