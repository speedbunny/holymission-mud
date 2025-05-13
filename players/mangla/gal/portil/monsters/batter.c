inherit "obj/monster";

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_name("cricketer");
      set_alt_name("batter");
      set_short("A batter");
      set_long("A cricketer who is batting at the moment.\n");
      set_gender(1);
      set_level(16);
      set_al(40);
      set_wc(12);
      set_ac(8);
      move_object(clone_object("players/portil/monstobj/crickbat"),this_object());
      command("wield bat");
      }
