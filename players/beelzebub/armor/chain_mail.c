

  inherit "/obj/armour";

  void reset(int flag) {
     ::reset(flag);
     if (flag == 0) {

        set_name("Chain Mail");
        set_alias("mail");
        set_short("Chain Mail");
        set_long("Chain Mail Armor. \n");
        set_ac(2);
        set_type("armour");
        set_value(5000);
        set_weight(2);
     }
  }

