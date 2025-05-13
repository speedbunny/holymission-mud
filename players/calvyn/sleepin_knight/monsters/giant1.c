inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Giant");
    set_short("Giant");
    set_alias("giant");  
    set_gender(random(0));
    set_level(25);
    set_wc(25);
    add_money(10000);
    set_attacks(3);
    set_ac(10);
    set_move_at_reset();
    set_long(
      "A 100 ft. tall giant is before you. You have woken him up from a 100\n"
"year sleep. He is not a happy camper.\n");
    load_chat(8,({ "The giant bellows, 'You have woken me up now you will die!'\n",
        "Whats a guy gotta do to get some sleep around here?\n",
      }));
}
