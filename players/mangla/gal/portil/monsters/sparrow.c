inherit "obj/monster";

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("sparrow");
      set_alt_name("bird");
      set_short("A little bird");
      set_long("A small sparrow playing in the bird bath.\n");
      set_gender(0);
      set_level(4);
      set_whimpy(10);
      set_al(20);
      set_wc(6);
      set_ac(0);
      move_object(clone_object("players/portil/monstobj/spclaw"),this_object());
      command("wield claw");
      }
