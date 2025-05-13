inherit "players/qclxxiv/leaf5/qmonster";

reset(arg) {
     ::reset(arg);
	 if (arg) return;
	 load_chat(20,({
		"Slime drips from the corners of Minotaur's big mouth.\n",
		"The Minotaur looks very angry.\n",
		"The Minotaur makes a roaring sound....\n"
	  }));
	 load_a_chat(20,({
        "The Minotaur tramples the floor with his hoofs.\n",
        "The Minotaur points his horns threatening.\n",
	  }));
	set_name("minotaur");
	set_race("dragon");
   	set_spell_mess1(
		"Minotaur takes his opponent on the horns.");
   	set_spell_mess2("Minotaur takes you on his horns.");
   	set_short("A Minotaur");
   	set_long("A Minotaur. A monstrous dragon looking somewhat like a bull,\n"
			+"but also somewhat like a human. An absolute KILLER!\n" );
}

fight_what(int i) {
	switch (i) {
    	case 0: return "missed";
    	case 1: return "touches";
    	case 2: return "hits";
    	case 3: return "hits";
    	case 4: return "blows";
    	case 5: return "blows";
    	case 6: return "strikes";
    	case 7: return "strikes";
   		case 8: return "crushes";
   		case 9: return "tramples";
  		case 10: return "wrecks";
		default: return "huh?";
	}
}

fight_how(int i) {
	switch (i) {
    	case 0: return "";
    	case 1: return " lightly";
    	case 2: return " ";
    	case 3: return " hard";
    	case 4: return " ";
    	case 5: return " hard";
    	case 6: return " badly";
    	case 7: return " very badly";
		case 8: return " to the floor";
   		case 9: return " to pieces";
  		case 10: return " entirely";
		default: return "huh?";
	}
}

