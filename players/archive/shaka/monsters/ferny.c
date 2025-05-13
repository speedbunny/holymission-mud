inherit "/obj/monster";

reset(arg) {
  ::reset(arg);

  if (!arg) {
    set_name("ferny");
    set_alias("bartender");
    set_alt_name("barkeeper");
    set_short("Ferny the bartender");
    set_long("Ferny is the owner of 'the prancing pony'.\n"+
             "He can serve you drinks.\n");
    set_race("hobbit");
    set_size(2);
    set_gender(1);
    load_chat(5,({"Ferny cleans the counter.\n",
                  "Ferny takes a zip himself.\n",
                  "Ferny mixes a drink.\n",}));
    load_a_chat(5,({"Ferny says: YOU DRUNK!\n",
                    "Ferny says: GET OUT!\n",}));
    set_gender(1);
    set_smell("Ferny smells like a mug of beer");
    set_level(15);
    set_hp(1000);
    set_ep(2000);
    set_al(100);
    set_wc(15);
    set_ac(4);
    set_aggressive(0);
    set_whimpy(-1);
    add_money(50 +random(50));
  }
}

