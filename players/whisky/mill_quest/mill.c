#define PPATH "/players/whisky/mill_quest/"

inherit "room/room";
  
int counter,fcounter;

reset(arg){
  counter=0;
  fcounter=0;
   
 if(arg) return;
  set_light(1);
  short_desc = "Inside the watermill";
  long_desc = "You're inside the watermill. The walls are made of oak and\n" 
           "beautiful pictures covers the walls. To your right you notice\n" 
           "a giant millstone and right before you stands a large,\n" 
           "open chest.\n";
  items = ({ "millstone","A really heavy millstone",
              "stone","A really heavy millstone",
              "floor","You see a floor made of stone",
              "walls","They are made of oak",
              "wall","They are made of oak",
              "pictures","You see the daughter of Hobbe smiling sexily at you",
              "chest","You see a big open chest with a lot of flour in it" });
  dest_dir = ({ PPATH + "path2","out", });
}

init(){
 ::init();
   add_action("search","search");
   add_action("search","take");
   add_action("search","get");
   add_action("close","close");
   add_action("open","open");
   add_action("push","push");
   add_action("push","move");
}

search(arg){
  object ob;
   
 if(!arg) return;
  if(arg!="flour" && arg!="chest") { return; }
  else if(arg=="flour") { arg=="chest"; }
  if (arg=="chest") {
    if(fcounter >= 10) {
 	write( "You find some flour.\n" +
               "But as you try to get it, it slips through your fingers.\n" );
         return 1;
      }
    else if (fcounter != 5) {
         write("You find some flour.\n");
         say(this_player()->query_name()+" searches the chest.\n");
         ob=clone_object(PPATH + "flour");
         if (transfer(ob,this_player())) {
            write("But you can't carry that much.\n");
            destruct(ob);
            return 1;
         }
    fcounter++;
    return 1;
      }
      else {
         arg = "flour";
         fcounter++;
      }
   }
   
  if(arg=="flour"){
    if(counter<1){
         write("You find a hammer.\n");
         say(this_player()->query_name()+" searches the chest.\n");
         ob=clone_object(PPATH + "hammer");
         if (transfer(ob,this_player())) {
            write("But you can't carry that much.\n");
            destruct(ob);
            return 1;
         }
            
    counter = 1;
    return 1;
      }
   }      
   write("You search and search, but find nothing.\n");
   say(this_player()->query_name()+" searches around.\n");
   return 1;
}
close(arg){
 if(!arg) return;
      
  if(arg!="chest") return 0;
  
   write("You try to close the heavy chest, but the links are much too rusty.\n");
   say(this_player()->query_name()+" shows "+this_player()->query_possessive()+
       " weakness.\n");
   return 1;
}
open(arg){
 if(!arg) return;
  if(arg!="chest") return 0;
   write("The chest is already open !\n");
   say(this_player()->query_name()+" shows how braindamaged "+
   this_player()->query_pronoun()+" is !\n");
    return 1;
}

      
push(arg) {
 if(!arg) return;
   if(arg == "millstone" || arg == "stone") {
      write( "The stone is much too heavy to move !\n" );
      say( this_player()->query_name() + " tries to move the millstone, but fails.\n" );
      return 1;
   }
   write("You can't move that !\n"); 
      return 1;
}
