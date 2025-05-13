inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Octopus");
    set_short("Octopus");
    set_alias("octopus");
    set_gender(random(2));
    set_level(8);
    set_wc(10);
    set_ac(7);
    set_move_at_reset();
    set_long(
      "The octopus stares at you as you stare at it.  It sits quietly at the\n"
"bottom of the tank.  It looks harmless enough...\n");
    load_chat(8,({ "The octopus brushes your leg with a tentacle.\n",
        "The octopus tries to hug you!\n",
      }));
}
