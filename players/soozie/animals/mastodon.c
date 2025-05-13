inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Mastodon");
    set_short("Mastodon");
    set_alias("mastodon");
    set_gender(random(2));
    set_level(50);
    set_wc(18);
    set_ac(16);
    set_move_at_reset();
    set_long(
      "This mastodon is the largest land animal and now you can see why.  Its\n"
"long hair hangs nearly to the ground and seems very thick.  Its tusks are\n"
"twice as long as you are tall.  Now THAT'S some weaponry.\n");
    load_chat(8,({ "The mastodon pokes you with its sharp tusk.\n",
        "The mastodon tries to stomp on you!\n",
      }));
    return 1;
}
