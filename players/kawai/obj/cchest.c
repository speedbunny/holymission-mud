#include "setlight.h"

#ifndef TO
#define TO this_object()
#endif

int local_weight;
int chest_is_open, chest_is_locked, locklevel;
mixed ld;

void init() 
  {add_action("open", "open");
  add_action("close", "close");
  add_action("lock","lock");
  add_action("unlock","unlock");
  add_action("force","picklock");
  add_action("force","knock");
  add_action("force","break");
  add_action("turn","turn");}

int id(string str)
  {return str=="chest";}

string short() 
  {return "chest";}

void long() 
  {write("A chest that seems to be of a high value.\n");
  if(chest_is_open)
    write("It is open.\n");
  else
    write("It is closed.\n");}

int query_value() 
  {return 200;}

int query_weight() 
  {return 8;}

int get(string str) 
  {return 0;}

int can_put_and_get() 
 {return chest_is_open;}

void add_weight(int w) 
  {if(w+local_weight>8)
    return;
  local_weight+=w;}

status close(string str)
  {if(!id(str))
    return 0;
  if(!chest_is_open)
    {write("It already is closed.\n");
    return 1;}
  chest_is_open=0;
  write("Ok.\n");
  return 1;}

status open(string str)
  {if(!id(str))
    return 0;
  if(chest_is_open)
    {write("It already is open.\n");
    return 1;}
  if(chest_is_locked)
    {write("The chest is locked.\n");
    return 1;}
  chest_is_open = 1;
  write("Ok.\n");
  return 1;}

void reset(int arg) 
  {chest_is_open=0;
  chest_is_locked=1;
  locklevel=0;
  ld=({"right","left","right","left"});
  if(!present("kq1-glo",TO))
    {move_object(clone_object("players/kawai/obj/gloves"),TO);}}
 
string query_name() 
  {return "chest";}

status lock(string str)
  {if(!id(str))
    {return 0;}
  if(chest_is_open)
    {write("You must close the chest first.\n");
    return 1;}
  if(chest_is_locked)
    {write("The chest is already locked.\n");
    return 1;}
  chest_is_locked=1;
  locklevel=0;
  write("Ok.\n");
  return 1;}

status force(string str)
  {if(!id(str))
    {return 0;}
  write("Just go find the combination....\n");
  return 1;}

status unlock(string str)
  {if(!id(str))
    {return 0;}
  if(chest_is_open)
    {write("The chest is already open, what's the point?.\n");
    return 1;}
  if(!chest_is_locked)
    {write("The chest is already unlocked.\n");
    return 1;}
  write("You must 'turn lock <dir> <num> to unlock it.\n");
  return 1;}

status turn(string str)
  {string dir;
  object ob;
  int num;
  if(!str) 
    {write("Turn what?\n");
    return 1;}
  if(sscanf(str,"lock %s %d",dir,num)!=2)
    {write("What?\n");
    return 1;} 
  if(!ob=present("kq1-pam",this_player()))
    {write("You turn the wheel "+dir+" "+num+".\n");
    return 1;}
  write("You turn the wheel "+dir+" "+num+".\n");
  if((ob->query_num(locklevel+1)==num)&&(dir==ld[locklevel]))
    {write("You hear a faint click in the lock.\n");
    locklevel++;
    if(locklevel==3)
      {write("The chest unlocks.\n");
      chest_is_locked=0;}
    return 1;}
  else
    {locklevel=0;
    return 1;}}
