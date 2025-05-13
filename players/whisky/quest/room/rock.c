#include "../monkway.h"
inherit "room/room";
   object ob,drake;
   int flower_count, grass_count;
    

reset(arg) {

    if (!drake) {
        drake=clone_object(MONST+"danahra");
        move_object(drake,this_object());
        }
     

   flower_count=4;
   grass_count=8;
   
  ::reset(arg);
  

  if (arg) return;
  smell="You  smell blooming flowers !";
  set_light(1);
  short_desc = "On a little meadow";
  long_desc =
    "You are standing on the western end of the little lit meadow.\n"+
    " The bottom is soft and the grass is wet and high. There are\n"+
    "nearly any kind of flowers growing on this meadow. And there\n"+
    "are big rocks all around you. To the east you see a little lake.\n";
   
    
  items =
    ({    
     "meadow","@@query_meadow@@",
     "lake","A little dark lake",
     "rock","Big dark rocks, with an entrance to a small cavern to the west",
     "rocks","Some big rocks, with an entrance to a small cavern to the west",
     "water","You see yourself",
     "sun","You see the bright light of the sun burning at your face",    
     "bottom","A soft, wet bottom",
     "grass","@@query_grass@@",
     "flowers","@@query_flowers@@",
     "sky","A clear blue sky" });
  
    
  }

  init() {
    add_action("search","search");
    add_action("pass","pass");
    add_action("dive","dive");
    add_action("swim","swim");
    add_action("pass","climb");
    add_action("west","west");
    add_action("take","get");
    ::init();
   }

 

    swim() {
     write("You enter the cold lake and start to swim.\n");
     call_out("swim2",2);
     return 1;
     }
     
    swim2() {
     write("The water is so cold that you swim for your life.\n");
     call_out("swim3",2);
     return 1;
     }
     
     swim3() {
     write("You swim and swim and suddenly you see land !\n");
     call_out("swim4",2);
     }
     
      swim4() {
     write("You crawl up and find yourself in front of a big cave.\n");
     TP->move_player("into the lake#players/whisky/quest/room/meadow5");    
     }
     
     dive() {
     write("You make a big jump into the water, Bulp....\n");
     call_out("dive2",2);
     return 1;
     }
     
    dive2() {
     write("You come deeper and deeper, you can't breath any more.\n");
     call_out("dive3",2);
     return 1;
     }
     
     dive3() {
     write("Fighting for your life you, dicide to dive up again !\n");
     TP->command("look");
     return 1;    
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
       ob->set_id("grass");
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
       ob->set_id("flowers");
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
    
  west() {
   if (present("danahra",this_object())) {
      write("The big body of Danahra bars you the way.\n");
      say(TPN+" tries to go north, but fails.\n");
      return 1;
      }
    write("You leave into the cavern.\n");
    TP->move_player("into the cavern#players/whisky/quest/room/cavern1");
    
  return 1;
  }
    
