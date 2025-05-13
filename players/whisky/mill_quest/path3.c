#define PPATH "/players/whisky/mill_quest/"

inherit "room/room";

reset(arg) {
 if(arg) return;
   set_light(1);
   short_desc = "On a path";
   long_desc = "You're wandering along a fast flowing river.\n" 
                "There are some stones lying on the ground.\n" 
                "In the distance you can see a big building.\n";
   items = ({ "stones","Some heavy grey stones",
              "ground","You see some heavy stones lying in the grass",
              "grass","The grass is dew-drenched",
              "sky","You see the blue sky",
              "mill","You see a large watermill",
              "river","You see a big blue river which seems too deep to enter",
              "water","You see yourself !!!!" });
   dest_dir = ({ PPATH + "path4","north",
                 PPATH + "path1","southeast" });
}


init(){
 ::init();
   add_action("search","search");
   add_action("push","push");
   add_action("push","move");
   add_action("enter","enter");
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
enter(arg){
 if(!arg) return;
 if(arg!="river" && arg!="water" && arg!="the river" && arg!="the water") {
      write("What do you want to enter ?\n");
      say(this_player()->query_name()+" is fooling around!\n");    
   }
 else {
      write("You don't dare to enter the deep river!\n");
      say(this_player()->query_name()+" looks like a person who tries to make suicide !\n");
   } 
   return 1;
}    
