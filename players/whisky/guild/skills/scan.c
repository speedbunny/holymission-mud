

/* =============================================================== 
   Userdoc: Scan          /players/whisky/guild/skills/scan.c
   ---------------------------------------------------------------
   Art: watching, overlooking an area for victims
   Damage || Heal: none
   Cost: none
   Special: learnable by training or master / the area means one 
            room in all not hidden directions. A scanning player
            can't look closer into the neighbourrooms.
   =============================================================== */

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
         set_partner("/players/sauron/guild/room");
}


int scan()
{
   string *dir_arr;
   object partner,*inv;
   int i, sz, i2, sz2;

   write("You look around furiously.\n");
   say(_tpn+" looks around furiously.\n",_tp);

   if (!chk_skill(_tp,"monk_scan",6))
   {
       write("You are confused.\n");
       return 1;
   }
   if (catch(dir_arr = apply(call,_e(_tp),"query_dest_dir")))
   {
       write("You are confused.\n");
       return 1;
   }  
   for(sz = sizeof(dir_arr) - 1, i=0; i < sz; i+=2)
   {
      if (catch(apply(call,dir_arr[i],"???")))
      {
         write("You are confused.\n");
         return 1;
      }
      partner = find_object(dir_arr[i]); 
      inv = all_inventory(partner);

      for (sz2 = sizeof(inv), i2 = 0; i2 < sz2; i2++)
      {
          if (living(inv[i2]) && !(apply(call,inv[i2],"query_invis")) && 
              apply(call,inv[i2],"short"))
          {
             write("You see: "+apply(call,inv[i2],"short")+
             " : "+dir_arr[i+1]+"\n");
          }
      }
   }
   return 1;
}

      
      
