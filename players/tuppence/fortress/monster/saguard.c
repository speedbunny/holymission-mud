inherit "obj/monster";
string chats;
reset(arg) {
    ::reset(arg);
    if(!arg){
	set_name("guard");
	set_race("orc");
	set_short("Slave guard");
	set_long("He is here to make sure the slaves keep working no matter what.\n");
	set_alias("guard");
	set_level(17);
	set_ac(8);
	set_wc(18);
	if(!chats){
	    chats=allocate(2);
	    chats[0]= "Guard yells: Get back to work!\n";
	    chats[1]= "Guard whips a slave.\n";
	}
	load_chat(5,chats);
    }
}
