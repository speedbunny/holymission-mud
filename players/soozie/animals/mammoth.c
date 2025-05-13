inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Wooly mammoth");
    set_short("Wooly mammoth");
    set_alias("mammoth");
    set_gender(random(2));
    set_level(15);
    set_wc(10);
    set_ac(9);
    set_move_at_reset();
    set_long(
      "A rather large and hairy wooly mammoth browses around for a bite to\n"
"eat.  Its tusks gleam in the light.\n");
    load_chat(8,({ "The mammoth snorts loudly.\n",
        "The wooly mammoth polishes its tusks on a nearby tree trunk.\n",
      }));
}
