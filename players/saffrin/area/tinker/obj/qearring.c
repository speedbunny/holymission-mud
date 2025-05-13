inherit "/obj/armour";

void reset(int flag) {

   ::reset(flag);
   if (flag == 0) {
        set_name("earring");
        set_short("A quartz crystal earring");
        set_long("A quartz crystal earring worn for protection.\n");
        set_ac(1);
        set_type("ear");
        set_size("any");
        set_value(47);
        set_weight(1);
   }
}
