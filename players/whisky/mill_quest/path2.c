#define PPATH "/players/whisky/mill_quest/"

inherit "room/room";
object hobbit;
   


reset(arg){
 if(!hobbit){
     hobbit=clone_object(PPATH+"hobbe");
     move_object(hobbit,this_object());
     }
 if(arg) return;
   set_light(1);
   short_desc = "In front of the mill";
   long_desc = "You are standing in front of a huge water mill.\n" 
                "To your right you can see the mill wheel and to\n" 
                "your left you see a river. You also can see the \n" 
                "water supply for the mill wheel.\n";
   items = ({ "stones","Some heavy grey stones",
              "ground","You see some heavy stones lying in the grass",
              "grass","The grass is dew-drenched",
              "sky","You see the blue sky",
               "mill","You see a large watermill, inviting you to enter",
              "mill wheel","You see a big mill wheel, @@query_work@@",
              "wheel","You see a big mill wheel, @@query_work@@",
               "water mill","You see a large water mill, inviting you to enter",
              "water supply","It keeps the wheel turning @@query_supply@@",
              "supply","It keeps the wheel turning @@query_supply@@",
              "river","You see a big blue river which seems too deep to enter",
              "path","The path runs back to the northwest",
              "water","You see yourself !!!!" });
   dest_dir = ({ PPATH + "path1", "northwest" });
}
init(){      

run_mill(); 
   
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
 if (arg=="river" || arg=="water" || arg=="the river" || arg=="the water") {
      write("You don't dare to enter the deep river!\n");
      say(this_player()->query_name()+" looks like a person who is trying to commit suicide!\n");
   }
 else if (arg=="mill" || arg=="the mill" || arg=="water-mill" || arg=="the water-mill" ) {
    write("You enter the water-mill.\n");
    this_player()->move_player("into the mill#players/whisky/mill_quest/mill");
   }
 else {
      write("What do you want to enter?\n");
      say(this_player()->query_name()+" is fooling around!\n");    
   } 
   return 1;
}    


query_work(str){
 if((PPATH+"path4")->check_boulder() == 1){ 
      return str="it works now";
   }
   return str="it seems to be out of order";
}

query_supply(str){
 if ((PPATH+"path4")->check_boulder() == 1){    
      return str="";
   }    
   return str=", but now it's dried out";
}

run_mill(){
object who;

 if(this_player()){
   who=find_living(this_player()->query_real_name());
    if (present(who) && (PPATH+"path4")->check_boulder() == 1) {        
          write("The mill wheel slowly turns around.\n");
          call_out("run_mill",4);
          return;
      }
   }
   return;
}
