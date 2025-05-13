#define MON_TEST ({ "c11", "c13", "c31", "c33" })
#define ROPE_ROOMS ({ ({ "c11", "c22", "c13" }) , ({ "c21", "c32", "c23" }) })

inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc="A dimly lit cavern";
  long_desc="This is a junction in a dimly lit cavern. Red light coming\n"
	+ "from the south flickers off the walls. It is quite warm here.\n"
	+ "A large rope hangs down from above.\n";
  dest_dir=({ "players/moonchild/cave/c11", "west",
	"players/moonchild/cave/c22", "south",
	"players/moonchild/cave/c13", "east" });
  items=({ "walls", "There is an inscription carved on the walls",
	"inscription", "You think that you could read it",
	"rope", "It appears to be attached to something at the top" });
}

init() {
  ::init();
  add_action("_read", "read");
  add_action("pull", "pull");
}

_read(str) {
  if(str!="inscription") return;
  write("The inscription reads: If at first you don't succeed, try, try again.\n");
  return 1;
}

pull(str) {
  if(str!="rope") return;
    write("You pull the rope.\n");
    say(this_player()->query_name() + " pulls the rope.\n");
    call_out("ring",3,0);
    call_out("ring",7,0);
    call_out("ring",11,0);
  if(random(4)) {
    write("You feel something falling down your arm.\n");
    move_object(clone_object("players/moonchild/cave/spider"),this_object());
  }
  else if(!test_monsters()) "players/moonchild/cave/c21"->toggle_grate(0);
  return 1;
}

ring() {
  int i;
  tell_room(this_object(),"You hear a bell ringing loudly; you cover your ears.\n");
  for(i=0;i<3;i++) {
    object ob;
    if((ob=find_object("players/moonchild/cave/" + ROPE_ROOMS[0][i])))
	tell_room(ob,"You hear a bell ringing.\n");
    if((ob=find_object("players/moonchild/cave/" + ROPE_ROOMS[1][i])))
	tell_room(ob,"You hear a bell ringing in the distance.\n");
  }
}

test_monsters() {
  int i,res;
  i=-1;
  while(++i<sizeof(MON_TEST) && !res) {
    object ob;
    res=1;
    if((ob=find_object("players/moonchild/cave/" + MON_TEST[i]))
	&& !present("troll",ob)) res=0;
    else tell_room(environment(this_player()),
	"A small imp runs into the room.\n"
	+ "He says: I'm not doing anything while all those trolls are there!\n"
	+ "The small imp then runs away again.\n");
  }
  return res;
}
