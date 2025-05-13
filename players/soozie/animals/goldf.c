inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Goldfish");
    set_short("Goldfish");
    set_alias("goldfish");
    set_gender(random(2));
    set_level(4);
    set_wc(4);
    set_ac(2);
    set_move_at_reset();
    set_long(
      "A brightly colored goldfish peers at you from the depths of its home.\n"
"You feel like you want to catch it.\n");
    load_chat(8,({ "The goldfish stares at you.\n",
        "The goldfish jumps out of the water!\n",
      }));
}
