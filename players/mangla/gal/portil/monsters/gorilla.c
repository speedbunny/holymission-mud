inherit "obj/monster";

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("gorilla");
      set_alt_name("terrified gorilla");
      set_short("A terrified gorilla");
      set_long("She looks scared and very strong.\n");
      set_gender(2);
      set_level(40);
      set_aggressive(1);
      set_al(100);
      set_wc(18);
      set_ac(9);
      }
