inherit "obj/monster";

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("orc");
      set_alt_name("dirty orc");
      set_short("A dirty orc");
      set_long("It is fed up of being held in the cell.\n");
      set_gender(0);
      set_level(25);
      set_aggressive(1);
      set_al(-200);
      }
