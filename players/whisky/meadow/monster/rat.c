inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
   if (arg) return;
	  load_chat(4,({
            "The little rat nibbles on your toe.\n",
            "The little rat tries to go through the field but fails.\n",
            "A u t c h ..The little rat bites you in your knee.\n",
            "The little rat smells your foot.\n",
            "The little rat searches around.\n",
            "J u m m i..The little rat finds a piece of cheese and eats it.\n",
            "The little rat squeaks loudly.\n",
            "The little rat nibbles on your feet.\n",
            "The little rat bites you in your toe.\n",
	  }));
	  load_a_chat(20,({
            "The little rat bites you in your nose.\n",
            "Squiieeeekkkk.\n",
	  }));
	set_name("rat");
	set_alias("little rat");
	set_short("A little rat");
	set_long("A little brown rat, searching\n"+
                 "for something to eat.\n"); 
        set_level(2);
        set_hp(60);
        set_whimpy();
	set_al(-10);
}

catch_tell(str)
{
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
      if (random(2))
         call_out("follow",2,where);
}

follow(where)
{
 init_command(where);
}

