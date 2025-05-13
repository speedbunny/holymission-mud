
inherit "room/room";
#define TP  this_player()

object ob;

  reset(arg) {
        if(arg) return;
        set_light(0);

  short_desc = "A small sewer running under Holy Mission";

  long_desc =
        "You have entered an immense sewer system tunneling deep under \n" +
        "the main streets and paths of Holy Mission. As you look around \n" +
        "you see many decomposed skeletons of animals and people that did \n" +
        "not make it out of the sewers alive. You can even make out small \n" +
        "rats scurrying around feasting on whatever fallen prey they can \n" +
        "find and laying on top of pipes. \n";

  dest_dir = ({
        "players/apollo/thieves/rooms/sewer08", "north",
        "players/apollo/thieves/rooms/sewer21", "south",
        "players/apollo/thieves/rooms/sewer17", "east",
        "players/apollo/thieves/rooms/sewer15", "west",
           });

 items = ({
        "air", "The air is full of an awful stench",
        "skeletons", "You see a slightly decomposed body of an animal",
        "pipes", "Running along the ceiling you see old pipes",
        "sewer", "You are walking through an old sewer",
        });

  smell = "You smell decomposed flesh from dead corpses";

  if (!ob)
    move_object(clone_object("/players/apollo/thieves/monsters/pudding"),
	this_object());

}

void init() {
  ::init();
  add_action("_east","east");
  add_action("_south","south");
  add_action("_north","north");
}


status _east() {
  if (present("black pudding") && TP->query_guild()!=1)
    write("The black pudding is in your way.\n");
  else
    TP->move_player("east#players/apollo/thieves/rooms/sewer17");
  return 1;
}

status _south() {
  if (present("black pudding") && TP->query_guild()!=1)
    write("The black pudding is in your way.\n");
  else
    TP->move_player("south#players/apollo/thieves/rooms/sewer21");
  return 1;
}

status _north() {
  if (present("black pudding") && TP->query_guild()!=1)
    write("The black pudding is in your way.\n");
  else
    TP->move_player("north#players/apollo/thieves/rooms/sewer08");
  return 1;
}

