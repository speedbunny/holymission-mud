
/* command */

inherit "/players/whisky/obj/std_shadow";

#define notify(x) tell_object(me,x)

int com_followers(object *fol,string what)   
{
   int i, sz, h;
   object *all;

   all = fol;
   h = 0;

   for (sz=sizeof(all),i=0;i<sz;i++)
   {
        if (all[i]->query_npc())
        {
            command(what,all[i]);
            h = 1;
         }
   }
   return h;
}
        
int do_command(string whom,string what)
{
   object mob;
   object *fol;
   int i, sz;

    if (!whom)
    {
        notify("Command whom ?\n");
        return 1;
    }
    fol = me->query_followers();
    mob = present(what,environment(me));  

  if (whom=="followers")
  {
      if (!fol)
      {
         notify("But you don't have a follower !\n");
         return 1;
      } 
      else if (!com_followers(fol,what))
      {
          notify("Nobody here to command !\n");
          return 1;
      }
      else 
      {
         notify("Ok.\n");
         return 1;
      }
   }
   else if (!mob)
   {
       notify("There is noone present by this name !\n");
       return 1;
   }
   else if (!mob->query_npc())
   {
        notify("You can't command a player !\n");
        return 1;
   }
   else if (member_array(mob,fol)==-1)
   {
       notify(whom+" has to follow you !\n");
       return 1;
   } 
   else 
   {
       command(what,mob);
       notify("Ok.\n");
       return 1;
   }
  return 1;
}
    
int comm_shad()
{
    return 1;
}

object comm_object()
{
     return this_object();
}

