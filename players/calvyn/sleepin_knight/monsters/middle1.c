inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Middle Finger");
    set_short("Middle Finger");
    set_alias("middle");  
    set_gender(random(0));
    set_level(5);
    set_wc(4);
    set_ac(2);
    set_move_at_reset();
    set_long(
      "The middle finger stands there flipping you off.\n");
    load_chat(8,({ "'Flip!' The middle finger tells you where to go!\n",
        "The middle finger says, '!@#$%&* man get out of here'\n",
      }));
}
