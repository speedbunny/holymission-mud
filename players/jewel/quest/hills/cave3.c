inherit "room/room";

reset(arg) {
  int i;
  if (!present("dracolich")) {
    for (i=0;i<1;i++)
move_object(clone_object("/players/jewel/quest/hills/dracolich"),this_object());
  }
  if (arg) return;
  set_light(0);
  short_desc="In the parlour of the demonlord";
  long_desc=
 ("This is the parlour of the demonlord. His guards charge.\n");
  items=({
    "parlour","The parlour of the demonlord"
        });
  dest_dir=({
    "/players/jewel/quest/hills/cave2","north",
    "/players/jewel/quest/hills/cave4","east"
           });
}

init() {
  ::init();
  if(present("dracolich")) {
      add_action("east","east",1);
      }
    }

east() {
  if(!present("dracolich")) {
     this_player()->move_player("east#players/jewel/quest/hills/cave4");
  } else { 
    write("The dracolich blocks your way.\n");
  }
  return 1;
}
      
