inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Belly Lint");
    set_short("Belly Lint");
    set_alias("lint");  
    set_gender(random(2));
    set_level(10);
    set_wc(9);
    set_ac(4);
    set_move_at_reset();
    set_long(
      "The belly lint blows around with the wind.\n");
    load_chat(8,({ "Some loose lint gets caught in your eye.\n",
      }));
}
