inherit "room/room";
reset (arg) {
   clone_list=({
      1, 1, "mother","/players/bobo/monsters/halflingm", 0,
      2, 1, "child","/players/bobo/monsters/halflingc2", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="In a halfling hole.";
   long_desc=
      "This little home is spartan and bare. There is little here except\n"+
      "a small lamp, a table with a couple of chairs, and a straw bed.\n"+
      "Even though there aren't many furnishings, it is obvious that the\n"+
      "person who takes care of the home takes pride in their job because\n"+
      "everything is neat and tidy.\n";
   dest_dir=({
      "/players/bobo/rooms/halfling/corridor5.c","south",
      });
   items=({
      "beams","Thick wooden beams running up the sides and accross the top of the tunnel",
      "dirt","Yep it's dirt, and it's everywhere",
      "lamp","The tiny lamp is kept very clean so that it can give as much light as possible",
      "bed","The straw bed is large and free of bugs and debris",
      "chairs","The chairs around the table are shody and rickety",
      "table","The table top is kept clean and free of grime",
      "warren","Though this is only the entrance, hopefully it won't all look like this",
      });
   replace_program("room/room");
}
