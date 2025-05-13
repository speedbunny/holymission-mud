//This file to replace "/players/mangla/guild/rooms/portal"
//Thanks - Redsexy
inherit "room/room";

void reset(int arg) {     
    if(!arg) {

        set_light(1);
        short_desc = "A long corridor in the lower sanctum of the Jedi Guild";     
        long_desc = "\
You have reached the end of the corridor, and stand before a swirling mass \
of light and confusion.  As pretty as it seems, it doesn't seem to have any \
purpose except to provide illumination for the lower sanctums.... \n";

        dest_dir = ({
            "/players/mangla/guild/rooms/corridor2",  "east",
        });

         items = ({
             "corridor", "You are at the end of the corridor",            
             "mass", "It seems to be some kind of a portal",
             "light", "You look into the light and notice that it is a portal",
             "confusion", "The confusion clears in your jedi mind and you notice a portal",
        });    
   
    }
    ::reset(arg);
}

init() {
  ::init();
  add_action("_enter", "enter");
} 

_enter(arg) {
  if(arg == "portal" || arg == "opening") {
    write("You enter the portal.\n");
    this_player()->move_player("through the portal.#players/redsexy/jedi/areas/cantina/3");
    return 1;
  }
  write("Enter what?\n");
  return 1;
}
