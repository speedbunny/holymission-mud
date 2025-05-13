inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Hall of Fame.";
  long_desc="You're in the famous Hall of Fame.\n"+
   "It's the second level of the tower. Stairs are going down\n"+
   "There are many pictures at the walls and also a pillar stands in the middle of the "+
   "hall.\n"; 
  dest_dir=({
    "players/kelly/rooms/castle/tower11","down",
   });
  items =({
     "pillar","There are names engraved on this pillar",
     "pictures","One picture shows Kelly with a trophy in his hand.\nAnd an other "+
                      "shows the thief Marc. Somehow the look similar",
   });
}

init() {
::init();
  add_action("read","read");
}

read(str) {
  if(str!="names" && str!="pillar") return;
  write("These people have solved my Quest :\n");
  cat("players/kelly/obj/quest_file.txt");
  write("\n\nArchwiz Kelly.\n");
  return 1;
}
