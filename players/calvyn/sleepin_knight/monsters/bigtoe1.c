inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("big toe");
    set_short("big toe");
    set_alias("toe");  
    set_gender(random(0));
    set_level(5);
    set_wc(4);
    set_ac(2);
    set_move_at_reset();
    set_long(
      "A big toe standing in the middle, watching the toes dance around\n");
    load_chat(8,({ "'Thump Thump' the toe stamps on the ground.\n",
        "The big toe pokes you in the ribs.\n",
      }));
}
