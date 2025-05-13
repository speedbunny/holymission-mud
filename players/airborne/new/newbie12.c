inherit "room/room";

reset(arg){
  if(!arg){

   set_light(1);
   short_desc = "Complete newbie area";
   long_desc = 
"    Now you are almost ready to venture out into Holy Mission, but before "+
"you leave you might need to understand a few more concepts.\n"+
"    There are two types of people playing Holy Mission, players and wizards. "+
"Players are people just like you who adventure throughout Holy Mission "+
"killing monsters and solving quests. Quests are little puzzles created to "+
"offer excitement and thinking to the MUD. You are expected to do the quests "+
"without any outside help, although working with others is allowed. "+
"Give each quest a try and work it out as best you can.\n"+
"    The other type of people playing Holy Mission are the wizards. The "+
"wizards all help in creating new parts to Holy Mission and help to fix "+
"errors when they occur. They are not here to watch over you but will "+
"intervene if there is something wrong or someone is causing a lot of "+
"trouble. They will not interfere with player disputes, those are for you "+
"to solve amongst yourselves.\n"+
"    When you get a chance, read the book of rules available in the Sheriff's "+
"office. You will be expected to know all of them and ignorance of any given "+
"rule is not an excuse to break it.\n"+
"    When you exit this room you will be able to finish your first quest.\n";

   dest_dir = ({ "players/airborne/new/end", "end" });

   property = ({ "no_tport_in", "no_tport_out", "no_steal" });
	}
}

init(){
 ::init();
  add_action("leave", "leave");  
  add_action("bar", "bar");
}

int leave(){
  write("Why would you want to stop the lessons so close to the end?\n");
  write("Mail Airborne with any suggestion or comments.\n");
  this_player()->move_player("after stopping the lessons#players/airborne/new/station");
  return 1; 
}

int bar(){
  this_player()->move_player("to the bar#players/airborne/new/bar");
  return 1; 
}
