inherit "room/room";

init() {
  ::init();
  add_action("do_read"); add_verb("read");
}


reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "A Small Room";
    long_desc =
"This small room is starkly furnished with a bed and\n"+
"a small desk. A note is tacked to the wall over the\n"+
"desk. A large window look east. You think you see something\n"+
"out of it.........\n";
    dest_dir = ({
"players/ted/fire/tower2", "west"
    });
    items = ({
"window","As you look out the window, you see a small courtyard\n"+
         "surrounded by high walls. As you look a Fire Giant walks\n"+
         "from a small door in the east wall to the double doors and enters",
"window","As you look out the window, you see a small courtyard\n"+
         "surrounded by high walls. As you look a Fire Giant walks\n"+
         "from a small door in the east wall to the double doors and enters",
"desk","This is a small wooden desk. It has nothing on it, only a pen\n"+
       "and a stack of paper, none of which interests you",
"note","It seems to be writen in your language. Maybe you should read it?"
    });
  }
}

do_read(str) {
 if(str == "note"){
  write("To Captain Vacard:\n");
  write("Please remember to interogate our frost giant prisoner soon.\n");
  write("He may have important information about the giant conference\n");
  write("on human bashing. He WAS the frost giant kings messenger......\n");
  write("I have heard rumours that the frost giants have found a very\n");
  write("valuable treasure. He may know something about it......\n");
  write("                      King Thelborn\n");
 return 1;
 }
}
