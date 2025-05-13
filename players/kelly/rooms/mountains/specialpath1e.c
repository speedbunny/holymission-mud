#define PR "players/kelly/rooms/mountains/specialpath1w"

reset(arg) {
  if (!arg) {
    set_light(1);
  }
} /* reset */

init() {
  add_action("ne","northeast");
  add_action("se","southeast");
  if(living(this_player())) {
    tell_room(PR,
     this_player()->query_name()+" arrives on the other side of the gap.\n");
  }
} /* init */

short() {
    return "A path";
}

long(str) {
   if(!str) {
     write("You are standing on a large plateau with a gap in the middle.\n" +
           "Here at this point the gap isn't very large, though you would\n" +
           "not be able to jump over it.\n"+
           "   There are two obvious exits: northeast and southeast.\n");
     return;
   }
   if(str=="gap") {
     write("The gap is too wide to jump over it.\n");
     return;
   }
   if(str=="other side") {
     PR->long();
   }

} /* long */
 
id(str) { return !str || str=="gap" || str=="other side"; }

se() {
  this_player()->move_player("southeast#players/kelly/rooms/mountains/path7");
  return 1;
}

ne() {
  this_player()->move_player("northeast#players/kelly/rooms/mountains/specialpath2e");
  return 1;
}

