inherit "/obj/armour";

void reset(int flag) {

   ::reset(flag);
   if (flag == 0) {
        set_name("earring");
        set_short("A malachite earring");
        set_long("A malachite earring worn for luck, protection, and prosperity.\n");
        set_ac(1);
        set_type("ear");
        set_size("any");
        set_value(47);
        set_weight(1);
   }
}
