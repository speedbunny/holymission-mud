inherit "room/room";
object monster;

reset(arg) {
   if(!monster) {
      monster=clone_object("/players/stanley/mobs/snake");
      move_object(monster,this_object());
   }
   if(arg) return;
   set_light(1);
   short_desc="Beside stream";
   long_desc =
"You are beside a stream that winds through a dense forest. Unfortunately,\n" +
"the trees are too dense for you to enter the forest right now, but the water\n" +
"is shallow enough to follow the water's path.\n";

dest_dir= ({
   "/players/stanley/room/stream/stream1","east",
   "/players/stanley/room/stream/stream4","south",
});

items= ({
   "stream",
      "The stream runs from the direction of the bridge on to the south.\n" +
      "The water looks slightly muddy",
   "tree",
      "The tree is a tree",
   "trees",
      "The trees pose no problems for you",
   "forest",
      "The forest is very thick. You cannot enter it from here",
   });
}
