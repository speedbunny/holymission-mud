inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="A crossing in the secret orc caves";

  long_desc="You are standing at a crossing in the secret orc caves.  "+
            "The main corridor leads north and south.  Smaller, darker "+
            "passages lead off to the east and west.  The familiar orc "+
            "decor of blood and moss is still present, and the smell.\n";

  items=({"crossing","Caves lead to the north, south, east, and west",
          "caves","The secret orc caves are much like the known orc caves",
          "corridor","It runs north and south",
          "passages","Evil lies in the side passages",
          "decor","Blood stained walls and mossy ground",
          "blood","Blood staines the walls",
          "moss","Sinister moss growing on the ground",
        });
      
  dest_dir=({"/players/emerald/island/room/caves/room/ci18","north",
             "/players/emerald/island/room/caves/room/ci14","south",
             "/players/emerald/island/room/caves/room/ci16","east",
             "/players/emerald/island/room/caves/room/ci17","west",

           });

  smell="The stench of death.";

  ::reset(arg);
  replace_program("/room/room");

}
