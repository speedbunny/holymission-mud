inherit "/players/whisky/seaworld/monster/monster.c";

int count;

reset(arg) {
        ::reset(arg);
     if (arg) return;
	  load_chat(12,({
            "Rudi bangs his head against the next wall.\n",
            "Rudi pokes you in the eye ... Ouuch that HURTS!\n",
            "Rudi scratches his head.\n",
            "Rudi shakes hands with everybody.\n",
            "Rudi tries to solve the riddle of the Sphinx.\n",
	  }));
	  load_a_chat(40,({
	    "Rudi says: You shouldn't do that, kid!\n",
            "Rudi says: Stop that or I'll zap you..\n",
	    "Rudi says: Don't you EVER do that again!\n",
	    "Rudi says: I'm a wizard, didn't you know that?\n",
	  }));
	  load_match(this_object(),
		     ({
		       "say_hello",		({"arrives"}),
		       "follow",		({"leaves"}),
		     }));
	set_name("rudi");
	set_alias("aldo");
	set_short("Rudi the small adventurer (nasty)");
	set_long("Rudi the small adventurer (nasty)\n"+
                 "He has a scar on his right hand, left foot and cheek.\n"); 
        set_level(4);
        set_hp(200);
        add_money(random(400));
        set_whimpy();
	set_al(-100);
	set_aggressive(0);
	set_move_at_reset(0);
}


    
    
say_hello(str) {
    string who;
    if (sscanf(str, "%s arrives.", who) == 1) {
	notify( "Rudi says: Hi " + who + ", nice to see you !\n");
    }
}
    

follow(str) {
    string who, where;
    if(sscanf(str, "%s leaves %s.\n", who, where) == 2)
        command(where);
}
