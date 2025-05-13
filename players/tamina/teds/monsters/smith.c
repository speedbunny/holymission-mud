inherit "obj/monster";
string chat_str, function, type, match;

reset(arg) {
    ::reset(arg);
    if(arg) return;
    if (!chat_str) {
	chat_str = allocate(3);
	chat_str[0] =
	"Bring me a raw lump of Adamite and I will make you a Dragon Slayer!\n";
	chat_str[1] =
	"You might want to try the Fire Giant castle near here.\n";
	chat_str[2] =
	"The Frost Giants sometimes find lumps of metal in their caves.\n";
	function = allocate(1);
	type = allocate(1);
	match = allocate(1);
	function[0] = "gives";
	type[0] = "gives";
    }
    set_name("smith of the gods");
    set_alias("smith");
    set_short("A Smith");
    set_long("This is Vulcan, smith of the gods.\n(He is a Demi-god himself)\n");
    set_level(19);
    set_hp(1900);
    set_wc(35);
    set_ac(95);
    set_chance(80);
    set_spell_dam(80);
    set_spell_mess2("Vulcan hits you with his hammer");
    set_spell_mess1("Vulcan uses his hammer");
    load_chat(50, chat_str);
    set_match(this_object(), function, type, match);
}

#define	PO	previous_object()

enter_inventory(ob) {
    object sword;

    if (ob->query_alias()=="raw adamite meteor") {
	if(creator(ob)!="tamina") {
	    log_file("QUESTS.CHEAT",this_player()->query_real_name()+": by "+
	      file_name(ob)+": dragon_slayer: "+ctime(time())+"\n");
	    destruct(ob);
	    return 1;
	}
	destruct(ob);
	sword = clone_object("/players/tamina/teds/weapons/dragon_slayer");
	transfer(sword, PO);
	say("The Smith begins to hammer away at the raw lump of metal.\n");
	say("He hammers.......and hammers........and hammers.......\n");
	say("Soon he is finished.......He takes the rough blade and\n");
	say("heats it in a pool of lava. Then He quickly sharpens it\n");
	say("on a dolemite grinding stone....dolemite being the\n");
	say("only substance harder than adamite. Vulcan tests the\n");
	say("blade by cutting his anvil in half in one stroke.......\n");
	say("\nSmith says: A weapon fit for the gods themselves!");
	say("\n");
	say("Smith gave the Dragon Slayer to " + PO->query_name() + ".\n");
	if (!PO->query_quests("dragon_slayer")) {
	    /*	    3.14.95 Kasgaroth: Quest was removed, so they get no credit for it
			PO->set_quest("dragon_slayer");
			*/
	    PO->add_exp(10000);
	    tell_object(PO,"You feel more experienced\n");
	}
	return 1;
    } else
	say("Smith says: What use is this?\n");
    return 1;
}
