#include "../monkway.h"
inherit "room/room";
   object ob;
   int flower_count, grass_count;
    

reset(arg) {
     object inv;
     inv=all_inventory(this_object());
    
    
     if (!inv || !sizeof(inv)) {
      switch(random(5)) {
      
      case 0:
      move_object(clone_object("players/whisky/tree/monster/ant"),this_object());
      break;
      case 1:
       move_object(clone_object("players/whisky/tree/monster/swarm"),this_object());
      break;
      case 2:
       move_object(clone_object("players/whisky/tree/monster/louse"),this_object());
      break;
      case 3:
       move_object(clone_object("players/whisky/tree/monster/butterfly"),this_object());
      break;
      case 4:
       move_object(clone_object("players/whisky/tree/monster/caterpillar"),this_object());
      break;     
      default:
      return;
      }
    }
 

   flower_count=4;
   grass_count=8;
   
  ::reset(arg);
  

  if (arg) return;
  smell="You  smell blooming flowers !";
  set_light(1);
  short_desc = "On a little meadow";
  long_desc =
    "You are standing on a  little, lit meadow. The sun is shining\n"+
    "on your face. The bottom is soft and the grass is wet and high.\n"+
    "There are nearly any kind of flowers growing on this meadow and\n"+
    "you can see some big rocks to the east and north.\n";
  items =
    ({
     "rocks","Big grey rocks",
     "rock","A big grey rock",
     "meadow","@@query_meadow@@",
     "sun","You see the bright light of the sun burning at your face",    
     "bottom","A soft, wet bottom",
     "grass","@@query_grass@@",
     "flowers","@@query_flowers@@",
     "sky","A clear blue sky" });
  dest_dir =
     ({
     PATH+"meadow12","northwest",
     PATH+"meadow8","southeast",
     PATH+"meadow7","south",
     PATH+"meadow10","west",
     
     });

    
  }

  init() {
    add_action("search","search");
    add_action("pass","pass");
    add_action("pass","climb");
    add_action("take","get");
    ::init();
   }

 

  search(arg) {
    if (!arg) return;
    write("You search around, but find nothing.\n");
    say(TPN+" searches around.\n");
    return 1;
   }
     
  pass(arg) {
    switch(arg) {
     case "rock":
     case "rocks":
     write("You try to pass the rocks, but you stumble and fall down.\n");
     say(TPN+" tries to pass the rocks, but falls down.\n");
     TP->hit_player(random(20)); /* the wet bottom is a bit softer */
     break;
     default:
     write("You can't do that.\n");
     return 1;
    }
   return 1;
  } 
  
  
  take(arg) {
   object ob;
   
   if (arg=="grass" && grass_count) {
       ob=clone_object("obj/food");
       ob->set_name("grass");
       ob->set_alias("some grass");
       ob->set_short("Some gras");
       ob->set_long("Some green grass.\n");
       ob->set_value(1);
       ob->set_strength(1);
       ob->set_weight(1);
       ob->set_eater_mess("Jumpf Jumpf Jumpf");
       ob->set_eating_mess("eats some grass");
       if (transfer(ob,TP)) {
          write("You can't carry that much.\n");
          transfer(ob,environment(TP));
          grass_count--;
          return 1;
          }
       write("You get some grass.\n");
       say(TPN+" gets some grass.\n");
       transfer(ob,TP);
       grass_count--;
       return 1;
       }
    else if (arg=="grass" && !grass_count) {
         write("There is no grass left.\n");
         return 1;
       }
          
   else if ((arg=="flower" || arg=="flowers") && flower_count) {
   
       ob=clone_object("obj/food");
       ob->set_name("flowers");
       ob->set_alias("some flowers");
       ob->set_short("Some flowers");
       ob->set_long("Some beautiful flowers.\n");
       ob->set_value(10);
       ob->set_strength(2);
       ob->set_weight(1);
       ob->set_eater_mess("Jumpf Jumpf Jumpf");
       ob->set_eating_mess("eats some beautiful flowers");
       if (transfer(ob,TP)) {
          write("You can't carry that much.\n");
          transfer(ob,environment(TP));
          flower_count--;
          return 1;
          }
       write("You get some flowers.\n");
       say(TPN+" gets some flowers.\n");
       transfer(ob,TP);
       flower_count--;
       return 1;
       }
       else if ((arg=="flower" || arg=="flowers") && !flower_count) {
         write("There are no flowers left.\n");
         return 1;
       }
       
    else {
      return;
      }
   }
    
  query_grass() {
    if (grass_count) 
       return "You see some wet grass";
    else
       return "You see only the roots of grass ** how sad **";
       }
  
  query_flowers() {
    if (flower_count>1) 
      return "You see some beautiful flowers";
    else if (flower_count)
      return "You see a beautiful flower";
    else 
      return "You see only the stems of flowers ** how sad **";
      }
      
  query_meadow() {
    return extract(long_desc,0,strlen(long_desc)-3);
    }
    
   
