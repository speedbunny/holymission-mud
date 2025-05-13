 inherit "/room/room";
#define TP this_player()
#define PATH "/players/goldsun/green_island/"
int is_move, is_open;

reset(arg){
  is_move=0;
  is_open=0;

if (arg) return;
 set_light(1);
 short_desc=("In a stilt house");
 long_desc=
       "You are inside a small stilt house. The interior is also made of\n"+
       "wood. You can see a table with a chair and a bed. This house looks\n"+
       "like sailors house.\n";

 smell="You smell salt fresh water.";
 
 dest_dir=({ PATH + "hm_coast",   "out" });
 
 items=({"table","@@query_table@@",
	 "wood","It is very rare teak",
	 "trapdoor","@@query_trapdoor@@",
	 "bed","An old bed",
         "chair","Wooden chair with nihonese signs on it"
         });

 ::reset(arg);

}


string query_table(){
  if (!is_move) return "A table made of wood. It stands in the middle of house";
  return "A table made of wood. It stands near the wall";
}

string query_trapdoor(){
 if (is_move){
   if (is_open) return "Trapdoor is opened. You can see a strange magic field in it";
   return "Tranpdoor is closed";
 }
 return "You see nothing of interest";
}

 init(){
  ::init();
  add_action("enter","enter");
  add_action("do_move","move");
  add_action("open","open");
  }

   
int enter(string str){
  notify_fail("Enter what?\n");
  if (!is_move) return 0;
  if (str=="trapdoor"){
     if (!is_open){
        write("Trapdoor is closed.\n");
        return 1;
     }
     write("As you enter the trapdoor you feel that magic force transfers you.\n");
     TP->move_player("down","players/goldsun/green_island/room/coast1");
     return 1;
   }
}

int do_move(string str){
  notify_fail("Move what?\n");
  if (str=="chair"){
    write("You take a chair and move it around you.\n");
    say(TP->query_name()+" moves a chair.\n");
    return 1;
  }
  if (str=="bed"){
   write("Uf. It is too heavy to move it.\n");
   say(TP->query_name()+" tries to move a bed.\n");
   return 1;
  }
  if (str=="table"){
    if (is_move){
      write("You push the table to the middle of the house.\n");
      say(TP->query_name()+" moves a table.\n");
      is_move=0;
      return 1;
    }
    write("You push the table to the wall.\n");
    write("You find a trapdoor in the floor.\n");
    say(TP->query_name()+" moves a table.\n");
    is_move=1;
    return 1;
   }
}

int open(string str){
  notify_fail("Open what?\n");
  if (!is_move) return 0;
  if (str=="trapdoor"){
    if (is_open){
      write("Trapdoor is already opened.\n");
      return 1;
    }
    write("You open trapdoor.\n");
    write("You can see a strange magic field in it.\n");
    say(TP->query_name()+" opens a trapdoor.\n");
    is_open=1;
    return 1;
   }
}

