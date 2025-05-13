inherit "room/room";
reset(arg){
  set_light(1);
  short_desc="Outside a hamlet";
  long_desc =
"The road you are on leads north into a small hamlet, and south\n\
 into a dense forest.  On either side of the road there are fields\n\
 where the people of the hamlet grow their food.  You see villagers\n\
 hard at work scattered throughout the fields.\n";


dest_dir=({
   "/wiz/belboz/room/town/road1","north",
   "/wiz/belboz/room/town/field2","east",
   "/wiz/belboz/room/town/field3","west",
   "/wiz/belboz/room/town/field4","south",
});

items=({
   "villagers",
      "The villagers are intent on keeping their fields clear of weeds and rocks\n"
      + "to insure a good harvest",
   "hamlet",
      "The hamlet lies to the north",
   "forest",
      "The forest is very thick, and you can't see into the trees at all.\n"
      + "Fortunately, the road cuts through the forest, leaving a clear path\n"
      + "through the trees",
   "road",
      "The road has many deep furrows from the passage of heavy laden carts\n"
      + "and wagons",
   "furrow",
      "The furrow still has some water in it from the last rain",
   });
}
