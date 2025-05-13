#define PPATH "/players/whisky/mill_quest/"
#define TP this_player()

inherit "room/room";
int check;

reset(arg){
check=0;
 if(arg) return;
   set_light(1);
   short_desc = "On a path";
   long_desc = "You're wandering along a slow flowing river.\n" 
                "There are some stones lying on the ground.\n" 
                "There is a big bush beside the river.\n";
   items = ({ "stones","Some heavy grey stones",
              "ground","You see some heavy stones lying in the grass",
              "grass","The grass is dew-drenched",
              "sky","You see the blue sky",
              "bush","It's a really big bush, maybe it's covering something",
              "boulder","@@query_boulder@@",
              "water-supply","It's the water-supply for the mill-wheel.\n" +
                              "@@query_supply@@",
              "supply","It's the water-supply for the mill-wheel.\n" +
                       "@@query_supply@@",
              "river","You see a big blue river which seems too deep to enter",
              "water","You see yourself !!!!" });
   dest_dir = ({ PPATH + "path3","south",
                 "/room/wild1","north" });
}

init(){
 ::init( );
   add_action("search","search");
   add_action("push","push");
   add_action("push","move");
   add_action("enter","enter");
   add_action("smash","smash");
   add_action("smash","destroy");
   add_action("smash","break");
}


push(arg){
 if(!arg) return;
 write("You can't move that !\n");
 return 1;
 }

search(arg){
 if(!arg) return;
 if(arg=="bush"){
    write("You recognize that the bush is hiding the water supply for the mill.\n");
    say(this_player()->query_name()+" searches the bush.\n");
   return 1;
    }   
  write("You search and search, but find nothing.\n");
  say(this_player()->query_name()+" searches around.\n");
 return 1;
}
 

enter(arg){
 if(!arg) return;
 if (arg!="river" && arg!="water" && arg!="the river" && arg!="the water") {
      write("What do you want to enter ?\n");
      say(this_player()->query_name()+" is fooling around!\n");    
   }
 else {
      write("You don't dare to enter the deep river!\n");
      say(this_player()->query_name()+" looks like a person who is trying to commit suicide!\n");
   }
   return 1;
}    

smash(arg){
object honour;

 if(!arg) return;
 if(arg == "boulder with hammer" || arg == "boulder with the hammer" ||
 arg == "boulder with hobbithammer" || arg == "boulder with the hobbithammer"){
   if(!present("hobbithammer", this_player())){
     write("You don't have the proper hammer to destroy such a big boulder.\n");
     return 1;
         }
   if(present("hobbithammer", this_player())){
      if(check > 0){
         write("But the boulder is already destroyed !!!\n");
         return 1;
         }
      else {
            write("The boulder crumbles to small fragments and the water streams into the supply.\n");
            say(this_player()->query_name()+" smashes the boulder.\n");
	    move_object(honour=clone_object("obj/treasure"),TP);
            honour->set_id("millhonour");
   	  }
        check=1;
        return 1;
         }
        write( "You don't have a hammer!\n" );
        return 1;
   }
   else if(arg == "boulder" || arg == "the boulder"){
      write( "With what do you want to smash the boulder?\n" );
      return 1;
   } 
   write( "You can't smash that!\n" );
   return 1;
}

query_boulder(str){
   if(check) return str="You can't see a boulder here";
   else return (str = "The big boulder hinders the water to flow" );
}

query_supply(str){
   if(check) return( str = "Water is streaming through it" );
   else return( str = "A big boulder hinders the water to flow" );
}

check_boulder(){
   return(check);           /* if check = 0 : boulder is here, esle 1  */
}
