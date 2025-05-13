inherit "/room/room";
#define TP this_player()
#define PATH "/players/goldsun/green_island/room/"
int is_fire, is_passage;

void duse(){ is_fire=0; }
 

reset(arg){

 is_fire=1;
 is_passage=0;

if (arg) return;
 set_light(1);
 short_desc=("In a cottage");
 long_desc=
   ("You are in a wood-cutter cottage. It is made of wood. There is\n"+
     "wooden table with wooden chairs around. A very nice fireplace is\n"+
    "in the corner.\n");

 smell="You smell teak wood.";
 
 dest_dir=({ PATH + "meadow5",   "out" });
 
 items=({"table","A table made of wood",
	 "fireplace","@@query_fire_place@@",
	 "wood","It is very rare teak"
	 
         });
 ::reset(arg);

}

 init(){
  ::init();
  add_action("ext","extinguish");
  add_action("search","search");
  add_action("push","push");
  add_action("push","turn");
  add_action("enter","enter");
  }

int enter(string str){
 if (is_passage && (str=="fireplace" || str=="passage")){
   TP->move_player("into the passage#/players/goldsun/green_island/room/w_cell");
   return 1;
  }
 
 notify_fail("Are you sure you can enter it now ?\n");
 return 0;
}

int push(string str){
 if (str=="button") str="button in ash";
 if (!is_fire && str=="button in ash"){
  write("You push the button and small passage apears in the fireplace.\n");
  is_passage=1;
  return 1;
 }
 notify_fail("Push what where?\n");
 return 0;
}

int ext(string str){
  if (str=="fire"){
    write("You start to blow to the fireplace, but the fire is too strong.\n");
     say(TP->query_name()+" starts to blow to the fireplace.\n");
    write("Maybe you could use other way.\n");
    return 1;
  }
  notify_fail("Extinguish what?\n");
  return 0;
}
 
string query_fire_place(){
  if (is_fire){ 
    return "There is a nice fire in it";
  }
  return "A heap of ash is here";
 
}


int search(string str){
  notify_fail("search what?\n");
  if (!is_fire && (str=="ash" || str=="ash in fireplace")){
    write("You feel a small button.\n");
    return 1;
  }
  return 0;
}  
   
