inherit "/obj/monster";
reset(arg) {
  ::reset(arg);
     if (arg) return 1;
     set_name("basilisk");
     set_short("Basilisk");
     set_long("This creature is very deadly. He likes to bite ankles.\n");
     set_level(15);
    set_wc(30);
      add_money(1213);
     set_al(-50);
     set_aggressive(0);
     return 1;
     }
