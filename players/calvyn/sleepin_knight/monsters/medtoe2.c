inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("medium toe");
    set_short("medium toe");
    set_alias("toe");  
    set_gender(random(2));
    set_level(4);
    set_wc(4);
    set_ac(1);
    set_move_at_reset();
    set_long(
      "A proud medium toe dancing around the big toe\n");
    load_chat(8,({ "'Thump Thump' the toe stamps on the ground.\n",
        "The toe rubs some cheese on you.\n",
      }));
}
