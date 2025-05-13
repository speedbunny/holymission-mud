inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The studyroom of Galadriel";
  long_desc="This is the workroom of Galadriel of Lothlorien.\n"
	+ "You have never seen a room so full with desks, chairs, and items lying around.\n"
        + "To the east is an opening to the boardhall.\n"
	+ "A thick layer of dust is covering most of them.\n";
  dest_dir=({ "players/galadriel/boardhall", "east",
        "room/church", "church",
	"obj/tick", "tick",
	"room/post", "post", });
  items=({"items", "You can't see the items clearly through the dust",
 "desk", "An old desk, covered with dust",
 "desks", "Old desks, covered with dust",
 "chair", "This chair is also covered with dust",
 "chairs", "You are very surprised, they are covered with dust :-)",
 "dust", "It is VERY thick",
	"button", "It's disabled", });
  enable_commands();
}

init() { ::init(); say(capitalize(this_player()->query_real_name()) + " is wandering into Galadriels workroom.\n",this_player()); }

catch_tell(str) {
  string name;
  if(sscanf(str,"%s left the game.\n",name)==1) {
    if(name=="Gal") {
	     shout("You feel that Galadriel left to a place where nobody can reach her.\n");
    }
  }
}
