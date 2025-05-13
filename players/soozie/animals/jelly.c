inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Jellyfish");
    set_short("Jellyfish");
    set_alias("jellyfish");
    set_gender(random(2));
    set_level(4);
    set_wc(4);
    set_ac(3);
    set_move_at_reset();
    set_long(
      "A little jellyfish floats around in the water.  It goes wherever the\n"
"current takes it.  It's hanging around you, though.\n");
    load_chat(8,({ "'Splat!' the jellyfish jumps up and smacks you in the forehead!\n",
        "The jellyfish rolls around in the water.\n",
      }));
}
