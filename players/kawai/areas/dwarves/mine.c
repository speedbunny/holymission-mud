inherit "room/room";

void reset(int arg)
  {clone_list=({1,1,"ore","/players/kawai/obj/ore",0});
  hidden_dir=({"players/kawai/areas/dwarves/river","dive"}); 
  set_light(1);
  short_desc = "Mine";
  long_desc = "You are standing in an abandoned mine. The walls have been "+
  "smoothed by years of mining, and little is left of value.  An "+
  "underground river flows through here, and was probably once "+
  "used by the miners to transport ore.\n";
  property=({"no_teleport"});
  smell = "The air is damp.";
  items = ({"cave","It is cold and damp",
  "passage","It is cold and damp",
  "shaft","You can't reach it",
  "river","It looks dangerous, but is probably the only way out.  You might want\n"+
  "to dive in",
  "walls","They have been completely cleared of anything of value",
  "wall","It has been mined completely"});
  ::reset(arg);}

void init()
  {::init();
  tell_object(this_player(),"You tumble out of the shaft....\n");
  say(capitalize(this_player()->query_name())+" tumbles in through the shaft.\n");
  add_action("climb","climb");}

status climb(string str)
  {if(!str || str!="shaft") 
    {notify_fail("Climb what?\n");
    return 0;}
  write("You can't reach it!\n");
  return 1;}


dive()
  {if(call_other("players/kawai/areas/dwarves/river","query_river",0)) 
    {write("The currents look to strong right now...you should wait\n"+ 
    "a moment for the river to calm down.\n");
    return 1;}
  return;}   
