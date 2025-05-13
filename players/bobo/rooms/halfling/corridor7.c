inherit "room/room";
reset (arg) {
   ::reset (arg);
   set_light(1);
   short_desc="In a halfling hole.";
   long_desc=
      "You are in the only part of the whole corridor that looks like it\n"+
      "was built with dilligence and care. The beams are straight, the\n"+
      "walls are well crafted, and the dirt floor is smooth and flat.\n";
   dest_dir=({
      "/players/bobo/rooms/halfling/corridor6.c","east",
      "/players/bobo/rooms/halfling/anteroom.c","west",
      });
   items=({
      "beams","The beams in this area are made of superior wood and are skillfully erected",
      "dirt","The dirt here is well packed and doesn't look so bad",
      "floor","The floor here is flat and even",
      "walls","The walls are parallel to each other and without bumps",
      "warren","Though this is only the entrance, hopefully it won't all look like this",
      });
   replace_program("room/room");
}
