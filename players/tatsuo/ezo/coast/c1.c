#define PPATH  "/players/tatsuo/ezo/coast/"
#define TP     this_player()
#define TPN    TP->query_name()
#define TPOBJ  TP->query_objective()
#define TPPOS  TP->query_possessive()
#define TO     this_object()
 
inherit "room/room";

int swim_it(string arg);
 
void reset(int arg) {
  if(arg) return;
 
  set_light(1);
  short_desc = "On the coast";
  long_desc =
    "You are standing on the coast of the island of Ezo. The ground "+
    "consists of sand and far, far away can you see the horizon. "+
    "The waves are rolling onto the coast and you get a very peaceful "+
    "feeling.@@ship@@\n";
 
  items = ({
    "coast", long_desc,
    "ground", "The ground consists of sand",
    "sand", "The sand is light-yellow",
    "sands", "The sand is light-yellow",
    "sky", "The sky is blue with a few clouds on it",
    "clouds", "The clouds have a dirty-white color",
    "volcano", "The volcano is very high and looks extremely steep",
    "sea", "Water, as far as the eye can see",
    "nihonese sea", "Water, as far as the eye can see",
    "water", "It is salt water. The waves are rolling onto the island",
    "wave", "This wave is a very big one",
    "waves", "The waves are rolling onto the island",
    "horizon", "It is really far away",
    "junk", "It is cargo junk in nihonese style",
    "cargo junk", "It is nihonese styled",
  });
 
  smell = "You smell the odor of salt and sea.";
 
  dest_dir = ({
    PPATH + "c2",  "east",
    PPATH + "rf1", "southeast",
    PPATH + "c11", "south",
  });
  ::reset(arg);
}
 
void init() {
  ::init();
  add_action("search", "search");
  add_action("drink_it", "drink");
  add_action("swim_it", "swim");
  add_action("enter_it", "enter");
}
 
int search(string arg) {
  object tekagi;
 
  if(!arg)
    return 0;
  
  write("You search and search, but find nothing special.\n");
  say(TPN+" searches around.\n");
  return 1;
}
 
int climb_it(string arg) {
  switch(arg) {
    case "rock-face":
    case "vulcano":
    case "volcano":
      write("Go to the volcano and then try it again.\n");
      return 1;
  }
  return 0;
}
 
int drink_it(string arg) {
  switch(arg) {
    case "water":
    case "water from sea":
    case "water from nihonese sea":
    case "salt water":
    case "salt-water":
    case "saltwater":
      write("As you drink some salty water from the sea, "+
            "you get a bad feeling.\n");
      say(TPN + " drinks some water.\n");
      TP->add_poison(3);
      return 1;
    default:
      return 0;
  }
}
 
int enter_it(string arg) {
  switch(arg) {
    case "water":
    case "sea":
    case "nihonese sea":
      return (swim_it("water"));
    default:
      return 0;
  }
}
 
int swim_it(string arg) {
  switch(arg) {
    case "":
    case "water":
    case "around":
    case "sea":
      write("You jump into the water and swim around for a while.\n");
      say(TPN + " jumps into the water and swims around for a while.\n");
      return 1;
    case "to ship":
    case "to junk":
      if(present("cargo_junk", TO)) {
        write("You jump into the water and swim to the ship.\n");
        TP->move_player("to the junk#players/bobo/obj/3_trip_junk");
      }
      else
        write("Do you see a ship here?\n");
      return 1;
    default:
      return 0;
  }
}
 
string ship() {
  if(present("cargo_junk", TO))
    return(" You can see a cargo junk anchoring out in the sea.");
  else
    return("");
}
