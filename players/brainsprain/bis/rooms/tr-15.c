inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

int do_mo(){
  int i;
  i = TP->query_guild();
  switch(i) {
    
  case 0 :  
    //adventurer
	TP->move_player("north#/players/brainsprain/bis/rooms/guild0.c");
    return 1;
  case 1 :
    //thief
	TP->move_player("north#/players/brainsprain/bis/rooms/guild1.c");
    return 1;
  case 2 : 
 //druid
     TP->move_player("north#/players/brainsprain/bis/rooms/guild2.c");
 return 1;
  case 3 : 
    //fighters
	TP->move_player("north#/players/brainsprain/bis/rooms/guild3.c");
    return 1;
  case 4 : 
    //jedi
	TP->move_player("north#/players/brainsprain/bis/rooms/guild4.c");
    return 1;
  case 5 :  
    //mage
	TP->move_player("north#/players/brainsprain/bis/rooms/guild5.c");
    return 1;
  case 6 :  
    //bard
	TP->move_player("north#/players/brainsprain/bis/rooms/guild6.c");
    return 1;
  case 7 :
    //monks
	TP->move_player("north#/players/brainsprain/bis/rooms/guild7.c");
    return 1;
  case 8 :
    //ninja
	TP->move_player("north#/players/brainsprain/bis/rooms/guild8.c");
    return 1;
  case 10 :
    //vagabonds
	TP->move_player("north#/players/brainsprain/bis/rooms/guild10.c");
    return 1;
  case 11: 
    //barbs
	TP->move_player("north#/players/brainsprain/bis/rooms/guild11.c");
    return 1;
  }
  return 1;
}
void reset(int arg) {
  rnd = random(3);
  clone_list = ({ 1, rnd, "orc",
		  bm+"/peas", 0 });
  ::reset(arg);
  if(arg) return;
  
  short_desc = "Town road";
  long_desc =
    "To the north is the guild room.  Here adventurers can rest in the "+
    "comfort of a suite designed especially for his or her guild.  The "+
    "sea has encroached here so that during high tide the tall waves "+
    "lap against the road.\n";
  set_light(1);
  items = ({
    "room",
    "A magic room that allows adventurers to rest in a guild specific room",
    "sea",
    "The Pansiac Ocean",
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
    "waves",
    "Huge waves lapping against your ankles",
  });
  dest_dir = ({
    br+"/guild_room","north",
    br+"/tr-14","west",
    br+"/tr-16","east",
  });
}

void init(){
  ::init();
  add_action("do_mo","north");
  }
