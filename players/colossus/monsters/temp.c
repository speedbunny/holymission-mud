inherit "obj/monster";

#include "/players/matt/definitions"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("vulcanus");
    set_alias("forger");
    set_short("Vulcanus the Forger");
    set_long("Vulcanus, the God of the Forge, is a huge, muscle-bound man\n" +
      "scarred and charred by the undying flames of his domain.\n" +
      "His skin has a reddish tinge, and he wears battered armour.\n");
    set_race("god");
    set_gender(1);
    set_level(100);
    set_no_fight(1);
    set_prevent_poison(1);
    load_chat(30, ({
      "Vulcanus says: Show me the Prisms!\n",
      "The Forger peers at you, looking for something.\n",
      "Vulcanus says: If you have the Prisms, show me!\n",
      "Vulcanus says: I will forge them for you.\n", ""
    }));
}

init() {
    ::init();
    add_action("show", "show");
}

show(arg) {
    object water, wind, earth, fire;
    if(arg == "prisms" || arg == "prisms to vulcanus" ||
      arg == "prisms to forger") {
	water = present("waterdiamond", TP);
	wind = present("winddiamond", TP);
	earth = present("earthdiamond", TP);
	fire = present("firediamond", TP);
	if(water && wind && earth && fire) {
	    write("You show the four Prisms to the Forger.\n");
	    say(TP->NAME + " shows " + TP->POS + " Prisms to the Forger.\n");
	    TELLR(ENV(TP), "Vulcanus roars: Well done!!\n");
	    TELLR(ENV(TP), "The Forger God takes the Prisms.\n");
	    TELLR(ENV(TP), "He throws back his head and calls down the mighty " +
	      "Power Element!\n");
	    TELLR(ENV(TP), "A bolt of raw Power comes down and strikes the " +
	      "Prisms in a blinding flash!\n");
	    TELLR(ENV(TP), "When your eyes readjust, Vulcanus is holding only " +
	      "one Prism.\n");
	    write("He gives it to you.\n");
	    say("He gives it to " + TP->NAME + ".\n");
	    destruct(water);
	    destruct(wind);
	    destruct(earth);
	    fire->set_type("master");
	    fire->set_extra("All of the Elements mingle and swirl within it.\n");
	    TELLR(ENV(TP), "Vulcanus says: Take this to Aeternus.\n");
	    TELLR(ENV(TP), "In a burst of smoke and fire, the Forger disappears.\n");
	    destruct(TO);
	    return 1;
	}
	say(TP->SNAME + " tries to show something to the Forger.\n");
	TELLR(ENV(TP), "Vulcanus roars: Don't waste my time!\n");
	TELLR(ENV(TP), "He disappears.\n");
	destruct(TO);
	return 1;
    }
    write("Show what?\n");
    return 1;
}

hit_player(arg) {
    int i;
    object att, inv;
    att = TO->query_attack();
    if(att && present(att, ENV(TO))) {
	inv = all_inventory(ENV(TO));
	TELLR(ENV(TO), "Vulcanus growls: You dare attack me, Mortal?\n");
	TELL(att, "A bolt of searing flame strikes you!\n");
	for(i = 0; i < sizeof(inv); i++) {
	    if(inv[i] != att) TELL(inv[i], "A bolt of flame " +
		  "strikes " + TP->NAME + "!\n");
	}
	TP->ADDHP(TP->HP / -2);
	return 1;
    }
    return 1;
}
