inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Squid");
    set_short("Squid");
    set_alias("squid");
    set_gender(random(2));
    set_level(8);
    set_wc(10);
    set_ac(5);
    set_move_at_reset();
    set_long(
      "A giant squid swims slowly by.  Although it's a graceful animal, you\n"
"can't help notice the menacing stare it gives you.\n");
    load_chat(8,({ "The squid changes color, blending with its surroundings\n",
        "The squid squirts ink onto your new outfit!\n",
      }));
}
