inherit "/room/room";
void i;
reset(arg){
  i=1;
 if (!arg){
 clone_list=({1,1,"kliment","/players/goldsun/nottingham/monster/kliment",
	    0});
 set_light(1);
 short_desc=("Abbot room");
 long_desc="This is the room of abbot Kliment. You can see a bed\n"+
	   "by the wall and bookcase on the other side of the room.\n"+
	   "Light comes in through a small window.\n";
 
 smell="You smell torch smoke.";

 dest_dir=({"/players/goldsun/nottingham/room/castle/hall3","west"});

 items=({ "bed","It is made of wood",
   	  "bookcase","There are many books in it",
	  "books","They are not very dusty, maybe they hide something"
	  
        });

 }
 ::reset(arg);
}

init(){
 ::init();
add_action("search","search");
}

int search(string str){
object chest;

 if (str=="books" || str=="bookcase"){
  if (i){
     write("You search the "+str+" and find a chest.\n");
     say(this_player()->query_name()+" searches the "+str+".\n");
     i=0;
     chest=clone_object("/players/goldsun/nottingham/obj/chest1");
     if ( transfer(chest,this_player()) ){
           write("You can't carry that much.\n");
           transfer(chest,environment(this_player()));
     }
   }else write("Someone was faster than you.\n");
  return 1;
 }
 notify_fail("Search what ?\n");
 return 0;
}
