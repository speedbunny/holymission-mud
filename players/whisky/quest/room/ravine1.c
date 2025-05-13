#include "../monkway.h"
inherit "room/room";
    object rat,wolf;
    int i; 

reset(arg) {
  i=0;
    
     if (!wolf) {
     
      wolf=clone_object("players/whisky/genobj/wolf");
      move_object(wolf,this_object());
      wolf->command("east");
      
      }
   
  if (arg) return;
   
  set_light(1);
  short_desc = "In a ravine";
  long_desc =
    "You are standing in a ravine. There are big rocks to\n"+
    "the north and south. A small path is leading further to the\n"+
    "west and east. There are some heavy stones lying on the bottom.\n"+
    "A big wooden SIGN is standing beside the path.\n";
    
  items =
    ({
     "rocks","Big grey rocks",
     "rock","A big grey rock",
     "stone","A big grey stone",
     "path","You see a small path leading to the west and east",
     "sign","You see a big wooden sign and the letters\n\n"+
            "Warning !!!!\n"+
            "This path was the death of a lot of strong adventurers.\n"+
            "The rocks are too dangerous to climb and this area is\n"+
            "the favorite place for a lot of dangerous animals.\n\n"+
            "                             The Major\n\n",
     "stones","Big grey stones",
     "bottom","A grey stony bottom",
     "sky","A clear blue sky" });
     
  dest_dir =
     ({
     PATH+"ravine2","west",
    "room/south/sforst24","east" 
     });


     if (!rat) {
     rat=clone_object("obj/monster");
     rat->set_name("rat");
     rat->set_short("A little rat");
     rat->set_long("A little brown rat.\n");
     rat->set_level(1);
     rat->set_move_at_reset();
     rat->set_wimpy(100);
     move_object(rat,TO);
     move_object(clone_object("players/whisky/garden/obj/rat_fur"),rat);
     rat->init_command("wear fur");
     rat->init_command("west");
    }
      
  }

  init() {
  
    object ob;
      ob=present("wolf",this_object());
      if (ob) {
         ob->command("east");
         }
         
    if (rat=present("rat")) call_out("run",20,rat);
    add_action("search","search");
    add_action("pass","pass");
    add_action("pass","climb");
    add_action("read","read");
    ::init();
   }

  read(arg) {
    if (arg!="sign") return;
     write( "You read:\n\n"+
            "Warning !!!!\n"+
            "This path was the death of a lot of strong adventurers.\n"+
            "The rocks are too dangerous to climb and this area is\n"+
            "the favorite place for a lot of dangerous animals.\n\n"+
            "                             The Major\n\n" );
     return 1;
     
   }
    
  run(arg) {
    if(arg) arg->command("east");
    }

  search(arg) {
   object stick;

   switch(arg) {
    case "rock":
    case "rocks":
    write("You search under the rocks, but find nothing.\n");
    say(TPN+" searches under the rocks, but finds nothing.\n");
    break;
    case "stone":
    case "stones":
    if (i < 1) {
       stick=clone_object("obj/torch");
       stick->set_name("stick");
       stick->set_short("A stick");
       stick->set_long("An oak wooden stick.\n");
       stick->set_fuel(800);
       move_object(stick,E(TP));
       write("You search under the stones, and find a stick.\n");
       say(TPN+" searches under the stones, and finds a stick.\n");
       }
     else {
       write("You search under the stones, but finds nothing.\n");
       say(TPN+" searches under the stones, but finds nothing.\n");
       }
    break;
    case "bottom":
    write("You search on the bottom, but find nothing.\n");
    say(TPN+" searches on the bottom, but finds nothing.\n");
    break;
    default:
    write("You search around, but you find nothing.\n");
    say(TPN+" searches around, but you finds nothing.\n");
    return 1;
    }
   return 1;
  }
  
  pass(arg) {
    switch(arg) {
     case "rock":
     case "rocks":
     write("You try to climb the rocks.\n");
     write("OUCH! You fall and hurt yourself.\n");
     say(TPN+" tries to pass the rocks, but falls down.\n");
     TP->hit_player(random(80));
     break;
     default:
     write("You can't do that.\n");
     return 1;
    }
   return 1;
  } 
    

  
   
