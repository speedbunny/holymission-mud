inherit "obj/monster";

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("worm");
      set_alt_name("earthworm");
      set_short("An earthworm");
      set_long("A tiny little worm.\n");
      set_gender(0);
      set_level(1);
      set_al(5);
      set_wc(3);
      set_ac(3);
         }
