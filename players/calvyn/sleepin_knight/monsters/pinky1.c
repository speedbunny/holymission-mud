inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Pinky");
    set_short("Pinky");
    set_alias("pinky");  
    set_gender(random(1));
    set_level(3);
    set_wc(3);
    set_ac(1);
    set_move_at_reset();
    set_long(
      "The pinky lays twitching.\n");
}
