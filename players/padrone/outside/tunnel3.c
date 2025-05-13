/* Tunnel 3 */
/* File checked - Exos 961028 */

inherit "players/cashimor/inherit/water";

reset(arg) {
  if(!arg) {
    short_desc="Water-filled tunnel";
    long_desc="You are in a dark water-filled tunnel.\n";
    dest_dir=({"players/padrone/outside/tunnel2","west",
               "players/padrone/outside/tunnel4","east"});
    damage=2;
  }
  ::reset(arg);
}

init() {
  ::init();
  add_action("west_it","west");
}

west_it() {
  write("The tunnel is too narrow to turn in!\n");
  say(this_player()->query_name()+" wanted to go back, but failed.\n");
  return 1;
}
