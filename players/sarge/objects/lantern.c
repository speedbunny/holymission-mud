inherit "obj/treasure";

int get()
  {return 1;}

int drop()
  {return 1;}

void reset(int arg)
  {::reset(arg);
   if(arg)
     return;
   set_id("lantern");
   set_short("A strange lantern");
   set_long("A strange lantern, maybe you could rub it?\n"+
   "Or maybe 'visit'");}

void init()
  {::init();
  add_action("rub","rub");
  add_action("visit","visit");}

status rub(string str)
  {if(!id(str))
    {notify_fail("Rub what?\n");
    return 0;}
  if(!find_living("sarge"))
    {write("Sorry, but Sarge is not here at the moment.\n");
    return 1;}
  else
    {object me;
    me=find_living("sarge");
    call_other(me,"move_player",environment(this_player()));
    tell_object(me,"You have been summoned!!\n");
    return 1;}}

status visit(string arg)
  {if(!arg)
    {if(environment(this_player()) == find_object("room/church"))
      {write("You hold your locket and close your eyes.\n");
      write("When you open them, you're in a different place.\n");
      write(this_player()->query_name()+ " holds a lantern and vanishes.\n");
      call_other(this_player(),"move_player","leaves#/players/sarge/workroom");
      return 1;}
    write("You have to be in the church to do that.\n");
    return 1;}
  return 0;}

string query_auto_load()
  {return "players/sarge/objects/lantern:";}
