inherit "obj/monster";

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("mouse");
      set_alt_name("drugged mouse");
      set_short("An odd looking mouse");
      set_long("It appears to be drugged.\n");
      set_gender(1);
      set_level(8);
      set_aggressive(1);
      set_al(0);
      set_wc(5);
      set_ac(3);
      }
