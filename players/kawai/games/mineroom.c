#define CONNECT "players/kawai/areas/slope1.c"

inherit "room/room";

void reset(int arg)
  {if(!arg)
    {clone_list=({1,1,"dispenser","/players/kawai/games/disp",0});
    short_desc="A small cavern";
    long_desc=
    "The small cavern appears fairly typical--dark and damp.\n";
    dest_dir=({CONNECT,"west"});
    set_light(1);}
  ::reset(arg);
 replace_program("room/room");}
