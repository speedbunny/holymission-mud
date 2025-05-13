
/* portal */

#include "/players/whisky/genesis/sys/break_string.h"

object dest;

void reset(int flag)
{
   if (flag == 0)  
   {
       set_light(2);
       call_out("dest_me",20);
   }
}

int id(string arg)
{
     return (arg == "portal" || arg == "wheel");
}

string short()
{
   return ("A shimmering portal (enter if you dare)");
}

void long()
{
   string desc;

   if (environment(this_player()) == environment())
       desc = "A shimmering, golden wheel.\n";
   else {
       desc = break_string( 
              "You are inside a shimmering portal. It looks like "+
              "a golden wheel surrounded by a strong magic aura. "+
              "It may teleport you to a special place by typing 'trans' "+
              "leave the portal by typing 'leave'.\n",60);
   }
   write(desc);
}

void init()
{
     add_action("do_trans","trans");
     add_action("do_leave","leave");
     add_action("do_enter","enter");
}

int do_trans(string arg)
{
 if (arg) return 0;

  write("You vanish.\n");
  say(this_player()->query_name()+" steps out of the wheel and vanishes.\n"); 

 if (objectp(dest))
   move_object(this_player(),dest);
 else 
   move_object(this_player(),"/players/whisky/guild/room/visit");

   command("look",this_player());
 return 1;
}

int do_leave(string arg) 
{
  if (arg) return 0;
  
   write("You leave the portal.\n");
   say(this_player()->query_name()+" leaves the portal.\n");
   tell_room(environment(),
             this_player()->query_name()+" steps out of the portal.\n");
   move_object(this_player(),environment());
 return 1;
}
   
int do_enter(string arg)
{
    if (arg!="portal" || environment(this_player()) != environment()) 
        return 0;
    
       this_player()->catch_tell("You enter the glowing wheel.\n");
       move_object(this_player(),this_object());
       tell_room(environment(),
       this_player()->query_name()+" enters the glowing wheel.\n");
       command("look",this_player());
    return 1;
}
       
     

    
void set_dest(object where)
{
     if (objectp(where))
         dest = where;
}

void dest_me()
{
   int sz, i;
   object *inv;
   object room;

     if (room = environment())          
        tell_room(room,"A portal vanishes.\n");

     inv = all_inventory(this_object());

     if (sz= sizeof(inv))
     {
        for (sz = sizeof(inv), i = 0; i < sz; i++)
        {
             tell_room(this_object(), "The portal vanishes.\n");
             move_object(inv[i],environment());
        }
     }
     destruct(this_object());
     return;
}

     
        
