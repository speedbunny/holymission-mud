
/* portal */

#include "defs.h"

#define COST 100

int portal(string arg)
{
   object portal, mob, where, po;
   string what, alias;
   string file;


     if (_tp->query_ghost())
     {
         write("You can' do this in your immaterial state !\n");
         return 1;
     }
     if (_tpw < 20)
     {
        write("You aren't wise enough to pray for a portal !\n");
        return 1;
     }
   if (stringp(arg))
   {
     call_other(_obj+"portals","???");

     if (arg == "list")
     {
         if (po = find_object(_obj+"portals"))
             po->show_places(_tpr);
          return 1;
     }
     else if (sscanf(arg,"%s %s",what,alias)==2)
     {
          if (what == "set")
          {
             if (_e(_tp)->query_property("no_teleport"))
             {
                 write("Magical barriers hinder you to store that place.\n");
                 return 1;
             }
            if (po = find_object(_obj+"portals"))
                po->add_place(_tpr,alias,file_name(_e(_tp)));
            return 1;
          }
          else if (what == "remove")
          {
            if (po = find_object(_obj+"portals"))
                po->remove_place(_tpr,alias);
            return 1;
          }
          else 
            return 0;
       }
     }
     if (_tps < COST) 
     {
         write("You can't conzentrate enough on a portal !\n");
         return 1;
     }
     else
     {
          portal = clone_object(_obj+"portal");

          if (stringp(arg))
          {
                call_other(_obj+"portals","???");
                po = find_object(_obj+"portals");
                file = po->exist_place(arg,_tpr);

                if (po && stringp(file))
                {
                  portal->set_dest(file);
                }
             else 
            {
               write("No such stored place found.\n");
               destruct(portal);
               return 1;
              }
           } 
           write("You concentrate and summoned a portal from nowhere !\n");
           say("Suddenly a glowing wheel appears !\n",_tp);
           move_object(portal,_e(_tp));
           _tp->restore_spell_points(-COST);
           return 1;
       }
    return 1;
}
          

     
