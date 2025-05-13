

  inherit "/obj/armour";

  void reset(int flag) {
     ::reset(flag);
     if (flag == 0) {

        set_name("Dragonskin");
        set_alias("dragonskin");
        set_short("Dragonskin");
        set_long("This is the skin of a mighty dragon.  It can be worn \n" +
                 "as protection against other monsters.\n");                 
        set_ac(4);
        set_type("armour");
        set_value(5000);
        set_weight(3);
     }
  }

