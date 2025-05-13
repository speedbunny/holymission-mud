inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Clam");
    set_short("Clam");
    set_alias("clam");  
    set_gender(random(2));
    set_level(4);
    set_wc(4);
    set_ac(2);
    set_move_at_reset();
    set_long(
      "A happy looking clam sits at the bottom of the tank.  It looks like\n"
"it's sticking its tongue out at you!\n");
    load_chat(8,({ "'Pfftthhh!' the clam sticks its tongue out at you!\n",
        "The clam tries to bury itself in the sand.\n",
      }));
}
