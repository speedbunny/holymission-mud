inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Serpent");
    set_short("Serpent");
    set_alias("serpent");
    set_gender(random(2));
    set_level(20);
    set_wc(15);
    set_ac(15);
    set_move_at_reset();
    set_long(
      "A giant, green, slimy serpent rears its huge head out of the water at\n"
"you!  Its bright scales glisten as its deafening scream rips through your\n"
"body.\n");
    load_chat(8,({ "The water in front of you churns a bit...\n",
        "You think you see a shadow through the fog, but you aren't sure.\n",
      }));
}
