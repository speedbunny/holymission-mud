inherit "obj/monster";

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("orc skeleton");
      set_alt_name("skeleton");
      set_alias("orc");
      set_short("An orcs skeleton");
      set_long("It is the remains of an orc.\n");
      set_gender(0);
      set_aggressive(1);
      set_level(16);
      set_al(-100);
      set_wc(11);
      set_ac(4);
      }
