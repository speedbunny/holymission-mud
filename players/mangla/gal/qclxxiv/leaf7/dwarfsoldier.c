inherit "players/qclxxiv/mymonster";

reset(arg) {
  object sword, shield;
        ::reset(arg);
	 if (arg) return;
	 load_chat(11,({
		"You hear a soft twittering...\n",
		"Was that a dwarf you saw moving there?\n",
		"Was that a dwarf you saw moving there?\n",
		"Was that a dwarf you saw moving there?\n",
		"Was that a dwarf you saw moving there?\n",
		"Was that a dwarf you saw moving there?\n",
		". moves around\n"
	  }));
	 load_a_chat(30,({
		"The dwarfsoldier says: Don't let my size fool you! Ugly giant.\n",
        "The dwarfsoldier utters angry curses.\n",
	  }));
	set_name("dwarf");
	set_alias("dwarfsoldier"); 
	set_level(7);
   	set_wc(9);
	set_ac(11);
   	set_hp(196);
	set_sp(60);
   	set_spell_mess1( 
	"The dwarfsoldier jumps up high and kicks his attacker's knee.");
   	set_spell_mess2( "The dwarfsoldier jumps up high and kicks your knee.");
	set_chance(27);
	set_spell_dam(5);
    set_al(-40);
   	set_aggressive(0);
   	set_short("");
   	set_long("You peer at the tiny dot that you suspect to be a dwarf,\n"+
		"it appears to be a dwarfsoldier, of the dwarf king's royal guard.\n");
    /* set_whimpy(); */
    shield=clone_object("/players/qclxxiv/leaf7/dwrfsldrshield");
    move_object(shield,this_object());
    sword=clone_object("obj/weapon");
    sword->set_id("sword");
    sword->set_class(10);
    sword->set_weight(1);
    sword->set_value(300);
    sword->set_short("A dwarfsoldiers's sword");
    sword->set_long("A dwarfsoldier's sword, made from the best steel.\n");
    move_object(sword,this_object());
	command("wear shield",this_object());
	command("wield sword",this_object());
}

