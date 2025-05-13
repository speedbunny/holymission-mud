inherit "/room/room";
object ring;
reset(arg){

 ::reset(arg);
 set_light(-2);
 short_desc=("In the tree");
 long_desc=("You are in the oak tree.\n"
	    +"The tree trunk looks mystical.\n");
 smell="You smell wooden smell.";
 no_castle_flag=1;
 dest_dir=({"/players/goldsun/sherwood/room/tree1","out"});
 items=({"tree","This tree is mystical oak with a crack",
    	 "crack","This is the crack that you entered tree through",
	 "trunk","The mystical oak trunk with a hole",
	 "oak trunk","The mystical oak trunk with a hole",
	 "mystical trunk","The mystical oak trunk with a hole",
	 "mystical oak trunk","The mystical oak trunk with a hole",
	 "oak tree","This tree is mystical oak",
	 "small crack","This crack is small",
	 "hole","A small hole in the tree trunk. Maybe it hinders something"
             });
 }

init(){
 ::init();
 add_action("search","search");
 }

search(str){

 if (str=="hole" || str=="crack" || str=="small crack"){
 if (set_light(0)<3){
    write("It's too dark.\n");
    return 1;}

   write("You search the hole.\n");
   if (ring) {return 1;}
    else {
     write("You find a ring.\n");
     say(this_player()->query_name()+" searches a hole.\n");
     ring=clone_object("/players/goldsun/sherwood/obj/Gring");
     transfer(ring,this_player());
     return 1;
    }
  }
}
