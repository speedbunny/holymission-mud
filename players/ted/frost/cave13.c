/* 230793 Galadriel: load of typos fixed */
inherit "room/room";
int trap;

reset(arg) {
  trap = 0;
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave turns north here. The floor and walls have been cut and\n"+
"shaped by tools. It is quite different than the natural cave\n"+
"you had been traveling through.\n";
    dest_dir = ({
"players/ted/frost/cave14", "north",
"players/ted/frost/cave12", "west"
    });
  }
}

long(str) {
  ::long(str);
  if(str == "pit" && trap) {
    write("This is a large pit in the center of the room.\n");
    write("A small ledge runs around the edge of it. It\n");
    write("is very deep and to dark to see into.\n");
  }
  if(str == "floor") {
    if(trap) {
      write("You can easily see the pit trap.\n");
    } else if(random(6) >= 3 && !trap) {
      trap = 1;
      write("You find a pit trap!!!\n");
      say(capitalize(this_player()->query_name())+" finds a pit trap!\n");
    } else {
      write("All you see is dust.\n");
      say(call_other(this_player(),"query_name")+" searches the floor.\n");
    }
  }
  if(!str && trap)
    write("There is a large pit in the center of the room.\n");
}

id(str) {
  if(::id(str)) return 1;
 return (str == "pit" || str == "floor" || str == "trap");
}

init() {
  ::init();
  add_action("find"); add_verb("search");
  add_action("north"); add_verb("north");
  add_action("down"); add_verb("down");
  add_action("jump"); add_verb("jump");
}

find(str) {
 if(trap) {
  write("You can easily see the pit trap.\n");
  return 1;
 }
  say(call_other(this_player(),"query_name")+" searches the floor.\n");
  if(random(6) >= 3) {
   write("You find a pit trap!\n");
   say(call_other(this_player(),"query_name")+" finds a pit trap!\n");
   trap = 1;
   return 1;
  }
  write("You see nothing but dust.\n");
  return 1;
}

north() {
  if(!trap) {
    write("As you leave north, you step upon a counterbalanced floor stone.\n");
    say("As "+call_other(this_player(),"query_name")+" leaves north");
    say(" he sets off a trap!!!\n");
    trap = 1;
    do_move();
    return 1;
  }
}

down() {
  write("You'd have to be crazy to jump in a hole like that!\n");
  write("But if you really want to do it, type 'jump'\n");
  return 1;
}

jump() {
  write("Boy! You really are crazy!\n");
  say(capitalize(this_player()->query_name())+" jumps into the pit!!!\n");
  move_object(this_player(),"players/ted/frost/pit");
  write("You jump\n");
  write("          D\n");
  write("           O\n");
  write("            W\n");
  write("             N\n");
  write("                into the pit!\n\n\n");
  say(capitalize(this_player()->query_name())+" lands with a SPLAT!!!\n");
  this_player()->hit_player(100);
  return 1;
}
  
do_move() {
 object next, temp;
 next = first_inventory(this_object());
 while(next) {
  temp = next_inventory(next);
  if(living(next)) {
   if(!next->query_npc())
    tell_object(next,"Suddenly the floor opens up and you fall into a deep pit!!!!!\n");
  tell_room("players/ted/frost/pit",capitalize(next->query_name())+" hits the bottom with a thud!\n");
  call_other(next,"move_player","suddenly#players/ted/frost/pit");
  next->hit_player(40);
  tell_object(next,"You hit the bottom with a thud!\n");
  }
 next = temp;
 }
 return 1;
}
