
/* guard room */

inherit "/room/room";
#include "defs.h"

object watchman,sturdy_sword,dog;
int *ring_chain, count;

void make_rings()
{
     int i,y,r;

     ring_chain = ({1,2,3});

     for(i=0;i<5;i++)
     {
         r=random(30)/10;
         y=ring_chain[0];
         ring_chain[0]=ring_chain[r];
         ring_chain[r]=y;
     }
     count = 0;
}

void reset(int flag)
{
     ::reset(flag);
     make_rings();
     if (!watchman) 
     {
       watchman = clone_object("obj/monster");
       call_other(watchman, "set_name", "watchman");
       call_other(watchman, "set_level",18);
       call_other(watchman, "set_short", "The night watchman is here");
       call_other(watchman, "set_ac", 10);
       call_other(watchman, "set_wc",25);
       call_other(watchman, "add_money",800);
       call_other(watchman, "set_aggressive", 1);
       move_object(watchman, this_object());

       sturdy_sword  = clone_object("obj/weapon");
       call_other(sturdy_sword, "set_name", "A sword");
       call_other(sturdy_sword, "set_short", "A sturdy sword");
       call_other(sturdy_sword, "set_class",15);
       call_other(sturdy_sword, "set_alt_name", "sword");
       call_other(sturdy_sword, "set_alias","sword");
       call_other(sturdy_sword, "set_value",700);
       call_other(sturdy_sword, "wield","sword");
       move_object(sturdy_sword, watchman);

       dog  = clone_object("obj/monster");
       call_other(dog, "set_name", "dog");
       call_other(dog, "set_short", "A guard dog is here");
       call_other(dog, "set_ac",4);
       call_other(dog, "set_level",6);
       call_other(dog, "set_wc",12);
       call_other(dog, "set_aggressive", 1);
       move_object(dog, this_object());
     }
     if (flag == 0)
     {
         set_light(0);
         short_desc = "The guards room";
         long_desc = BS(
         "You have entered the guardsroom of kanteles castle. "+
         "You can leave to east into a hall, west into a torture room "+
         "and south into a dungeon corridor. "+
         "There are three large iron rings is fastened in the wall."); 
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling id made if red bricks",
            "walls","The walls are made of red bricks",
            "rings","3 big iron rings, maybe you can pull them",
         });
         dest_dir =
         ({
             PATH+"torture_chamber","west",
             PATH+"west_bridge","east",
             PATH+"dungeon_corridor","south",
         });
      }
}

void init()
{
    add_action("do_pull","pull");
    ::init();
}

int do_pull(string arg)
{
    int x;

    if (!arg)
        return 0;
    else if (arg=="ring" || arg=="rings")
    {
       write("Which of the rings do you want to pull first ?\n");
       return 1;
    }
    else if (!present("long hook",this_player()))
    {
       write("The rings are hanging to high, you can't reach them.\n");
       return 1;
    }

    switch(arg)
    {
      case "ring 1":
      case "ring one":
      case "first ring":
           x = 1;
           break;
      case "ring 2":
      case "ring two":
      case "second ring":
           x = 2;
           break;
      case "ring 3":
      case "ring three":
      case "third ring":
           x = 3;
           break;
      default: return 0;
     }
     if (ring_chain[count]==x)
     {
        count++;
        if (count == 3)  
            tell_room(this_object(),"Knarrrrrk, the drawbridge lowers.\n");
        else 
            tell_room(this_object(),"Knarrrrrk.\n");
     }
     else if (count != 0)
     {
          count = 0;
          tell_room(this_object(),"Rummmps.\n");
     }
     else
     {
         tell_room(this_object(),"Click.\n");
     }
     return 1;
}


int move(string arg)
{
     if (!arg)
          arg = query_verb();

     if (arg=="south" && count != 3)
     {
         write("But you need to lower the drawbridge first.\n");
         return 1; 
     }
    return ::move(arg);
}
       
        
