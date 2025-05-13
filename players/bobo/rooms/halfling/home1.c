inherit "room/room";
reset (arg) {
   clone_list=({
      1, 1, "father","/players/bobo/monsters/halflingf", 0,
      2, 1, "mother","/players/bobo/monsters/halflingm", 0,
      3, 2, "child","/players/bobo/monsters/halflingc2", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="A halfling home.";
   long_desc=
      "This is a small halfling home. There is a small table with several\n"+
      "chairs next to it. There is an area for preparing food, as well as\n"+
      "several hay beds in various spots of the room. The dirt here is\n"+
      "mostly covered up by cloth and blankets. A small lamp sits on\n"+
      "the table that adequately lights up the room.\n";
   dest_dir=({
      "/players/bobo/rooms/halfling/corridor4.c","south",
      });
   items=({
      "beams","Thick wooden beams running up the sides and accross the top of the tunnel",
      "dirt","The dirt in this home is well taken care of and doesn't cover everything",
      "warren","Though this is only the entrance, hopefully it won't all look like this",
      "home","This small home is cozy and well taken care of",
      "table","The table is small, and lopsided",
      "chairs","The many chairs around the table are all old and worn",
      "food","Though there isn't any food being prepared now, you're sure you don't want any",
      "beds","The beds, if you can call them that are just a thin layer of straw",
      "cloth","A few large peices of cloth cover the walls of the room",
      "blankets","Large, worn blankts serve as rugs for the halflings that live here",
      "lamp","The lamp is attatched to the table so it won't go anywhere",
      });
   replace_program("room/room");
}
