inherit "obj/monster";

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("dragon");
      set_alt_name("young dragon");
      set_short("A young dragon");
      set_long("He looks strong and dangerous.\n");
      set_gender(1);
      set_level(55);
      set_aggressive(1);
      set_al(-200);
      }
