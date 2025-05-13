inherit "players/qclxxiv/leaf5/qmonster";

reset(arg) {
     ::reset(arg);
	 if (arg) return;
	 load_chat(20,({
		"Water drips from the `surface' of Waterghost's round body.\n",
		"The Waterghost looks very angry.\n",
		"You hear a deep bubbling sound coming from inside the Waterghost....\n"
	  }));
	 load_a_chat(20,({
        "The Waterghost makes awful bubbling noises.\n",
        "The Waterghost tries to drown his attacker by himself.\n",
	  }));
	set_name("waterghost");
	set_race("ghost");
   	set_spell_mess1(
		"Waterghost sprays an enormous amount of water towards his opponent.");
   	set_spell_mess2("Waterghost sprays an enormous amount of water towards you.");
   	set_short("A Waterghost");
   	set_long("A Waterghost. A weird, round-shaped, water-like substantion\n"
			+"hanging in the air. An absolute KILLER!\n" );
}

fight_what(int i) {
	switch (i) {
    	case 0: return "missed";
    	case 1: return "tickles";
    	case 2: return "hits";
    	case 3: return "hits";
    	case 4: return "hits";
    	case 5: return "strikes";
    	case 6: return "strikes";
    	case 7: return "strikes";
   		case 8: return "splashes";
   		case 9: return "splashes";
  		case 10: return "splashes";
		default: return "huh?";
	}
}

fight_how(int i) {
	switch (i) {
    	case 0: return "";
  		case 1: return "";
    	case 2: return " lightly";
    	case 3: return " heavy";
    	case 4: return " very heavy";
    	case 5: return " HARD";
    	case 6: return " very HARD";
    	case 7: return " super HARD";
		case 8: return " even HARDER";
   		case 9: return " at its HARDEST";
    	case 10: return " at its UTTER HARDEST";
		default: return "huh?";
	}
}

