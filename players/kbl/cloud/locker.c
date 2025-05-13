inherit "/players/kbl/objs/thing";
#include "/players/kbl/cloud/gen.h"

int locked;
string lock_dest;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    short_desc = "Locker device";
    long_desc = "Diamond shaped device made of dense material. It glows\n"+
                "with a enternal energy but has no outside access panels\n"+
                "or info ports.\n";
    locked = 0;
    weight = 2000;
    value = 5000;
    alt_name = "lock";
    alias_name = "locker";
    read_message = "A little label that has been altered. Now reads: \n"+
                   "            Palace Decell is where you can\n"+
                   "               see but cannot touch.\n";
    lock_dest = "none";
    ty = 1;
  }
}

init()
{
  ::init();
  add_action("unlock","unlock");
  add_action("lock","lock");
  add_action("trap","enter");
}

unlock(str)
{
  if(str == lock_dest)
  {
   if(locked)
   {
    if(present("cloud_control")->query_type() > TO->query_type())
    {
      write("You unlock the lock to "+lock_dest+".\n");
      say(CTPRN+" unlocks "+lock_dest+".\n");
      locked = 0;
      return 1;
    }
    write("Your cell control is inferior.\n");
    say(CTPRN+" tries to unlock "+lock_dest+" but fails.\n");
    return 1;
   }
   write(CP(lock_dest)+" is already unlocked.\n");
   say(CTPRN+" tries to unlock a unlocked cell.\n");
   return 1;
  }
  write("Unlock what??\n");
  return 1;
}

lock(str)
{
  if(str == lock_dest)
  {
   if(!locked)
   {
    if(present("cloud_control")->query_type() > TO->query_type())
    {
      write("You lock the lock to "+lock_dest+".\n");
      say(CTPRN+" locks "+lock_dest+".\n");
      locked = 1;
      return 1;
    }
    write("Your cell control is inferior.\n");
    say(CTPRN+" tries to lock "+lock_dest+" but fails.\n");
    return 1;
   }
   write(CP(lock_dest)+" is already locked.\n");
   say(CTPRN+" tries to lock a locked cell.\n");
   return 1;
  }
  write("Lock what??\n");
  return 1;
}
        
trap(str)
{
  if(str == lock_dest)
   if(locked)
   {
     write(CP(lock_dest)+" is locked!\n");
     say(CTPRN+" tries to enter a locked cell.\n");
     return 1;
   }
}

set_lock_dest(str)
{
  lock_dest = str;
}

set_type(n)
{
  ty = n;
}

query_type()
{
  return ty;
}
