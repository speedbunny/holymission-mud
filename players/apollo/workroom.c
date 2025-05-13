

#define NAME "apollo"
#define RN this_player()->query_real_name()
#define CNAME capitalize(NAME)

inherit "room/room";

int shield;
string who;

int i;
reset(arg) {
   if(arg) return;
    {  
      set_light (1);

      short_desc = CNAME + "'s Workroom";
      
      long_desc = 
         "         \n" +
         "		         Welcome to the Workroom of " + CNAME + ".\n" +
	 "	   \n" +
	 " 	   \n" +
	 "	   \n" +
	 "	   \n" +
	 "	   \n" +
         "         \n" +
         "         \n" +
         "         \n" +
         "         \n" +
         "         \n" +     
         "         \n" +
         "         \n";

      dest_dir = ({
         "room/post", "post",
         "room/church", "church",
         "players/apollo/testroom", "test",
         "players/apollo/area2/rooms/entrance", "area",
	 "players/apollo/thieves/rooms/fighter", "sewers",
         "players/matt/newworld/city/rooms/votebooth", "voting",
	 "/players/apollo/private/new_workroom", "private",
       });

      items = ({
         "air", "It is very thin up here",
         "floor", "The floor is cluttered with papers",
       });
 

      property = ({
         "no_sneak",
         "no_steal",
         "no_invisible",
         "no_snoop",
         "no_camouflage",
         "no_assasinate",
       });

      smell = "You can smell the aroma of beautiful roses";

    }
 }
 
init(){
  ::init();
  add_action("set_shield" , "shield");
  add_action("expel" , "expel");
  check();
  }

set_shield(str) {
  if((RN !="apollo") && (RN !="muzmuz") && (RN !="mangla")) return;
  if(!str) {
    write ("Shield is currently " + shield +".\n");
    return;
  }

if(str == "on") {
  write ("You place a spell on the room and a shield rises.\n");
  say ("Apollo speaks some magic words and the room seems to be protected.\n");
  shield=1;
  return 1;
}

if(str == "off") {
  write ("You lower your hand and the shield around thr room lowers.\n");
  say ("Apollo lowers his hand and the shield around the room lowers.\n");
  shield=0;
  return 1;
}

}

check() {
  if (shield && (RN !="apollo") && (RN !="muzmuz") && (RN !="mangla")) {
    write ("You failed to enter Apollo's Workroom.\n");
    say (this_player()->query_name()  +
       "tries to enter, but is blocked by the shield.\n");
    move_object (this_player(), "/room/church");
  }
  return 1;
}

expel(arg) {
  object player;
  if((RN != "apollo") && (RN != "muzmuz") && (RN !="mangla")) return;
  if(!arg) {
    write ("Expel whom?\n");
    return 1;
  }
  player = present (arg, this_object ());
  if(!player) {
    write ("That player is not here.\n");
    return 1;
  }
  write ("You expel " + player->query_name() +".\n");
  player->move_player ("to the church#/room/church");
  tell_room (this_object(), player->query_name() +
    " got expelled to the church.\n");
  return 1;

}

