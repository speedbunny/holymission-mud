inherit "room/room";

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {set_light(1);
    property=({"no_teleport"});
    short_desc = "Mine shaft";
    long_desc = "You are sliding down a mine shaft.\n";
    smell = "The air chalky";}} 

void init()
  {::init();
  add_action("cl","climb");
  call_out("movem",10,0);}

status cl()
  {write("The walls are to steep and slippery...\n");
  return 1;}

void movem()
  {this_player()->move_player("down#players/kawai/areas/dwarves/mine");
  return;}


