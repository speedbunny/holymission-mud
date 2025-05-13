inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Fist");
    set_short("Fist");
    set_alias("fist");  
    set_gender(random(0));
    set_level(10);
    set_wc(9);
    set_ac(4);
    set_move_at_reset();
    set_long(
      "The fist dosen't like you.\n");
    load_chat(8,({ "'Bop!' The fist hits you on the head!\n",
        "You killed my fingers! Now I must kill you!\n",
      }));
}
