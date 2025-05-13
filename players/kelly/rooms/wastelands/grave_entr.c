inherit "room/room";
 
object obj;
status locked,open;
 
reset(arg) {
    if (arg) return;
    set_light(0);
    open=0;
    locked=1;
    no_castle_flag=1;
    short_desc="Grave entrance";
    long_desc="You're in front of two gates which seem to be the"+
      " entrance to the tomb. There is a huge padlock attached to the gate.\n";
    dest_dir=({
    "players/kelly/rooms/wastelands/dolmen1","up",
   });
   items=({
     "padlock","This is a huge padlock, if you find the right key, you could open it"
   });
}

init() {
::init();
  add_action("unlock","unlock");
  add_action("lock","lock");
  add_action("open","open");
  add_action("north","north");
}

unlock(str) {
  string what,with;
  
  sscanf(str,"%s with %s",what,with);
  if (!(what=="padlock" && with=="key")) return;
  if(!present("key",this_player())) {
    write("You should have one!\n");
    return 1; 
  }
  if(locked) {
    if(present("gate key",this_player())) {
      write("You try to unlock the padlock and you manage it!\n");
      say(this_player()->query_name()+" unlocks the padlock.\n");
      locked=0;
    }
    else 
    {
       write("The key doesn't fit!\n");
       say(this_player()->query_name()+" tries to open the padlock, but fails.\n");
    } }
   else 
   {
    write("The padlock is already open.\n");
     say(this_player()->query_name()+" tries foolishly to open an unlocked padlock.\n");
   }
   return 1; 
}

open(str) {
  if(str!="gate" && str!="gates") return;
  if(locked) {
    write("The padlock is locked.\n");
    say(this_player()->query_name()+" tries to open the gates, but fails.\n");
  } else {
    write("Under great effort you open the gates.\n");
    say(this_player()->query_name()+" opens the gates.\n");
    open=1;
  }
}

lock(str) {
  if(str!="padlock") return;
  if(locked) write("It's already locked!\n");
  else write("You lock the padlock!\n");
  locked=1;
  return 1;
}

north() {
  if(open) {
    write("You step into a great hall.\n");
    this_player()->move_player("north#players/kelly/rooms/tomb");
  } else {
    write("You run directly into the gate.\n");
    say(this_player()->query_name()+" runs into the gate.\n");
  }
  return 1;
}
    

