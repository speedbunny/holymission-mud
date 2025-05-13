inherit "room/room";

reset(arg){
 if(arg) return;
  set_light(1);
  short_desc = "Complete newbie area";
  long_desc =
"     Welcome newbie! You are now on your way to learning all you need to know about playing LpMUDs and Holy Mission MUD in particular.\n"+
"     The first things you need to know are the communication commands. They are: say, tell, and shout. Say is used to speak to everyone in the same room, tell is used to speak to a particular person regardless of where they are in the MUD, and shout is used to speak to everyone on the MUD at the same time. Shout and tell will use up spell points, which we will discuss later on.\n"+
"     Say takes on the following format, say <message>. Or you can use ' before a message to have the same effect. For example, say Hello. is the same as 'Hello. Both will yield the following; You say : Hello.\n"+
"     Shout works in pretty much the same way as say, you type shout followed by the message.\n"+
"     Tell works a little differently. Because you are speaking to one person, you have to distinguish who that person is. The command for tell is: tell <name> <message>. That is the word tell followed by the person you wish to give a message to followed by the message.\n" +
"	When you are ready, exit lesson 3.\n";
   no_obvious_msg = "";

  property = ({"no_teleport", "no_sneak", "no_steal"});
}

init() {
 ::init();
  add_action("leave", "leave");
  add_action("shout_it", "shout");
  add_action("next", "lesson");
}

int leave(){
  write("You leave Airborne's newbie lessons.\n");
  this_player()->move_player("after stopping the lessons#players/airborne/new/station");
  return 1; 
}

int next(string str){
  if(str=="3"){
    this_player()->move_player("lesson 3#players/airborne/new/newbie4");
    return 1; 
    }
  else {
    notify_fail("You are not ready for that lesson yet.\n");
    return 0; 
    }
}

int shout_it(string str){
  if(lower_case(str) == "holy mission is the greatest mud"){
    write("Why thank you.\n");
    write("However that is no longer necesary to leave this lesson.\n");
    return 1; 
    }
  else { 
    return 0; 
    }
}
