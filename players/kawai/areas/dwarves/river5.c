inherit "room/room";

#define C capitalize
#define who previous_object()

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {set_light(1);
    property=({"no_teleport","no_fight"});
    short_desc = "River";
    long_desc = "You are floating down a swiftly moving river.  You are passing by a small "+
    "village.  You are just about to pass a small dock.  This could be your "+
    "last chance to grab on!\n";
    smell = "<cough> You inhale some water...."; 
    items = ({"cave","It is cold and damp",
    "village","You are just about past it now, and only see the backs of a few buildings",
    "buildings","You can't see much while floating down a river",
    "building","You can't see much while floating down a river",
    "dock","It isn't the sturdyest looking dock, but should be able to hold your weight if\n"+
    "you were to grab on to it",
    "passage","It is cold and damp",
    "river","It's cold!"});}}

void init()
  {::init();
  add_action("grab","grab");
  add_action("s","swim");
  call_out("move",10,this_player());}

void move(object ob)
  {say(C(ob->query_name())+" floats down the river...\n");
  transfer(ob,"players/kawai/areas/dwarves/river6");
  command("look",ob);}

status grab(string str)
  {if(!str ||str!="dock") 
    {notify_fail("Grab what?\n");
    return 0;}
  write("You quickly grab on the dock and hoist yourself aboard.\n");
  say(this_player()->query_name()+" grabs on to the dock.\n");
  transfer(this_player(),"players/kawai/areas/dwarves/dock");
  remove_call_out("move");
  return 1;}


status s() 
  {write("The currents are too strong.\n");
  return 1;}
