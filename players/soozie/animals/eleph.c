inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Elephant");
    set_short("Elephant");
    set_alias("elephant");
    set_gender(random(2));
    set_level(4);
    set_wc(3);
    set_ac(2);
    set_move_at_reset();
    set_long(
      "A big grey elephant.  It looks at you expectantly.\n");
    load_chat(8,({ "The elephant tickles you with its trunk!\n",
        "The elephant sprays you with water!\n",
      }));
}
