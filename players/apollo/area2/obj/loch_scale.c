

  inherit "/obj/armour";

  void reset(int flag) {
     ::reset(flag);
     if (flag == 0) {

        set_name("The Loch Ness Monster's scales");
        set_alias("scales");
        set_short("scales of a mysterious hidden monster");
        set_long("The scales from the Loch Ness Monster.\n");
        set_ac(2);
        set_type("armour");
        set_value(5000);
        set_weight(4);
     }
  }

