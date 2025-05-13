inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc="Beside stream";
   long_desc =
"You are beside a stream that winds through a dense forest.\n\
 Unfortunately, the trees are too dense for you to enter the\n\
 forest right now, but the water is shallow enough to follow\n\
 the water's path.\n";

dest_dir= ({
   "/players/stanley/room/stream/stream4","north",
   "/players/stanley/room/stream/stream6","east",
});

items= ({
   "forest","The forest is very dense, and does not let much light in here",
   "water","The water is slightly muddy",
   "stream","The stream runs from north to the south. The water looks slightly muddy",
   "tree","The tree is just one of many",
   "trees","The trees stand and wave in the breeze",
   });
}
