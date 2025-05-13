inherit "/room/room";
#define PATH "/players/goldsun/green_island/room/"
#define TP this_player()

int is_open, is_lock;

reset(arg){
 is_lock=1;
 is_open=0;
if (!arg){
 clone_list=({1,1,"syracusos","/players/goldsun/green_island/monster/syracusos",0});
 set_light(1);
 short_desc=("Residence of evil cyclops");
 long_desc=
    "You are inside of residence of evil Syracusos. It looks very nice.\n"+
    "Marble floor is shiny. High walls are made of light gray marble too.\n"+
    "There are pictures about greatest moments of cyclops' kingdom on them.\n"+
    "Tall columns are decorated too. Over this whole beauty is a large stony\n"+
    "vault. You can notice a small door leading up from here.\n";

 smell="You smell rotten air.";

 items=({"castle",long_desc,
         "residence",long_desc,
         "door","A wooden door with orb sign on it",
         "walls","Walls of gray stone with history of cyclops' kingdom"
         });

 dest_dir=({ PATH + "residence40", "north",
             PATH + "residence37", "east",
	     PATH + "residence38", "south",
	     PATH + "residence41", "west",
             PATH + "residence32", "down"    });


 }

 ::reset(arg);
}

init(){
 ::init();
add_action("enter","enter");
add_action("open","open");
add_action("close","close");
add_action("unlock","unlock");
}


int open(string str){
 notify_fail("Open what?\n");
 if (str=="door"){
   if (is_open){
     write("The door is already opened.\n");
     return 1;
   }
   if (is_lock){
     write("The door is locked.\n");
     return 1;
   }
   write("You open the door.\n");
   say(TP->query_name()+" opens a door.\n");
   is_open=1;
   return 1;
 }
}   

int close(string str){
 notify_fail("Close what?\n");
 if (str=="door"){
   if (!is_open){
     write("The door is already closed.\n");
     return 1;
   }
   write("You close the door.\n");
   say(TP->query_name()+" closes a door.\n");
   is_open=0;
   return 1;
 } 
}  


int unlock(string str){
 notify_fail("Unlock what?\n");
 if (str=="door"){
  if (!is_lock){
    write("Door is already unlocked.\n");
    return 1;
  }
  if (present("goldsun_orb_rockland_door",TP)){
   write("You unlock door.\n");
   say(TP->query_name()+" unlocks door.\n");
   is_lock=0; 
   return 1;
  }
  write("You are not allowed to do that.\n");
  return 1;
 }
}


int enter(string str){
 notify_fail("Enter what?\n");
 if (str=="door"){
  if (!is_open){
    write("Door is closed.\n");
    return 1;
  }
  TP->move_player("up#players/goldsun/green_island/room/residence42");
  return 1;
 }
}

