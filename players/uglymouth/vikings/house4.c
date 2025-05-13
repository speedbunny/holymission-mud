/* just a strange house, can collapse */
inherit "room/room";
int coll;

void reset(int arg) {
   coll=0;
   if(arg) return;

   set_light(1);
   short_desc="A burned out building";
   long_desc="This building has burned out completely. \n"
           + "Only the framework and the outer walls are still standing. \n"
           + "It looks like it can collapse if you sneeze too loud. \n";
   dest_dir=({"/players/uglymouth/vikings/villroad3","north", });
   items=({"buiding","You can't make out any more what purpose it served before the fire",
           "framework","The girders are all black and look rather fragile",
           "walls","They're all badly burned and partly collapsed", });
   enable_commands();
   }

int catch_tell(string str) {
object *pers;
string name;
int i;
   if(coll==1) return 0;
   if(sscanf(str,"%s arrives",name)==1 || sscanf(str,"%s leaves",name)==1) return 0;
   if(random(3)>0) return 0;
   tell_room(this_object(),"That was too much for this wreck. It collapses on your head!! \n");
   tell_room("/players/uglymouth/vikings/villroad3","With a loud thunder the southern building collapses. \n");
   pers=all_inventory(this_object());
   for(i=0;i<sizeof(pers);i++) {
      if(pers[i]->query_player()) {
         pers[i]->hit_player(random(75)+25);
         pers[i]->stop_fight();
         pers[i]->stop_fight();
         pers[i]->stop_hunter(1);
         }
      }
   long_desc="You're standing between the remains of a collapsed building. It's hard \n"
           + "to move through the broken framework, as the beams start shifting at \n"
           + "every move you make. \n";
   coll=1;
   return 1;
   }
