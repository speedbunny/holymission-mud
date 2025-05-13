inherit "room/room";
reset (arg) {
   if (arg) return;
   clone_list=({
        1, 2, "seargent","players/bobo/monsters/seargent", 0,
   });
   ::reset (arg);
   set_light (1);
   short_desc="In the stands.";
   long_desc=
      "This area of the stands is unlike any other area that you\n"+ 
      "have come accross.  It has no spectators nor any trace of\n"+
      "them remains.  This area is void of trash and has a set of\n"+
      "steps leading up to the balcony.  There is a large sign\n"+
      "next to the stairway\n";
   dest_dir=({
        "players/bobo/arena/s9.c","northeast",
        "players/bobo/arena/s11.c","southeast",
        "players/bobo/arena/b1.c","up",
   });
items=({
        "area","This place, unlike the rest of the stands is neat, clean, and orderly",
        "spectators","There are none here nor any sign that they were here",
        "trash","There is no litter at all in this portion of the stands",
        "steps","Large well cut blocks of stone create steps leading up to the balcony",
        "sign","A large sign with words on it",
   });
}

init () {
   ::init();
   add_action("read","read");
}

read(str) {
   if(str=="sign") {
   write("The sign reads:  No spectators in this area!\n"+
         "                 No one permitted onto balcony!\n");
   return 1;
   }
}
