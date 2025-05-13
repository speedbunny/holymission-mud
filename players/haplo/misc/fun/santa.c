inherit "/obj/monster";

string chats;

get_chats(){
    if(!chats){
	chats=allocate(3);
	chats[0]=("Santa Claus sings: I wish you a Merry Christmas!\n");
	chats[1]=("Santa Claus sings: And a Happy New Year!!\n");
	chats[2]=("From a distance you can hear a bell ringing.\n");
    }
    return chats;
}

reset (arg) {
    ::reset(arg);

    set_name("santa");
    set_alias("santa klaus");
    set_short("Santa Klaus");
    set_long("He holds Huge, green christmas tree in his hand.\n"+
      "You feel nasty cold comeing from his red coat.\n"+
      "Barely you can see his eyes bihing his hairy beard\n"+
      "and you feel that he is comming from far behind ...\n");
    set_race("human");
    set_level(30);
    load_chat(6,get_chats());
    set_al(100);
}
