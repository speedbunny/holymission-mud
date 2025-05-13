inherit "/obj/armour";

void reset(int flag) {

   ::reset(flag);
   if (flag == 0) {
        set_name("earring");
        set_short("A lapis lazuli earring");
        set_long("A lapis lazuli earring worn for protection.\n");
        set_ac(1);
        set_type("ear");
        set_size("any");
        set_value(47);
        set_weight(1);
   }
}
