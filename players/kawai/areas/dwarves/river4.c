inherit "room/room";

#define C capitalize
#define who previous_object()

void reset(int arg)
  {::reset(arg);
  if(!arg) 
    {set_light(1);
    short_desc = "River";
    property=({"no_teleport","no_fight"});
    long_desc = "You are floating down a swiftly moving river.  You are passing by a small "+
    "village.  A small dock is approaching quickly...\n";
    smell = "<cough> You inhale some water....";
    items = ({"cave","It is cold and damp",
    "village","You pass by several small buildings along the shore",
    "building","You can't see much while floating in a river",
    "buildings","You can't see much while floating in a river",
    "shore","Just some dangerous looking rocks...",
    "dock","The dock is approaching quickly, and you think it may be a good idea\n"+
    "to grab on to it",
    "passage","It is cold and damp",
    "river","It's cold!"});}}

void init()
  {::init();
  add_action("grab","grab");
  add_action("s","swim");
  call_out("move",10,this_player());}

void move(object ob)
  {say(C(ob->query_name())+" floats down the river...\n");
  transfer(ob,"players/kawai/areas/dwarves/river5");
  command("look",ob);}

status grab(string str)
  {if(!str ||str!="dock") 
    {notify_fail("Grab what?\n");
    return 0;}
  write("You wait for the dock to approach and pull yourself on....\n");
  say(this_player()->query_name()+" grabs on to the dock.\n");
  transfer(this_player(),"players/kawai/areas/dwarves/dock");
  remove_call_out("move");
  return 1;}


status s()
  {write("The currents are too strong.\n");
  return 1;}
