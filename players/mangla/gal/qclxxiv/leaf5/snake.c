inherit "players/qclxxiv/leaf5/qmonster";

reset(arg) {
     ::reset(arg);
	 if (arg) return;
	 load_chat(20,({
		"Vernom drips from the corners of Poison-snake's big mouth.\n",
		"The Poison-snake looks very angry.\n",
"You hear a deep rumbling noise coming from the Poison-snake's long belly....\n",
	  }));
	 load_a_chat(20,({
        "The Poison-snake makes awful bubbling noises.\n",
        "The Poison-snake spits vernom towards his attacker.\n",
	  }));
	set_name("poison-snake");
	set_race("snake");
   	set_spell_mess1(
	"Poison-snake sprays an enormous amount of vernom towards his opponent.");
   	set_spell_mess2(
			"Poison-snake sprays an enormous amount of vernom towards you.");
   	set_short("A Poison-snake");
   	set_long(
"A huge Poison-snake. Vernom is dripping from its mouth. An absolute KILLER!\n" );
}

fight_what(int i) {
	switch (i) {
    	case 0: return "missed";
    	case 1: return "bites";
    	case 2: return "bites";
    	case 3: return "bites";
    	case 4: return "bites";
    	case 5: return "bites";
    	case 6: return "bites";
    	case 7: return "bites";
   		case 8: return "bites";
   		case 9: return "bites";
  		case 10: return "did an INSANE amount of damage to";
		default: return "huh?";
	}
}

fight_how(int i) {
	switch (i) {
    	case 0: return "";
    	case 1: return " in the foot";
    	case 2: return " deep in the foot";
    	case 3: return " in the leg";
    	case 4: return " deep in the leg";
    	case 5: return " in the belly";
    	case 6: return " deep in the belly";
    	case 7: return " in the neck";
		case 8: return " in the face";
   		case 9: return " deep in the face";
  		case 10: return "";
		default: return "huh?";
	}
}

