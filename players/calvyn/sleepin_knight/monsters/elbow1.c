inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Elbow");
    set_short("Elbow");
    set_alias("elbowt");  
    set_gender(random(2));
    set_level(8);
    set_wc(7);
    set_ac(3);
    set_move_at_reset();
    set_long(
      "The elbow holds the forarm on.\n");
    load_chat(8,({ "'UGH!' The elbow hits you in the gut!\n",
      }));
}
