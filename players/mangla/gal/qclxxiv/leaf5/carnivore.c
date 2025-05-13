inherit "players/qclxxiv/leaf5/qmonster";

reset(arg) {
     ::reset(arg);
	 if (arg) return;
	 load_chat(20,({
"Acid drips out of the Carnivore plant's big mouth-shaped flowers.\n",
		"The Carnivore plant makes threatening moves with its branches.\n",
"You hear clicking sounds as the Carnivore plant opens and closes\n"
+"its mouth-shaped flowers....\n",
	  }));
	 load_a_chat(20,({
        "The Carnivore plant drips acid from its mouth-shaped flowers.\n",
        "The Carnivore plant spits acid towards its attacker.\n",
	  }));
	set_name("carnivore");
	set_race("plant");
   	set_spell_mess1(
		"Carnivore plant sprays an enormous amount of acid towards his opponent.");
   	set_spell_mess2("Carnivore plant sprays an enormous amount of acid towards you.");
   	set_short("A Carnivore plant");
   	set_long(
"A Carnivore plant. Apparantly very conscious. Its mouth-shaped flowers\n"
+"are red inside and surrounded by sharp points. An absolute KILLER!\n" );
}

fight_what(int i) {
	switch (i) {
    	case 0: return "missed";
    	case 1: return "bits";
    	case 2: return "bits";
    	case 3: return "bits";
    	case 4: return "bits";
    	case 5: return "bits";
    	case 6: return "bits";
    	case 7: return "bits";
   		case 8: return "bits";
   		case 9: return "bits";
  		case 10: return "did an INSANE amount of damage to";
		default: return "huh?";
	}
}

fight_how(int i) {
	switch (i) {
    	case 0: return "";
    	case 1: return " with one flower";
    	case 2: return " deep with one flower";
    	case 3: return " very deep with one flower";
    	case 4: return " deep with several flowers";
    	case 5: return " very deep with several flowers";
    	case 6: return " with several flowers";
    	case 7: return " with most of its flowers";
		case 8: return " DEEP with most of its flowers";
   		case 9: return " VERY DEEP with most of its flowers";
  		case 10: return "";
		default: return "huh?";
	}
}

