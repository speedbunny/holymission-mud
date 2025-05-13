inherit "obj/monster";
string chats;

get_chats(){
    if(!chats){
	chats = allocate(4);
	chats[0] = "Grand Master says: Check out the Mortal Kombat Area to the north!\n";
	chats[1] = "Grand Master says: You'll love Colossus' Mortal Kombat Area!\n";
	chats[2] = "The Grand Master says: Welcome brave adventurer.\n";
	chats[3] = "The Grand Master gazes wisely at you.\n";
    }
    return chats;
}

reset(arg){
    ::reset(arg);
    if(arg) return 1;
    set_name("grand master");
    set_alias("master");
    set_race("human");
    set_level(100);
    load_chat(35, get_chats());
    set_short("A Shaolin Grand Master");
    set_long(
      "Here stands a formidable Shaolin grand master. He looks sagely at you.\n"+
      "Though he looks small, you sense a hidden power within this man. You\n"+
      "think that if you attack him, he'll pound you to grape juice.\n");
}
