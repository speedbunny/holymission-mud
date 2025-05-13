inherit "room/room";
#include <lw.h>

void reset(int arg)
  {if(!arg)
    {clone_list=({1,1,"kq1-axe","/players/kawai/obj/pickaxe",0});
    set_light(1);
    short_desc = "Wheat field";
    long_desc = "You're in a small, dirty basement, that looks as if it is still "+
    "being tunneled.  A mysterious glowing portal hovers to the "+
    "north, and a trap door leads upwards.\n A sign on a post sits next to the portal.\n";
    smell = "The air damp and musty";
    dest_dir = ({"players/kawai/workroom","north",
    "players/kawai/areas/shack","up"});
    items = ({"room","It is large and illuminated by the gateway to the north",
    "tunnel","The basement is slowly expanding",
    "trap","It is the only way out, other than the portal",
    "door","It leads back up to the shack",
    "trap door","It leads back up to the shack",
    "post","A piece of wood",
    "portal","It is the gateway into Kawai's PRIVATE workroom!",
    "basement","It is still being dug, so there isn't much going on",
    "sign","####################\n"+
    "#                  #\n"+
    "#    Welcome to    #\n"+
    "#      Kawai's     #\n"+
    "#     Workroom     #\n"+
    "#                  #\n"+
    "#  Enter at your   #\n"+
    "#    own risk!     #\n"+
    "#                  #\n"+
    "####################\n"});}
  ::reset(arg);}

void init()
  {::init();
  add_action("exit_it","up"); 
  add_action("north","north");
  add_action("open_it","open");
  add_action("close_it","close");
  add_action("read","read");}

status north()
  {if(this_player()->query_level()<30)
    {writelw("An image of the great Kawai appears before you and says: "+
    "Come back when you are a higher level.  I can't let just ordinary "+
    "adventurers wander around my private chambers!\n");
    return 1;}
  else
    {return 0;}}

status close_it(string str)
  {if(!str) 
    {notify_fail("Close what?\n");
    return 0;}
  else if(str=="door"||str=="trapdoor") 
    {write("Hey...that was easy!  Maybe too easy...");
    return 1;}
  else
    {return 0;}}


status open_it(string str)
  {if(!str)
    {notify_fail("Open what?\n");
    return 0;}
  else if(str=="door"||str=="trapdoor") 
    {writelw("As you reach for the trap door, you come to the conclusion that "+
    "if you're not going to go through it, you might as well not even open "+
    "it!  That IS the point of a trap door, isn't it?  I mean, who ever heard "+
    "of leaving random trap doors open all the time?  Wouldn't that make it "+
    "just a WEE BIT obvious?  Hmmmm?  That's why there's a rug on the other "+
    "side, so people can't see it!  So next time you do something stupid "+
    "like that, think about it first!\n");
     return 1;}
  else
    {return 0;}}


status exit_it()
  {object gopher;
  gopher=clone_object("obj/treasure");
  gopher->set_id("gopher");
  gopher->set_short("");
  gopher->set_long("");
  if (!present("gopher",this_player())) 
    {transfer(gopher,this_player());}
  return 0;}

status read(string str)
  {if(!str||str!="sign") 
    {notify_fail("Read what?\n");
    return 0;}
  write("####################\n"+
  "#                  #\n"+
  "#    Welcome to    #\n"+
  "#      Kawai's     #\n"+
  "#     Workroom     #\n"+
  "#                  #\n"+
  "#  Enter at your   #\n"+
  "#    own risk!     #\n"+
  "#                  #\n"+
  "####################\n");
  return 1;} 
 
