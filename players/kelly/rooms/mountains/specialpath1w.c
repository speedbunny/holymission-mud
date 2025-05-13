#define PR "players/kelly/rooms/mountains/specialpath1e"

reset(arg) {
  if (!arg) {
    set_light(1);
  }
} /* reset */

init() {
  add_action("south","south");
  add_action("ne","northeast");
  if(living(this_player())) {
    tell_room(PR,
     this_player()->query_name()+" arrives on the other side of the gap.\n");
  }
} /* init */

short() {
    return "A path";
}

long(str) {
   object all;
   int i;

   if(!str) {
     write("You are standing on a large plateau with a gap in the middle.\n" +
           "Here at this point the gap isn't very large, though you would\n" +
           "not be able to jump over it.\n"+
           "    There are two obvious exits: south and northeast\n");
     return;
   }
   if(str=="gap") {
     write("It's too wide to jump over it.\n");
     return;
   }
   if(str=="other side") {
     all=all_inventory();
     write("On the other side you can see:\n");
     for(i=0;i<sizeof(all);i++) 
       if(all[i]->short()) write(all[i]->short()+".\n"); 
     if(!all[0]) write("Nothing.\n");
     return 1; 
   }
} /* long */

id(str) { return !str || str=="gap" || str=="other side"; }

south() {
  this_player()->move_player("south#players/kelly/rooms/mountains/rocks7");
  return 1;
}

ne() {
  this_player()->move_player("northeast#players/kelly/rooms/mountains/specialpath2w");
  return 1;
}

