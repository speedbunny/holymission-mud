inherit "room/room";
reset (arg) {
   if (arg) return;
   ::reset (arg);
   set_light(1);
   short_desc="In a dense jungle.";
   long_desc=
      "You are now deep in the jungle.  Leafy plants are all around you\n"+
      "masking the way that you came from.  You can hear the sounds of\n"+
      "many different animals, especially various kinds of birds and monkeys\n"+
      "They seem to be mocking you.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/maze2/J7.c","north",
	"/players/bobo/clan/rooms/maze2/J8.c","east",
	"/players/bobo/clan/rooms/maze2/J7.c","south",
	"/players/bobo/clan/rooms/maze3/J6.c","west",
      });
   items=({
      "animals","Though you can't see them, you know that they're there...watching you",
      "birds","All sorts of bird calls can be heard around you, it's hard to make out just one",
      "monkeys","Curious little monkeys are having conversations all around you",
      "plants","small plants to large trees are all around you causing you to lose your way",
      });
   replace_program("room/room");
}
