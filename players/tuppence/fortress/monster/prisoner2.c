inherit "obj/monster";
string chats;
reset(arg) {
    ::reset(arg);
    if(!arg){
	set_name("prisoner");
	set_race("elf");
	set_short("Prisoner");
	set_long("A poor tortured prisoner. You should put him out of his himisery\n");
	set_alias("man");
	set_level(6);
	set_al(100);
	set_ac(1);
	set_wc(3);
	if(!chats){
	    chats=allocate(4);
	    chats[0]="The prisoner screams as the whip hits his back.\n";
	    chats[1]="The prisoner faints from the pain.\n";
	    chats[2]="The prisoner says: Honest i dont know anything about them!\n";
	    chats[3]="The prisoner says: I wont tell you anything you son of a she devil!\n";
	}
	load_chat(3,chats);
    }
}
