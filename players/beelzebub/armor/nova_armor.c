

  inherit "/obj/armour";

  void reset(int flag) {
     ::reset(flag);
     if (flag == 0) {

        set_name("Nova Armor");
        set_alias("armor");
        set_short("Nova Armor");
        set_long("This armor was forged in the fires that created the universe.  Before Belix\n" +
                 "turned evil, he was the guardian of this armor.  Now that you have it, use it\n" +                 
                 "wisley, for it is one of the four strongest armors in the Netherworld.\n");
        set_ac(6);
        set_type("armour");
        set_value(6000);
        set_weight(4);
     }
  }

