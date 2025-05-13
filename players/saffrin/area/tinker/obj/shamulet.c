inherit "/obj/armour";

void reset(int flag) {

   ::reset(flag);
   if (flag == 0) {
        set_name("amulet");
        set_short("A quartz crytsal amulet");
        set_long("An amulet of quartz crystal which is said to amplify protection.\n");
        set_ac(1);
        set_size("any");
        set_type("amulet");
        set_value(47);
        set_weight(1);
   }
}
