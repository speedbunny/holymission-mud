/* cellar.c (C) Whisky */ 
#define	TP	this_player()
#define TPN this_player()->query_name()

inherit "room/room";
int counter;
object o1;
 
reset(arg) {
  counter = 0;
  if (!o1) {
     o1=clone_object("players/whisky/garden/monster/rat");
     move_object(o1,this_object());
  }
  if (arg) return;
 
  set_light(0);
  short_desc = "In a wet cellar";
  no_castle_flag = 0;
  long_desc = 
      "You have entered the cellar of a strange building. "+
      "It's horribly cold and damp here. There are many "+
      "spider webs hanging from the walls. There is a small "+
      "shelf on the north wall. An old wooden stairway leads up "+
      "to a hotter place where danger lurks.\n";
dest_dir = ({ "players/whisky/garden/room/house2","up",});
  items = ({"wall","You see some red bricks.",
            "stairway","A big wooden stairway leading up",
            "spider webs","Grey dusty spider webs",
            "webs","Grey dusty spider webs",
            "shelf","A brown wooden shelf"});
}
 
 
init() {
  ::init();
  add_action("search","search");
  add_action("search","put");
  add_action("search","give");
}

search(str) {
  object hank;
  if (str=="pocket") return 0;
  if (str=="webs" || str=="spider webs" || str=="wall") {
     write("You found nothing.\n");
     say(TPN+ "seaches around but finds nothing.\n");
  return 1;
}
  if (str=="shelf" || str=="fingers in shelf") {
  if (counter < 1) {
     hank=clone_object("players/whisky/garden/obj/hank");
     if(transfer(hank,this_player())) { /* Edit */
	write("You are carrying too much to search properly.\n");
	destruct(hank);
	return 1;
     }
     counter++;
     write("You find a hank.\n");
     say(TPN+ " searches around and finds a hank.\n");
     return 1;
  } /* End edit */
  else {
  write("Sorry, you find nothing. Someone must have been faster.\n");
  say(TPN+ " searches in the shelves but finds nothing.\n");
  return 1;
}
 return 1;
}
}

