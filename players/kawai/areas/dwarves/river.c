inherit "room/room";

#define C capitalize
#define who previous_object()

int tick;

void reset(int arg)
  {::reset(arg);
  tick=0;
  if(!arg) 
    {tick=0;
    set_light(1);
    short_desc = "River";
    property=({"no_teleport","no_fight"});
    long_desc = "You are floating down a swiftly moving river.\n";
    smell = "<cough> You inhale some water....";
    items = ({"cave","It is cold and damp",
    "passage","It is cold and damp",
    "river","It's cold!"});}}

void init()
  {::init();
  add_action("grab","grab"); 
  add_action("s","swim");
  tick=1;
  call_out("move",10,this_player());}

int query_river() 
  {return tick;}

void move(object ob) 
  {say(C(ob->query_name())+" floats down the river...\n");
  transfer(ob,"players/kawai/areas/dwarves/river2");
  command("look",ob);
  call_out("clear_tick",5,0);}

void clear_tick()
  {tick=0;}

status grab() 
  {notify_fail("There is nothing to grab on to!\n");
  return 0;}

status s() 
  {write("The currents are too strong.\n");
  return 1;}
