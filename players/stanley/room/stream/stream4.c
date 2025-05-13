inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc="Beside stream";
   long_desc =
    "You are standing beside a small stream which cuts through a dense forest.\nThe sun shines brightly on the water.\n";

dest_dir= ({
   "/players/stanley/room/stream/stream3","north",
   "/players/stanley/room/stream/stream5","south",
});

items= ({
   "water","The water is slightly muddy",
   "stream","The stream runs from north to the south. The water looks slightly muddy",
   "tree","The tree is just one of many",
   "trees","The trees stand and wave in the breeze",
   });
}
