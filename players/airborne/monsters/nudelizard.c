inherit "/obj/monster";
string chats;
get_chats(){
   if(!chats){
	chats = allocate(2);
	chats[0] = "Lizardman says: Wash my back.\n";
	chats[1] = "Naked lizardman says: Pass the soap.\n";
   }
     return chats;
}

reset(arg) {
	::reset(arg);
	if(arg) return 1;
	set_name("lizardman");
	set_alias("man");
	set_short("Lizardman");
	set_long("This lizardman is standing before you in his birthday suit.\n" 		+"He looks rather nasty!\n");
	set_level(3);
	set_aggressive(1);
	load_chat(10, get_chats());
	set_al(0);
	set_race("lizardman");
return 1;
}
