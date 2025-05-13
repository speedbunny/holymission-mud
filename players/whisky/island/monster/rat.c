inherit "/players/whisky/seaworld/monster/monster";

reset(arg) {
        ::reset(arg);
	  load_chat(40,({
            "The little rat nibbles on your toe.\n",
            "The little rat tries to go through the fields but fails.\n",
            "A u t c h ..The little rat bites you in your knee.\n",
            "The little rat smells on your foot.\n",
            "The little rat searches around.\n",
            "J u m m i..The little rat found a piece of cheese and eats it.\n",
            "The little rat squieks intantly.\n",
            "The little rat nibbles on your feet.\n",
            "The little rat bites you in your toe.\n",
	  }));
	  load_a_chat(80,({
            "The little rat bites you in your nose.\n",
            "Squiieeeekkkk.\n",
	  }));
        load_match(this_object(),
        ({ "follow",  ({"leaves"}),}));
	set_name("rat");
	set_alias("little rat");
	set_short("A little rat");
	set_long("A little brown rat, searching\n"+
                 "for something to eat.\n"); 
        set_level(2);
        set_hp(60);
        add_money(random(80));
        set_whimpy();
	set_al(-10);
}
notify(str) {
  say(str);
  write(str);
  }

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
	init_command(where);
}


