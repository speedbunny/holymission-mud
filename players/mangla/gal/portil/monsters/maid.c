inherit "obj/monster";

    reset(arg) {
     ::reset(arg);
     if (arg) return;

	set_name("serving maid");
	set_alt_name("maid");
	set_short("A young serving maid");
	set_long("It looks as though she has come to the well for some water.\n");
	set_gender(2);
	set_level(15);
	set_al(300);
	set_weight(3);
	set_race("human");
	load_chat(15,({
          "The serving maid says: I need to get some water but the well is dry.\n",
          "The serving maid starts to cry.\n",
          "The serving maid says: I have something of great importance if you can fix the well.\n",
          "The serving maid looks at the well.\n"
	}));
}
