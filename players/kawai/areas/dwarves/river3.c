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
    "village.  You see what appears to be a dock some ways down the river.\n";
    smell = "<cough> You inhale some water....";
    items = ({"cave","It is cold and damp",
    "passage","It is cold and damp",
    "village","As you float by, you notice several dwarves stop and look at you as\n"+
    "you struggle to stay afloat",
    "dock","While still far down the river, it looks as if you could grab it as you\n"+
    "approach it",
    "dwarves","You can't see much while floating in a river, but you hear their laughter",
    "dwarf","He is laughing at you",
    "river","It's cold!"});}}

void init()
  {::init();
  add_action("grab","grab");
  add_action("s","swim");
  call_out("move",10,this_player());}

void move(object ob)
  {say(C(ob->query_name())+" floats down the river...\n");
  transfer(ob,"players/kawai/areas/dwarves/river4");
  command("look",ob);}

status grab(string str)
  {if(!str ||str!="dock") 
    {notify_fail("Grab what?\n");
    return 0;}
  write("The dock is too far ahead...\n");
  return 1;}

status s() 
  {write("The currents are too strong.\n");
  return 1;}
