/* 170794: Nokey: strict types */
#pragma strict_types
inherit "room/room";

void reset(int arg)
  {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  dest_dir =
  ({"players/padrone/inside/main_hall","north",
	   "players/padrone/inside/stairs2", "up",
	   "players/padrone/inside/stairs0", "down",
  });
  short_desc = "Stairs";
  long_desc =
	   "You are on a landing on the stairway.\n" +
	   "This is the ground floor, and there are stairs leading up and down.\n" +
	   "There is a rope with a 'PRIVATE' sign barring the stairs leading\n" +
          "down, but it is probably easy to go down anyway.\n";
  replace_program("room/room");
  }
