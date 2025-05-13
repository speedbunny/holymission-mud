

  inherit "/obj/armour";

  void reset(int flag) {
     ::reset(flag);
     if (flag == 0) {

        set_name("Celestial Armor");
        set_alias("armor");
        set_short("Celestial Armor");
        set_long("This armor was created from the power of the heavens and sent to Molenubar \n" +
                 "to protect its people from the demon sorcerors.  In the last wizard war, it\n" +                 
                 "was stolen by Rahn. Use it wisley, for it may save your life.\n");
        set_ac(6);
        set_type("armour");
        set_value(6000);
        set_weight(4);
     }
  }

