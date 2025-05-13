

  inherit "/obj/armour";

  void reset(int flag) {
     ::reset(flag);
     if (flag == 0) {

        set_name("Plate Armor");
        set_alias("plate");
        set_short("Plate Armor");
        set_long("Plate Armor.\n");
        set_ac(3);
        set_type("armour");
        set_value(5000);
        set_weight(2);
     }
  }

