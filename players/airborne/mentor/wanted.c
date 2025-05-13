inherit "room/room";


reset(arg){

  if ( arg ) return;

  transfer(clone_object("/boards/mentor_wanted"),this_object());

  set_light(1);
  short_desc = "Mentor wanted room";
  long_desc = 
"This room is designed so that Apprentices looking for a mentor can have "
"some help in locating one. Apprentices are encouraged to leave a note "
"listing some of thier experience with code and MUDs and Mentors are "
"encouraged to leave notes when they feel they might want an apprentice.\n"
"The adventurer's guild is to the northwest and the wizards mentor board "
"is to the south.\n";

  dest_dir = ({ "room/adv_guild", "northwest" });

}

init(){
 ::init();
   add_action("south", "south");
   if(!this_player()->short()) this_player()->vis();
}

south(){
  if(!this_player()->query_immortal()){ return; }
    this_player()->move_player("south#players/airborne/mentor/mentor");
    return 1;
}
