inherit "room/room";

#include "/players/tatsuo/area/tatsuo_defs.h"


reset(arg){
 
clone_list=({1,4,"guard",MPATH+"wolfen_guard",0});                         
                         

   if(!arg) {
        set_light(1);
        short_desc="A small room";
        long_desc=
"This is a large room, where the silver ingots made in this camp are stored\n"+
"before they are shipped off to civilization.  Stacks and stacks of silver\n" +
"surround you.  You stand back in awe at the amount of wealth stored within\n"+
"this room.  The room is unnaturally quiet.  You think there may be a \n"+
"protection spell on this room, so you want to leave as fast as you can.\n";
   dest_dir=({
            CAMPPATH+"silver_storehouse1.c", "west",
                 });
   items=({ 
     "wolfen","A large burly wolfen guard who eyes you warily",
     "table","A small table in the corner with a book resting on it",
     "book","A fat log of everything that has entered and left the east room",
   });
        smell = "You dont smell anything special";
     }  
}

int get(string str_arg){

  if(str_arg=="silver"||str_arg=="silver ingot"){
    move_object((clone_object("/players/tatsuo/area/obj/silver_ingot")),TP);
    return 1;
  }
  else return 0;
}

init(){
  ::init();
  add_action("get","get");
}




