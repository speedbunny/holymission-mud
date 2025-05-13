inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Minnow");
    set_short("Minnow");
    set_alias("minnow");
    set_gender(random(2));
    set_level(4);
    set_wc(3);
    set_ac(2);
    set_move_at_reset();
    set_long(
      "An itty bitty minnow...how cute!  It swims rapidly around the tank.\n"
"Maybe it could be worth something to you...\n");
    load_chat(8,({ "The minnow blows bubbles!\n",
        "The minnow nibbles at your toes!\n",
      }));
}
