inherit "players/qclxxiv/leaf5/qmonster";

reset(arg) {
     ::reset(arg);
	 if (arg) return;
	 load_chat(20,({
		"Flames leak from the surface of Fireghost's oval body.\n",
		"The Fireghost looks very angry.\n",
		"The Fireghost whirls around.\n",
	  }));
	 load_a_chat(20,({
        "The Fireghost seems to get hotter, as the flames get even wilder.\n",
        "The Fireghost whirls around its opponent.\n",
	  }));
	set_name("fireghost");
	set_race("ghost");
   	set_spell_mess1(
		"Fireghost concentrates ALL its flames on his opponent.");
   	set_spell_mess2("Fireghost concentrates ALL its flames on you.");
   	set_short("A Fireghost");
   	set_long("A Fireghost. A frightening, flaming monster. An absolute KILLER!\n" );
}

fight_what(int i) {
	switch (i) {
    	case 0: return "missed";
    	case 1: return "hits";
    	case 2: return "hits";
    	case 3: return "hits";
    	case 4: return "hits";
    	case 5: return "hits";
    	case 6: return "hits";
    	case 7: return "strikes";
   		case 8: return "strikes";
   		case 9: return "strikes";
  		case 10: return "strikes";
		default: return "huh?";
	}
}

fight_how(int i) {
	switch (i) {
    	case 0: return "";
    	case 1: return " with some flames";
    	case 2: return " with quite some flames";
    	case 3: return " with many flames";
    	case 4: return " with some hotter flames";
    	case 5: return " with quite some hotter flames";
    	case 6: return " with some very hot flames";
    	case 7: return " with quite some very hot flames";
		case 8: return " with many very hot flames";
   		case 9: return " with its HOTTEST flames";
  		case 10: return " with LOTS of its HOTTEST flames";
		default: return "huh?";
	}
}

