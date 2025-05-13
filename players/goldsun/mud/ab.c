#define TP   this_player()
#define TPN  TP->query_name()

inherit "room/room";
 status stone_moved, searched;
 object stone;
 string walldesc;
 int move_tried;

reset(arg){
  walldesc="A stone wall, well built from huge stones";
  stone_moved=0;
  searched=0;
  if (stone && present(stone,this_object())) {
    move_tried=0;
    destruct (stone);
    tell_room(this_object(),"A huge stone crumbles to dust.\n");
  }
  long_desc = 
    "You are in a cold, wet room, filled with dirt and awful smell. There\n" +
    "doesn't seem to be anything here at all, maybe you are the first who ever\n" +
    "happened to be trapped here.\n";
  items = ({
    "walls",
       "High walls, well built of huge stones, no windows or light supply from anywhere",
    "ceiling",
       "A far too high to see anything, but you are sure there must be a trapdoor in it",
    "floor",
       "The floor is made of stones and too hard to dig anywhere",
    "dirt",
       "Undefinable dirt, you feel an urge to vomit",
    "wall",
       "There are four walls in this dungeon, all are made of huge stones",
    "west wall", walldesc, "south wall", walldesc, "north wall", walldesc,
    "east wall", "@@query_wall_desc@@",
  });
  if (arg) return;
  move_tried=0;
  set_light(-1);
  short_desc= "Secret room";
  smell="The foul smell makes you vomit.";
}

init(){
   ::init();
    add_action("search","search");
    add_action("crawl", "crawl");
    add_action("climb", "climb");
    add_action("east",  "east");
  if (searched) {
    add_action("move",  "move");
    add_action("move",  "loose");
    add_action("move",  "remove");
  }
}

search(str) {
  int fail;
  if (stone_moved) {
    write ("You find a hole in the east wall, big enough to crawl through it.\n");
    return 1;
  }
  if (searched) {
    write ("You touch cold wet stone everywhere.\n");
    say (TPN + " feels with " + this_player()->query_possessive() + 
       " fingers floor and walls to find a way out.\n");
    return 1;
  }
  if (!str || str=="room" || str=="walls" || str=="wall" || str=="east wall") {
    fail=random(4);
    if (str && fail) fail--;
    if (fail) {
      write ("You touch cold wet stone everywhere.\n");
      if (this_player()->query_real_name()=="helenette") write ("fail: " + fail + "\n");
      say (TPN + " feels with " + this_player()->query_possessive() + 
       " fingers floor and walls to find a way out.\n");
      return 1;
    }
    write("You find a stone in the east wall which might be moveable.\n");
    say (TPN + " feels with " + this_player()->query_possessive() + 
       " fingers floor and finds a stone which might be moved.\n");
    searched = 1; 
    add_action("move",  "move");
    add_action("move",  "loose");
    add_action("move",  "remove");
    items += ({
    "stone",
       "A loose stone in the east wall",
    });
    return 1;
  }
  if (str=="west wall" || str=="north wall" || str=="south wall" || str=="floor") {
    write("You find nothing special.\n");
    say(TPN+ " searches around.\n");
    return 1;
  }
  write("Search what?\n");
  return 1;
}

move(str){
  int success;
  if (str!="stone") {
    write ("Move what?\n"); return 1; }
  if (this_player()->query_ghost()) {
    write ("Your incorporeal hands pass right through the stone.\n");
    return 1;
  }
  if (stone_moved) {
    if (present("stone",this_object())) {
      write ("You roll the stone a little more aside.\n");
      say (TPN + " rolls the stone a little more aside.\n");
      return 1;
      }
    else return 0;
  }

  success=20+random(20);
  if (this_player()->query_str() + move_tried < success) {
    write ("The stone did not move.\n");
    say (TPN + " tries to remove a stone but fails.\n");
    return 1;
  }
  
  stone_moved=1;
  stone=clone_object("obj/treasure");
  stone->set_id("stone");
  stone->set_short("a huge wall stone");
  stone->set_long("A huge stone which seems to be broken recently from a wall.\n");
  stone->set_weight(success);
  stone->set_value(success-20);
  transfer(stone,this_object());
  
  long_desc = 
    "You are in a cold, wet dungeon room, filled with dirt and awful smell.\n" +
    "One stone in the east wall was broken out recently, the dark hole looks\n" +
    "threatening like a hungry mouth, ready to munch you.\n";
  items -= ({
    "stone",
       "A loose stone in the east wall",
  });
  items += ({
    "hole",
       "A dark hole in the east wall, big enough to crawl through it",
  });

  write("You manage to get the stone out off the wall. A hole about your size\n" +
        "appears. Looks like you might be able to crawl through it.\n");
  say(TPN+ " moves a stone and part of the wall moves aside.\n");
  return 1;
}

crawl(str){
  if (stone_moved && (!str || str=="hole" || str=="east" || str=="e")) {
    write("You wriggle through the hole in the east wall.\n");
    this_player()->move_player
     ("through a hole in the east wall#players/airborne/temple/levelc/secret2");
    return 1;
  }
  return 0;
}

climb (str) {
  write ("You try to climb the cold walls but you fail.\n");
  return 1;
}

query_wall_desc() {
  if (stone_moved)
    return "There is a huge dark gap in the wall where one stone is missing";
  if (searched)
    return "You notice a stone in the east wall which seems to be moveable";
  return walldesc;
}
