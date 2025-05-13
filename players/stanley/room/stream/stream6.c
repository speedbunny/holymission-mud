inherit "room/room";
object monster;

reset(arg) {
   if(!monster) {
      monster=clone_object("/players/stanley/mobs/turtle");
      move_object(monster,this_object());
   }
   if(arg) return;
   set_light(1);
   short_desc="Beside stream";
   long_desc = "You are beside a stream that winds through a dense forest. Unfortunately,\n\
the trees are too dense for you to enter the forest right now, but the water\n\
is shallow enough to follow the water's path.\n";


dest_dir= ({
   "/players/stanley/room/stream/stream5","west",
   "/players/stanley/room/stream/stream7","north",
});

items= ({
   "forest","The forest is dark and dense. You don't think you can enter from here",
   "water","The water is slightly muddy",
   "stream","The stream winds through the forest on an unpredictable path.\nThe water looks slightly muddy",
   "tree","The tree is a tree",
   "trees","The trees pose no problems for you",
   "forest","The forest is very thick. You cannot enter it from here",
   });
}
