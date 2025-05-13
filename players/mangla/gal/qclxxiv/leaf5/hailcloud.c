inherit "players/qclxxiv/leaf5/qmonster";

reset(arg) {
     ::reset(arg);
	 if (arg) return;
	 load_chat(20,({
		"Hail falls down from the frightening cloud.\n",
		"The Hailcloud makes an angry impression.\n",
	"You hear a deep thundering sound coming from inside the Hailcloud....\n"
	  }));
	 load_a_chat(20,({
        "The Hailcloud makes thundering noises.\n",
        "The Hailcloud spreads balls of lightning.\n",
	  }));
	set_name("hailcloud");
	set_race("cloud");
   	set_spell_mess1(
		"Hailcloud casts out an enormous amount of hail towards his opponent.");
   	set_spell_mess2("Hailcloud casts out an enormous amount of hail towards you.");
   	set_short("A Hailcloud");
   	set_long(
"A Hailcloud. Or rather, an unearthly weird monster looking a lot like a\n"
+" hailcloud. An absolute KILLER!\n" );
}

fight_what(int i) {
	switch (i) {
    	case 0: return "missed";
    	case 1: return "spats";
    	case 2: return "spats";
    	case 3: return "spats";
    	case 4: return "sprays";
    	case 5: return "sprays";
    	case 6: return "sprays";
    	case 7: return "strikes";
   		case 8: return "strikes";
   		case 9: return "casts bitingly large and fast hail to";
  		case 10: return "casts INSANE large and fast hail to";
		default: return "huh?";
	}
}

fight_how(int i) {
	switch (i) {
    	case 0: return "";
    	case 1: return " with some hail";
    	case 2: return " with rather much hail";
    	case 3: return " with a lot of hail";
    	case 4: return " with some biting hail";
    	case 5: return " with rather much biting hail";
    	case 6: return " with a lot of biting hail";
    	case 7: return " with a ball of lightning";
		case 8: return " with a large ball of lightning";
   		case 9: return "";
  		case 10: return "";
		default: return "huh?";
	}
}

