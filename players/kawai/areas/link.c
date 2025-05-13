inherit "room/room";
#define CLOSED 0
#define BUGGY 1
#define CROOM "players/whisky/quest/room/ravine4"
#define CDIR "north"

void reset(int arg)
  {short_desc="A cave";
  set_light(1);
#if CLOSED
  long_desc="You have entered a small cave.  Scribbled in the dirt "+
  "on the floor is a message:  This area is closed for repairs!  Will "+
  "open in a few days or even hours!  ---Kawai\n";
  dest_dir=({CROOM,CDIR});
#else
#if BUGGY
  long_desc="You have entered a small cave.  The area you stand on is level, but looking "+
  "further into the cave you can see a passage slope downwards.  Scribbled inthe dirt "+
  "is a message:  This area has recently been revised.  Be aware that there may be "+
  "some previously undetected bugs.  If any are uncovered, please report them to "+
  "Kawai.\n";
  dest_dir=({"players/kawai/areas/slope1","down",
  CROOM,CDIR});
#else
  long_desc="You have entered a small cave.  The area you stand on is level, but looking "+
  "further into the cave, you can see a passage slope downwards.\n";
  dest_dir=({"players/kawai/areas/slope1","down",
  CROOM,CDIR});
#endif
#endif
  items=({"cave","You stand inside a small cave, formed naturally out of the surrounding rock",
  "room","You stand inside a small cave, formed naturally out of the surrounding rock",
  "rock","The rock forms a natural shelter",
  "passage","It leads further into the cave",
  "area","The floor is level where you stand",
  "floor","Ooooh...."});
  smell="The air is damp and smells of animal waste";
  clone_list=({1,1,"lunatic","/players/kawai/monst/lunatic",0});
  ::reset(arg);
  replace_program("room/room");}

