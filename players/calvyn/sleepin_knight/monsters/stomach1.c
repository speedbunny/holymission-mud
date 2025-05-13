inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Stomach");
    set_short("Stomach");
    set_alias("stomach");  
    set_gender(random(0));
    set_level(9);
    set_wc(8);
    set_ac(3);
    set_move_at_reset();
    set_long(
      "The stomach lays there hungary for you.\n");
    load_chat(8,({ "'Grumble Grumble!' The stomach wants to eat you!\n",
      }));
}
