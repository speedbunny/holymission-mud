inherit "obj/monster";
string chats;
reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_name("drunk goblin");
	set_race("goblin");
	set_short("Drunk goblin");
	set_long("This goblin looks as if he has had alittle too much to drink.\n");
	set_alias("goblin");
	set_level(19);
	set_al(400);
	set_ac(9);
	set_wc(17);
	if(!chats) {
	    chats=allocate(3);
	    chats[0]= "Drunk goblin hiccups.\n";
	    chats[1]= "Drunk goblin burps in your face.\n";
	    chats[2]= "Drunk goblin says: hey bub you have anything to drink, i am as dry\n"+
	    "as a bone!\n";
	}
	load_chat(3,chats);
    }
}
