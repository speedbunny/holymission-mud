inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("The Heart");
    set_short("The Heart");
    set_alias("heart");  
    set_gender(random(0));
    set_level(12);
    set_wc(11);
    set_ac(4);
    set_move_at_reset();
    set_long(
      "The heart beats vigorously.\n");
    load_chat(8,({ "'Squish!' The heart spews blood all over you!\n",
        "The heart says, 'I keep you alive, I can kill you!\n",
      }));
}
