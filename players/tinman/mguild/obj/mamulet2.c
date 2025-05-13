inherit "obj/armour";

  reset(arg) {
   ::reset(arg);
   if (arg) return;

    set_id("amulet");
    set_alias("monks amulet");
    set_short("A bright monks amulet");
    set_long("A holy protection amulet, which spends a strange\n"+
             "bright light. It has an inscripiton:\n\n"+
             "< I EVER FIND MY WAY IN DARKNESS !!!!>\n");
    set_type("amulet");
    set_arm_light(1);
    set_ac(1);
    set_value(800);
    set_weight(1);
    }
    query_monk_wear() { return 1; }
