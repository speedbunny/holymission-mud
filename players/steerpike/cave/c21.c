#define OC ({ "closed", "open" })
#define ROOMS ({ "drag", "c11", "c12", "c13", "c21", "c22", "c23", "c31", "c32", "c33" })
#define SOUNDS ({ "crunch", "grind" })

inherit "room/room";

int *grate_status;

reset(arg) {
  if(!pointerp(grate_status)) grate_status=({ 0,0 });
  if(grate_status[0]) toggle_grate(0);
  if(grate_status[1]) toggle_grate(1);
  if(arg) return;
  short_desc="A large dimly lit cavern";
  long_desc="You are in a large dimly lit cavern. The walls feel close about you\n"
	+ "and there seems to be some kind of hole in the floor below you.\n"
	+ "To the west an archway leads off into a brighter-lit area.\n";
  dest_dir=({ "players/moonchild/cave/c11", "north",
	"players/moonchild/cave/c31", "south",
	"players/moonchild/chapel/link", "west" });
  items=({ "walls", "The walls are quite narrow at this part of the cavern",
	"archway", "A tall, majestic archway, quite out of keeping with the rest of the place" });
}

init() {
  ::init();
  add_action("climb", "climb");
  add_action("climb", "enter");
  add_action("down", "down");
  add_action("suck_me", "open");
  add_action("suck_me", "close");
}

id(str) { return ::id(str) || str=="hole" || str=="grate" || str=="grates"; }

long(str) {
  if(str=="hole" || str=="grate" || str=="grates") {
    write("In the hole in the ground there are two grates.\n"
	+ "The upper of the two grates appears " + OC[grate_status[0]] + ".\n"
	+ "The lower of the two grates appears " + OC[grate_status[1]] + ".\n");
    return;
  }
  return ::long(str);
}

toggle_grate(arg) {
  int i;
  grate_status[arg]=!grate_status[arg];
  for(i=0;i<10;i++) {
    object ob;
    if((ob=find_object("players/moonchild/cave/" + ROOMS[i])))
      tell_room(ob,"You hear a " + SOUNDS[grate_status[arg]] + "ing sound.\n");
  }
}

climb(str) {
  if(str!="down" && str!="grate" && str!="down hole" && str!="hole") return;
  if(!grate_status[0] || !grate_status[1])
	write("But your way is blocked by a closed grate.\n");
  else this_player()->move_player("through the hole#players/moonchild/cave/drag");
  return 1;
}

down() { return climb("down"); }

suck_me(str) {
  if(str!="grate" && str!="grate 1" && str!="grate 2" && str!="upper grate"
	&& str!="lower grate") return;
  write("You don't appear to be able to " + query_verb() + " the grate.\n");
  return 1;
}
