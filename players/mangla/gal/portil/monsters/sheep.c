inherit "obj/monster";

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("sheep");
      set_alt_name("wooly sheep");
      set_short("A wooly sheep");
      set_long("The wooly sheep is grazing on the grass.\n");
      set_gender(0);
      set_level(7);
      set_al(0);
      }
