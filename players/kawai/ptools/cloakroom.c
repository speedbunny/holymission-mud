inherit "room/room";

void reset(int arg)
  {::reset(arg);
  if(!arg) {
  set_light(0);
  long_desc="";
  short_desc="";}}

void init()
  {::init();
  add_action("chk","",1);}

status chk(string str)
  {string verb;
  verb=query_verb();
  if(verb=="who"||verb=="rwhere"||verb=="goto"||verb=="home"||verb=="uncloak")
    {return 0;}
  else if(verb=="l"||verb=="look")
    {write("You can't see much while cloaked.\n");}
  else
    {write("You can't do that while cloaked!\n");}
  return 1;}
