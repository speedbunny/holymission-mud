#define PPATH "/players/whisky/mill_quest/"

inherit "room/room";

reset(arg){
 if(arg) return;
   set_light(1);
   short_desc = "At a spring";
   long_desc = "You are standing in front of a tiny spring.\n" 
               "This must be the spring of the river you followed up\n" 
               "to here. The water is fresh and clean and invites you\n" 
               "to drink some. There are some stones lying around.\n";
   items = ({ "stones","Some heavy grey stones",
              "ground","You see some heavy stones lying in the grass",
              "grass","The grass is dew-drenched",
              "sky","You see the blue sky",
              "spring","You see a fresh water coming out of the ground",
              "water","You see yourself !!!!" });
   dest_dir = ({ PPATH + "path4","southeast" });
}
init(){
 ::init( );
   add_action("search","search");
   add_action("push","push");
   add_action("push","move");
   add_action("drink","drink");
}
push(arg){
 if(!arg) return;
  write("You can't move that !\n");
  return 1;
 }
search(arg){
 if(!arg) return;    
   write("You search and search, but find nothing.\n");
   say(this_player()->query_name()+" searches around.\n");
   return 1;
}
drink(arg){
 if(!arg)return;
 if (arg=="water" || arg=="from spring" || arg=="some water") {
      write("You drink some fresh water.\n");
      say(this_player()->query_name()+" drinks some water from the spring.\n");
      this_player()->drink_soft(1);
   }
   return 1;
}    
