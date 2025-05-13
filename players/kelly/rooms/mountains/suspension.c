#define PR "players/kelly/rooms/mountains/undersusp"

status rope;

reset(arg) {
  if (!arg) {
    set_light(1);
  }
} /* reset */

init() {
  add_action("south","south");
  add_action("north","north");
  add_action("down","down");
  add_action("dropping","drop");
} /* init */

short() {
    return "On a bridge";
}

long(str) {
   object all;
   int i,count;

   if(!str) {
     write("You are standing on an suspension bridge over a valley.\n" +
           "Far down in the valley you can see a path running east to west.\n" +
           "The bridge doesn't look very new, but it will carry you.\n"+
           "    There are two obvious exits: south and north\n");
     return;
   }
   if(str=="valley") {
     write("It runs from east to west.\n");
     return;
   }
   if(str=="path") {
     write("It's is a long way down, so don't try to jump.\n"+ 
           "You cannot make out anything special on the street.\n");
  
     all=all_inventory(PR->query_me());
     count=0;
     for(i=0;i<sizeof(all);i++) 
       if(living(all[i])) count=1;
     if(count==1) 
       write("Except one creature.\n");
     else if(count>1)
       write("Except some creatures.\n");
   }
} /* long */

id(str) { return !str || str=="path" || str=="valley" || str=="bridge"; }

south() {
  this_player()->move_player("south#players/kelly/rooms/mountains/rocks10");
  return 1;
}

north() {
  this_player()->move_player("north#players/kelly/rooms/mountains/rocks11");
  return 1;
}

down() {
  if(!rope) {
    write("You wouldn't survive the touchdown and there's no way of climbing down.\n");
    return 1;
  }
  else {
    write("You climb down the rope.\n"); 
    this_player()->move_player("down the rope#players/kelly/rooms/mountains/undersusp");
    return 1;
  }
}

dropping(item) {
  object ob;

  this_player()->drop_thing(item); 
  ob=first_inventory(this_object());
  if(!living(ob)) {
    write("Unfortunately "+item+" falls down as you drop it.\n");
    say("As "+this_player()->query_name()+" drops "+item+" it falls down.\n");
    move_object(ob,PR);
    tell_room(PR,"Something fell down from above.\n"); 
    return 1;
  }
}

tie(str) {
  if(str!="bridge") return 0;
  rope=1;
  return 1;
}

untie() {
  rope=0;
  return 1;
}

query_rope() { return rope; }

query_me() { return this_object(); }
