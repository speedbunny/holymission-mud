inherit"room/room";

reset(arg) {

  set_light(0);
  dest_dir=({ 
        "players/airborne/temple/levelb/room5","north",
	"players/airborne/temple/levela/stairs3", "up" });
  short_desc="Stairwell.\n";
  long_desc=
	
"The stairs continue up and down as well as the exit on this level."
"It appears to be getting darker and darker.\n"
"It sorta looks like there may be stairs leading down too.\n";
}

init() {

 add_action("down","down");
::init();
}

down() {
if ((present("crown",this_player())) && (present("quest_scepter",this_player()))) {
this_player()->move_player("goes down#/players/airborne/temple/levelc/stairs5");
return 1;
}
  else {
    write("You don't have the right items to go down.\n");
    return 1;
            }
}
