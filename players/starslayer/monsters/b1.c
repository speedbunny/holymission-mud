
a
inherit"obj/monster";

object o1,o2,o3;
string chats;
get_chats() {
	if(!chats){
	chats=allocate(4);
	chats[0] ="The Beggar scratches himself.\n";
	chats[1] ="The Beggar tkaes a drink from his bottle.\n";
	chats[1] ="The Beggar takes a drink from his bottle.\n";
	chats[2] ="Beggar says: welcome to the land of beggars\n";
	chats[3] ="The Beggar tries to steal from you.\n";
		  }
return chats;
	}
reset(arg) {
::reset(arg);
if (arg) return 1;
set_name("beggar");
set_race("human");
set_level(15);
set_short("beggar");
set_long("a drunken smelly beggar.He looks like he could do with a good bath.\n";
o1= clone_object("players/starslayer/armour/bjacket");
move_object(o1,this_object());
o2= clone_object("players/starslayer/obj/key");
move_object(o2,this_object());
o3 = clone_object("players/starslayer/obj/bottle");
move_object(o3,this_object());
return 1;
}
x
