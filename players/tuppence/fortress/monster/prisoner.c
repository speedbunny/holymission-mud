inherit "obj/monster";
string chats;
reset(arg) {
    ::reset(arg);
    if(!arg){
	set_name("prisoner");
	set_race("human");
	set_short("Prisoner");
	set_long("A poor prisoner stands here, he knows he will not get out alive.\n");
	set_alias("man");
	set_level(6);
	set_al(100);
	set_ac(1);
	set_wc(3);
	if(!chats){
	    chats=allocate(4);
	    chats[0]= "Prisoner moans in great pain.\n";
	    chats[1]= "Prisoner moans: Help me! Please!\n";
	    chats[2]= "Prisoner falls to the ground!\n";
	    chats[3]= "Prisoner begs you for help.\n";
	}
	load_chat(3,chats);
    }
}

