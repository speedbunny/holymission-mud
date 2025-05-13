inherit "obj/monster";
string chats;
reset(arg) {
    ::reset(arg);
    if(!arg){
	set_name("water rat");
	set_race("rat");
	set_short("Water rat");
	set_long("A water rat that likes to spend his time in dark wet places.\n");
	set_alias("rat");
	set_level(13);
	set_ac(5);
	set_wc(3);
	if(!chats){
	    chats=allocate(3);
	    chats[0]= "The water rat squeeks at you.\n";
	    chats[1]= "Water rat nibbles on something.\n";
	    chats[2]= "Water rat runs past your feet.\n";
	}
	load_chat(8,chats);
    }
}
