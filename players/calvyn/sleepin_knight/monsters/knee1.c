inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Knee cap");
    set_short("Knee cap");
    set_alias("knee");  
    set_gender(random(2));
    set_level(9);
    set_wc(7);
    set_ac(6);
    set_move_at_reset();
    set_long(
      "The knee cap wobbles in the wind.\n");
    load_chat(8,({ "'UGH!' The knee cap thrusts you in the gut.\n",
        "The knee cap knocks in the wind.\n",
      }));
}
