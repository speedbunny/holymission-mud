/* 12.08.93 Airborne: change register.c over to room/room */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "Registration room";
  long_desc = "You come here when you want to register yourself as a party leader.\n"
       + "To do so, type 'register'. But are you a person who has enough\n"
       + "leadership qualities ?\n";
  dest_dir = ({ "room/pub2","down" });
}

init(){
::init();
    add_action("register","register");
}
register() {
  if (present("party object",this_player())) {
     write("You already belong to another party.\n");
     return 1;
  }
  move_object(clone_object("obj/party"),this_player());
  write("Your party has been registerd.\n");
  return 1;
}
