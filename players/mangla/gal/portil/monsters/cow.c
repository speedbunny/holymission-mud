inherit "obj/monster";

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("cow");
      set_alt_name("fat cow");
      set_short("A fat cow");
      set_long("It is eating the lush grass that lies here.\n");
      set_gender(0);
      set_level(10);
      set_al(0);
      }
