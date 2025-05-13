inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("little toe");
    set_short("little toe");
    set_alias("toe");  
    set_gender(random(1));
    set_level(3);
    set_wc(3);
    set_ac(1);
    set_move_at_reset();
    set_long(
      "A happy little toe dancing around the big toe\n");
    load_chat(8,({ "'Thump Thump' the toe stamps on the ground.\n",
        "The toe rubs some cheese on you.\n",
      }));
}
