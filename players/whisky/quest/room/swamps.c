#include "../monkway.h"
inherit "room/room";
   object hunt;
   int test;
      
reset(arg) {    
       
  ::reset(arg);
   test = 1;
  

  if (arg) return;
  set_light(1);
  short_desc = "By a big swamp";
  long_desc =
    "You are leaving the dark cavern. There are big rocks to the north\n"+
    "and south and there is a big swamp to the west. The moon is shining\n"+
    "in your face and you can hear a loud howling coming from the swamp.\n";
    
   
    
  items =
    ({    
     "rock","Big dark rocks, with an entrance to a small cavern to the west",
     "rocks","Some big rocks, with an entrance to a small cavern to the west",
     "cavern","You see a big dark cavern to the east",
     "swamp","You see a big, dark swamp",    
     "bottom","A soft, wet bottom",
     "moon","You see the moon shining into your face" });

  dest_dir= ({
        PATH+"cavern2","east",
        });        
    }
        
  init() {
    if (hunt && interactive(TP))
    {
       write("Suddenly you see a big wolf leaving into the swamp.\n");
       destruct(hunt);
       }
    add_action("search","search");
    add_action("pass","pass");    
    add_action("pass","climb");
    add_action("enter","enter");
    add_action("blow","blow");
    add_action("west","west");
    add_action("take","get");
    ::init();
   }

 search(arg) {
   if (!arg) return;
   write("You search around, but find nothing.\n");
   say(TPN+" searches around, but finds nothing.\n");
   return 1;
  }
  
 blow(arg) {
   if ((arg!="horn" && arg!="hunting-horn")) return;
   if (!present("hhorn",TP)) return;
   
    write("T U U U U T  you blow the hunting-horn !\n");
    say(TPN+" blows the hunting-horn !\n");
    if (test && !present("wolf",this_object()))
    {
       test--;
     call_out("hunt_me",4);
    }
    else {
      write("Nothing happens !\n");
      }
   return 1;
   }
  
  hunt_me() {
    write("Suddenly the howling gets louder and you get the the feeling you should better leave this place !\n"); 
    say("Suddenly the howling gets louder and you get the the feeling you should better leave this place !\n");
    call_out("come_hunt",4);
    }
    
  come_hunt() {
    write("Suddenly a big black wolf arrives, bigger than you ever seen before !\n");
    say("Suddenly a big black wolf arrives, bigger than you ever seen before !\n");
    hunt = clone_object("/players/whisky/quest/monster/hunt");
    move_object(hunt,this_object());
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
    if (arg!="rock" && arg!="rocks" && arg!="stone" && arg!="stones") return;
       write("You can't take that.\n");
       return 1;
     }
    
  west() {
    write("You dont dare to enter the swamp !!!!\n");   
  return 1;
  }
    
  enter(arg) {
    if (arg!="swamp") return;
       write("You dont dare to enter the swamp !!!!\n");   
  return 1;
  }
