inherit "room/room";

#define C capitalize
#define who previous_object()

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {set_light(1);
    short_desc = "River";
    property=({"no_teleport","no_fight"});
    long_desc =
    "You are floating down a swiftly moving river.   The currents are pulling you under!!\n";
    smell = "<cough> You inhale some water....";
    items = ({"cave","It is cold and damp",
    "passage","It is cold and damp",
    "river","It's cold!"});}}

void init()
  {::init();
  add_action("grab","grab");
  add_action("s","swim");
  this_player()->reduce_hit_point(15);
  call_out("move",7,this_player());}

void move(object ob)
  {say(C(ob->query_name())+" floats down the river...\n");
  transfer(ob,"players/kawai/areas/dwarves/river7");
  command("look",ob);}

status grab(string str)
  {if(!str ||str!="dock") 
    {notify_fail("Grab what?\n");
    return 0;}
  write("Too late!\n");
  return 1;}

status s() 
  {write("The currents are too strong.\n");
  return 1;}
