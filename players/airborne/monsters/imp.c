inherit "/obj/monster";
object state;
string chats;

get_chats(){
   if(!chats){
	chats = allocate(6);
	chats[0] = "Imp tries to pick your pocket.\n";
	chats[1] = "Imp kicks you.    OUCH!!\n";
	chats[2] = "Imp says: There's nothing here. Go away!\n";
	chats[3] = "Imp says: My name is Grendel, what's yours?\n";
	chats[4] = "Imps says: Master is going to eat you!\n";
	chats[5] = "Imp trips you.\n";
   }
    return chats;
}

reset(arg){
	::reset(arg);
    if(arg) return 1;
	set_name("imp");
	set_race("devil");
	set_size(1);
	load_chat(30, get_chats());
	set_level(6);
	set_whimpy(20);
	set_short("An Imp");
	set_long("A short devilish creature with a pot belly looks right at you.\n" + "His long nose and cock-eyed face make you want to laugh.\n");
	set_frog();
   state=clone_object("players/airborne/obj/statuette");
   move_object(state, this_object());
		return 1;
}
