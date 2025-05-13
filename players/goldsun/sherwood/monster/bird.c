inherit "/obj/monster";

void reset(int arg) {

    ::reset(arg);

    load_chat(10,({"Bird flies around your head.\n",
	           "Bird makes Chirps at you.\n"
                }));
  
    if (arg) return;

    set_name("bird");
    set_race("bird");
    set_short("A forest bird");
    set_long("A small forest bird.\n");
    set_level(1);
    set_gender(1);
    set_wc(1);
    set_ac(5);
}


