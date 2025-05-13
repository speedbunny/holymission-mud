inherit "/room/room";
#define TO this_object()

void give_orb(){
 if (!present("bright orb",TO)){
   move_object(clone_object("/players/goldsun/nottingham/obj/orb"),TO);
   tell_room(TO,"A strong shine appears in the middle of the room.\n");
   call_out("dest_orb",20);
 }
}

void dest_orb(){
 if (present("bright orb",TO)){
   destruct(present("bright orb",TO));
   tell_room(TO,"A strong shine disappears.\n");
 }
}

reset(arg){
 if (!arg){
  set_light(0);
  short_desc=("Empty room");
  long_desc="You are in the total empty room.\n";
  smell="You smell dust.";
  property=({"no_teleport"});
  no_obvious_msg="";
 }
 ::reset(arg);
}

init(){
 call_out("give_orb",10);
 ::init();
}

