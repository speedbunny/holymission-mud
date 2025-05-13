#define PR "players/kelly/rooms/mountains/specialpath3e"

reset(arg) {
  if (!arg) {
    set_light(1);
  }
} /* reset */

init() {
  add_action("n","north");
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
           "   There are two obvious exits: north and southeast.\n");
     return;
   }
   if(str=="gap") {
     write("It is too wide to jump over it.\n");
     return;
   } 
   if(str=="other side") {
     PR->long();
   }
} /* long */

id(str) { return !str || str=="gap" || str=="other side"; }

se() {
  this_player()->move_player("southeast#players/kelly/rooms/mountains/specialpath2w");
  return 1;
}

n() {
  this_player()->move_player("north#players/kelly/rooms/mountains/rocks10");
  return 1;
}

