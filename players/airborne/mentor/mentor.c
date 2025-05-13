inherit "room/room";

reset(arg){

 if(arg) return;

  transfer(clone_object("/boards/mentor_note"), this_object());
  set_light(1);
  short_desc = "New area approval room";
  long_desc = 
 "This room is for the new areas awaiting to be approved.  Mentor's are "
 "to post here when their student's areas are ready to be examined. Use "
 "the 'mentors' command to view the current list of Mentors and their "
 "students.\nTo the north is the mentor wanted board.\n";

  dest_dir = ({ "players/airborne/mentor/wanted", "north" });

}

init(){
::init();

add_action("mentors", "mentors");
}

mentors(){
this_player()->more_string(read_file("/players/airborne/mentor/secured/Mentor.List"));
  return 1;
}

