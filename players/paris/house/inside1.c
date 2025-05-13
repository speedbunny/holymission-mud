inherit "room/room";
#include "/players/paris/house/house.h"

void reset(int arg) {
  if (arg)
    return;
  set_light(1);
  short_desc = "Reception room";
  long_desc = "You are in a ornate reception room, dark wooden panels line "
    + "the walls. The air is musty and a thin coating of dust lies on "
    + "all that you can see. You get the feeling you should be really "
    + "quiet. You can see a spiral staircase leading upwards, and a "
    + "study to the north, a large door to the east leads out.\n";
  dest_dir = ({
    "players/paris/house/study", "north",
    "players/paris/house/upstairs1", "up",
  });
  items = ({
    "stairs", 
    "An ornate spiral staircase, you might want to creep upstairs.",
    "staircase", 
    "An ornate spiral staircase, you might want to creep upstairs.",
    "spiral staircase", 
    "An ornate spiral staircase, you might want to creep upstairs.",
    "air", "Motes of dust dance in the light.",
    "dust", "Ooooh, no one looks as if they have cleaned in here for years.",
    "panels", "Heavy oaken panels, you can't make out what they depict.",
  });
  smell = "You can smell the scent of old musty books.";
  ::reset(arg);
}

void init() {
 ::init();
 add_action("_open", "open");
 add_action("_goCreep", "creep");
 add_action("_goUp", "up");
}

int _open(string str) {
  if (str == "door" || str == "iron door") {
    printf("You open the door and slip out before it closes behind you.\n");
    this_player()->move_player("slips out the door#players/paris/house/garden");
    return 1;
  }
  return 0;
}

int _goCreep(string str) {
  /*
   * be very quiet walking up the stairs
   */
  if (str == "up" || str == "upstairs") {
    printf("You start to creep up the stairs.\n");
    this_player()->move_player("creeps up the stairs#players/paris/house/upstairs1");
    return 1;
  } else 
    return 0;
}

int _goUp() {
  say(capitalize((string)this_player()->query_name())
      + " starts to walk up the stairs.\nCREEEEAAAAAKKK!\n"
      + "You seem them suddenly disappear.\n", this_player()); 
  printf("You start to walk up the stairs.\n"
	 + "CREEEEAAAAAKKKK!!!!\nYou suddenly find yourself moved.\n\n");
  move_object(this_player(), "players/paris/house/garden");
  command("look", this_player());
  return 1;
}
