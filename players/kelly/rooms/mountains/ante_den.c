inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="In dimly lit cave";
  long_desc="You're in dimly lit cave.\n"+
   "To the north there's more light. To the south there are three exits\n"+
   "Beside every exit there's a cave-painting.\n";
  dest_dir=({
    "players/kelly/rooms/mountains/stonepath7","north",
    "players/kelly/rooms/mountains/den1","southwest",
    "players/kelly/rooms/mountains/den3","southeast",
    "players/kelly/rooms/mountains/den2","south",
   });
   items=({
    "paintings","They are very old and show three creatures",
    "painting 1","It shows a unicorn that stands on his back legs",
    "painting 2","It shows a centaur notching a arrow to his longbow",
    "painting 3","It shows a harpy killing a curious adventurer",
   });
   /*
   move_object(clone_object("players/kelly/monster/den_gaurd"),this_object());
   */
}
 
