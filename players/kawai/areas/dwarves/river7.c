inherit "room/room";

#define C capitalize
#define who previous_object()

void reset(int arg)
  {::reset(arg);
  if(!arg) 
    {property=({"no_teleport","no_fight"});
    set_light(1);
    short_desc = "River";
    long_desc = "You're going under!!!\n";
    smell = "<cough> You inhale some water....";
    items = ({"cave","It is cold and damp",
    "passage","It is cold and damp",
    "river","It's cold!"});}}

void init()
  {::init();
  add_action("grab","grab");
  add_action("s","swim");
  this_player()->reduce_hit_point(15);
  call_out("move",5,this_player());}

void move(object ob)
  {say(C(ob->query_name())+" floats down the river...\n");
  write("\nYou pass out for some time.....when you awake\n\n");
  transfer(ob,"players/kawai/areas/wcave");
  tell_room(ob,capitalize(ob->query_real_name())+" floats into the pool.\n");
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
