inherit "room/room";
object vill;
reset(arg) {

   if(!vill) {
      vill=clone_object("/players/stanley/mobs/villager");
      move_object(vill,this_object());
   }

  if(arg) return;
  set_light(1);
  short_desc="In the fields";

  long_desc =
"You stand in the brown earth of a field near a small hamlet.\n" +
"Planting season could not have been too long ago, as the green\n" +
"shoots of this years crops have are a hand's breadth high.\n" +
"Scattered throughout the fields you see villagers and field\n" +
"hands diligently tending the land.\n";

dest_dir=({
   "/wiz/belboz/room/town/field1","east",
   "/wiz/belboz/room/town/field6","northwest",
});

items=({
   "villagers",
      "The villagers are intent on keeping their fields clear of weeds and rocks\n" +
      "to insure a good harvest",
   "hamlet",
      "The hamlet lies to the northeast",
   "forest",
      "The forest is very thick, and you can't see into the trees at all.\n" +
      "Fortunately, the road cuts through the forest, leaving a clear path\n" +
      "through the trees",
   "crops",
      "You are not sure what the crops are, as gardening was never one of your\n" +
      "strong points. Probably why you are adventuring and not out in a field\n" +
      "somewhere yourself",
   "shoots",
      "The shoots are healthy and green",
   "hands",
      "The field hands are hard at work tending the land",
   });
}
