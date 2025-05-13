#include <lw.h>

int tick;

int id(string str)
  {return str=="kq1-statue"||str=="kazak"||str=="statue";}

int get(string str) 
  {return 0;}

string short()
  {return "A statue of Kazak";}

void long() 
  {writelw("You stand before a 12 foot statue of the demi-god Kazak. It is "+
  "a hideous creature, even when in stone.  It has 4 massive arms "+
  "and a mouth big enough to swallow a small elf whole.  The only "+
  "other word capable of describing it is ugly.  "+
  "There is a spherical indentation at its base.\n");}

void reset(int arg)
  {tick=0;}

void init()
  {add_action("l","look");
  add_action("l","l");
  add_action("put","put");
  add_action("put","place");}

status l(string str)
  {if(!str) 
    {notify_fail("Look AT what?\n");
    return 0;}
 if(str=="at statue"||str=="at kazak")
    {long();
    return 1;}
 if(str=="at indent"||str=="at indentation"||str=="at hole")
    {if(!present("kq1-orb",this_player()))
      {write("You aren't sure what it is used for.\n");
      return 1;}
    write("It looks just about big enough to place the orb in.\n");
    return 1;}}

status put(string str)
  {string a,x;object orb;
  if(!str) 
    {notify_fail("Put what where?\n");
    return 0;}
  if(sscanf(str,"%s in %s",a,x))
    {if(x=="indent"||x=="indentation"||x=="hole"||x=="base"||x=="statue")
      {if(a!="orb")
        {write("That doesn't fit in there...\n");
        return 1;}
      if(!orb=present("kq1-orb",this_player()))
        {write("You don't have the orb\n");
        return 1;}
      write("You place the orb inside the "+x+"\n");
      destruct(orb);     
      set_heart_beat(1);
      return 1;}}}

void heart_beat()
  {tick++;
  if(tick==3)
    {tell_room(environment(this_object()),"The ground begins to shake...\n");}
  else if(tick==5)
    {tell_room(environment(this_object()),
    "The statue of Kazak starts to crack and crumble...\n");}
  else if(tick==8)
    {tell_room(environment(this_object()),
    "As the stone casing crumbles, Kazak emerges from within!\n");
    tell_room(environment(this_object()),lw(
    "Kazak screams: Thank you for awakening me.  I have slumbered "+
    "in that prison for centuries, awaiting for the day I would be "+
    "free!  My powers have grown, and now I will destroy this world, "+
    "starting with you!\n"));
    transfer(clone_object("players/kawai/monst/kazak"),
    environment(this_object()));
    set_heart_beat(0);
    tick=0;
    destruct(this_object());}}
