inherit "obj/armour";

  reset(arg) {
   ::reset(arg);
   if (arg) return;

    set_id("amulet");
    set_alias("monks amulet");
    set_short("A monks amulet");
    set_long("A holy protection amulet\n");
    set_type("amulet");
    set_ac(1);
    set_size(1);
    set_value(200);
    set_weight(1);
    }
    query_monk_wear() { return 1; }
