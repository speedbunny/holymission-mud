inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc="End of stream";
   long_desc =
   "The stream flows into a small hole in the ground here. A few large rocks\n\
lie scattered around the end of the stream. The forest surrounds you except\n\
for where the stream leads back to the south.\n";

dest_dir=({
   "/players/stanley/room/stream/stream6","south",
});

items= ({
   "boulders","The boulders are basically very large rocks",
   "boulder","The boulder is basically a very large rock",
   "hole","The hole is dark, and the water flows into it very fast",
   "rocks","The rocks are your typical boulders found in streams",
   "forest","The forest is very dense, and does not let much light in here",
   "water","The water is slightly muddy",
   "stream","The stream enters a hole in the ground here",
   "tree","The tree is just one of many",
   "trees","The trees stand and wave in the breeze",
  });
}

init(arg)
    {
    ::init();
    add_action("_enter","enter");
    }

_enter(str) {
   if(!str) return 0;
   if(str=="hole" || str=="hole in ground")
      {
      write("Are you mad? You would never survive!\n");
      return 1;
      }
   return 0;
}
