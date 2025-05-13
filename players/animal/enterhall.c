inherit "room/room";
object foot;
 
reset(arg) {
#if 0
    ::reset(arg);
    set_outdoors(1);
#endif
    set_light(1);
if(!present("magic ball",this_object())) {
    foot = clone_object("players/animal/obj/football");
    move_object(foot, this_object());
    }
   long_desc = "The Entrance\n" +
          "\n" +
               "    Here stands the entrance to Animal's castle.\n" +
               "    You notice hanging on the wall the dead bodies\n" +
               "    of three adventurers.\n" +
               "    The first corpse appears to be an evil corpse.\n" +
               "    The second corpse appears to be a good corpse.\n" +
               "    The third corpse appears to be an unknown corpse.\n" +
               "    Could these be the trophies of Animal's numerous\n" +
               "    victories? Highly unlikely, because they all look like\n" +
               "    wimps when one thinks of Animal's famous skill.\n" +
               "\n";
    short_desc = "Entrance to Animal's castle";
    items = ({
          "evil corpse", "This corpse has been moved recently",
          "good corpse", "This corpse has not been moved yet",
          "unknown corpse", "This corpse has not been moved yet",
          "corpse", "WHICH ONE"
    });
    dest_dir = ({
              "room/plane2","jump",
    });
    return;
}
 
init() {

#if 0
	if(!present("note",this_object()))
	move_object(clone_object("players/animal/note"),this_object());
#endif
       ::init();
   add_action("move"); add_verb("move");
   add_action("jump"); add_verb("jump");
}
 
query_light() {
    return 1;
}
 
query_long() {
    return long_desc;
}
 
move(str) {
  if (str == "evil corpse") {
  write("The corpse comes alive and drags you into its world!\n");
  say(call_other(this_player(), "query_name",0)+
  " is dragged somewhere by the evil corpse.\n");
  tell_room("players/animal/evilhall1",this_player()->query_name()+
  " is deposited here by a corpse.\n");
  move_object(this_player(), "players/animal/evilhall1");
  call_other(this_player(),"look");
  return 1;
  }
  if (str == "good corpse") {
  write("The corpse comes alive and drags you into its world!\n");
  say(call_other(this_player(), "query_name",0)+
  " is dragged somewhere by the good corpse.\n");
  tell_room("players/animal/light/light1",this_player()->query_name() +
  " is deposited here by a corpse.\n");
  move_object(this_player(), "players/animal/light/light1");
  call_other(this_player(),"look");
	return 1;
  }
  if (str == "unknown corpse") {
  write("The corpse tries to comes alive but fails miserably!\n");
  say(call_other(this_player(), "query_name",0)+
  " tries to move the unknown corpse and fails.\n");
  write("This section is under repair still.\n");
  write("Come back often as one day the corpse might grab you!\n");
  return 1;
  }
  if (str == "corpse") {
  write("WHICH ONE!!!!!????\n");
  return 1;
  }
  return 0;
}
 
jump() {
  write("You close your eyes and jump!\n\n");

  this_player()->move_player(
   "jumps from the room screaming BANZAI!!!!!", "room/plane2", 1,
   "falls from the sky, and lands with a THUMP!");

  return 1;
}
