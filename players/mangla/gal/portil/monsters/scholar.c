inherit "obj/monster";

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("scholar");
      set_alt_name("student");
      set_short("A scholar");
      set_long("He is a student at this University.\n");
      set_gender(1);
      set_level(15);
      set_al(20);
      set_wc(15);
      set_ac(6);
      }
