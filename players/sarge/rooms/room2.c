inherit "room/room";

int is_open, found_door;

void reset(int arg) 
  {::reset(arg);
  is_open=0;
  found_door=0;
  if(!arg)
    {set_light(1);
    short_desc="At a gate";
    long_desc=
    "Through the mist you can see what appears to be a large, stone gate.  "+
    "It is much too tall to climb over, and the doors are probably much too "+
    "heavy to push open.  Looking around, however, you do notice something "+
    "peculiar about the mist near the gate.@@check_door@@";
    items=({
     "mist","A grey mist swirls around the air, limiting visibility.  It appears\n"+
            "something may be hidden under the mist towards the gate",
     "stone","It is an unusual stone, one you are not familiar with.  It is\n"+
             "bloodstained",
     "gate","A tall gate made from a strange, bloodstained stone",
     "door","The stone door is much too heavy to move",
     "doors","The stone doors are much too heavy to move",  
     "blood","Probably the blood of others, like yourself, who have traveled\n"+
             "through these parts"});
    dest_dir=({"/room/well","leave"});}}


void init() 
  {::init();
  add_action("search","search");
  add_action("down","down");
  add_action("open","open");
  add_action("close","close");}


string check_door()
  {if(!found_door)
     {return "\n";}
  else if(!is_open)
     {return "\nEnshrouded in mist is a trapdoor leading down.  It is closed.\n";}
  else
     {return "\nEnshrouded in mist is a trapdoor leading down.  It is open.\n";}}


status open(string arg) 
  {if(!arg)
    {notify_fail("Open what?\n");
    return 0;}
  if(arg=="trapdoor"||arg=="door")
    {if(!found_door)
      {printf("You do not see a %s here to open.\n",arg);
      return 1;}
    else
      {if(is_open)
        {write("It is already open.\n");}
      else
        {is_open=1;
        write("You open the trapdoor\n");
        tell_room("players/sarge/rooms/room2",
        "You sense movement within the mist.\n");}
      return 1;}}
  else
    {notify_fail("You can't open that.\n");
    return 0;}}
  

status close(string arg) 
  {if(!arg)
    {notify_fail("Close what?\n");
    return 0;}
  if(arg=="trapdoor"||arg=="door")
    {if(!found_door)   
      {write("You can't see any door here.\n");
      return 1;}
    if(!is_open)
      {write("It is already closed.\n");
      return 1;}
    else
      {is_open=0;
      write("You close the trapdoor\n");
      tell_room("players/sarge/rooms/room2",
      "You sense movement within the mist.\n");
      return 1;}}
  else
    {notify_fail("You can't close that.\n");
    return 0;}}


status search(string arg) 
  {if(!arg) 
    {notify_fail("Search what?\n");
    return 0;}
  if(arg=="mist") 
    {if(found_door) 
      {write("You find nothing special.\n");
      return 1;}
    else
      {write("You have just found a trapdoor!\n");
      tell_room("players/sarge/rooms/room2",
      "You sense movement within the mist.\n");
      found_door=1;
      return 1;}}
  else
    {notify_fail("You find nothing special.\n");
    return 0;}}


status down() 
  {if(!found_door)
    {notify_fail("You can't go that way.\n");
    return 0;}
  if(!is_open)
    {write("The trapdoor is closed.\n");
    return 1;}
  else 
    {this_player()->move_player("enters the mist#"+
    "players/sarge/rooms/room3");
    return 1;}}
