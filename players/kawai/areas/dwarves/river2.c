inherit "room/room";

#define C capitalize
#define who previous_object()

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {set_light(1);
    short_desc = "River";
    property=({"no_teleport","no_fight"});
    long_desc = "You are floating down a swiftly moving river.  You see a small palace "+
    "on your right...\n";
    smell = "<cough> You inhale some water....";
    items = ({"cave","It is cold and damp",
    "palace","As you pass my, you get a glimpse of a small, yet elaborate castle\n"+
    "and a large statue in what appears to be a courtyard",
    "statue","It looks like a statue of a King",
    "courtyard","You can't see much while floating in the river",
    "castle","As you pass my, you get a glimpse of a small, yet elaborate castle\n"+
    "and a large statue in what appears to be a courtyard",
    "passage","It is cold and damp",
    "river","It's cold!"});}}

void init()
  {::init();
  add_action("grab","grab");
  add_action("s","swim");
  call_out("move",10,this_player());}

void move(object ob)
  {say(C(ob->query_name())+" floats down the river...\n");
  transfer(ob,"players/kawai/areas/dwarves/river3");
  command("look",ob);}

status grab() 
  {notify_fail("There is nothing to grab on to!\n");
  return 0;}

status s() 
  {write("The currents are too strong.\n");
  return 1;}
