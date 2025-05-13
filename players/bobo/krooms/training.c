inherit "room/room";
 
reset(arg) {
  if (arg) return;
  set_light(5);
  short_desc="Trainingsroom";
  long_desc="You're in Kelly's trainings room.\n"+
      "There's a button at the wall and a sign beside it.\n";
  dest_dir=({
    "players/kelly/workroom","down",
   });
  items=({
    "button","Press this button to clean room",
    "sign","Only NPCs and objects will be destructed", 
  });
}

init() {
::init();
  add_action("press","press");
  add_action("moving","north");
  add_action("moving","south");
  add_action("moving","west");
  add_action("moving","east");
}

press(str) {
  int i;
  object dests;
  if(str!="button") return;
  dests=all_inventory(this_object());
  i=sizeof(dests)-1; 
  while(i>=0) {
    if(!living(dests[i]) || dests[i]->query_npc()) { 
       write("Destructed : "+dests[i]->short()+"\n"); 
       destruct(dests[i]);
     } 
    i--;
  }
  return 1;
}
 

moving() {
  if(this_player()->query_npc()) {
    say(this_player()->short()+" is moved to store.\n");
    move_object(this_player(),"players/kelly/store");
  }
  write("You cannot, it's just a dummy exit.\n");
  return 1;
}

