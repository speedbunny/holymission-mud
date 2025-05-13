inherit "/room/room";

int trap;

int move(string str) {
  if(!str)
  str=query_verb();
  switch(str) {
    case "north" :
      if(!trap) {
        write("As you leave north, you step upon a counterbalanced floor "+
              "stone.\n");
        say("As "+this_player()->query_name()+" leaves north, "+
            this_player()->query_pronoun()+" sets off a trap!!!\n");
        trap = 1;
        call_out("do_move", 3);
        return 1;
      }
  }
  return ::move(str);
}

void reset(int arg) {
  trap = 0;
  if(arg) return;

  set_light(0);
  short_desc="Dark cave";
  long_desc="Tools have been at work in this section of the cavern.  The "+
            "floor and walls show evidence of cutting and squaring-off.  "+
            "The cavern has a strange feeling to it, and the air feels as "+
            "if it is coming from an empty space in the floor@@chk_pit@@\n";

  dest_dir=({"/players/emerald/perilous/frost/cave14","north",
             "/players/emerald/perilous/frost/cave12","west",
           });

  property=({"no_sneak"});

  items=({"floor","@@floor@@",
          "pit","@@pit@@",
          "ledge","@@ledge@@",
          "trap","@@trap@@",
          "section","Definitely not natural",
          "cavern","It has a strange feel, and should be thoroughly searched",
          "walls","Their sharp angles bear testimony to the presence of tools",
       });

  ::reset(arg);

}

string chk_pit() {
  if(trap==1) 
    return ".  There is a large pit in the centre of the room.  "+
           "A small ledge runs around it.";
    return ".";
}

pit() {
  if (trap==1) return "This is a large pit in the center of the room.\n"+
          "A small ledge runs around the edge of it.\n"+
          "It is very deep and to dark to see into";
  return "You see nothing of interest";
}

ledge() {
  if(trap==1) return "This is a ledge that runs round the pit.\n"+
          "it will enable you to go north now";
  return "You see nothing of interest";
}

trap() {
  if(trap==1) return "There is a pit trap in the centre of the floor";
  return "You see nothing of interest";
}

floor() {
  if(trap==1) return "You can easily see the pit trap";
  return "All you see is dust";
}

void init() {
  ::init();
  add_action("_search",  "search");
  add_action("_jump", "jump");
}

int _search(string str) {
  if (str == "floor" || str == "cavern") {
    if(trap==1) {
      write("You can easily see the pit trap in the room.\n");
      return 1;
    }
    say(this_player()->query_name()+" searches the floor.\n");
    if (random(6) >= 3) {
      write("You find a pit trap!\n");
      say(this_player()->query_name()+" finds a pit trap!\n");
      trap=1;
      return 1;
    }
    write("You see nothing but dust.\n");
    return 1;
  }
  if(!str) {
    notify_fail("Search what?\n");
    return 1;
  }
}

int _jump(string str) {
  if(str=="pit") {
    write("Boy! You really are crazy!\n");
    this_player()->move_player(
    "into a pit#/players/emerald/perilous/frost/pit");
    write("You jump\n"+
          "          D\n"+
          "           O\n"+
          "            W\n"+
          "             N\n"+
          "                into the pit!\n\n\n");
    say(this_player()->query_name()+" lands with a SPLAT!!!\n");

    this_player()->hit_player(100 + random(50));
    return 1;
  }
  if(!str) {
    notify_fail("Jump where?\n");
    return 1;
  }
}

int do_move() {
  object next, temp;
  next=first_inventory(this_object());
  while(next) {
    temp = next_inventory(next);
    if(living(next)) {
      if(!next->query_npc())
      tell_object(next,"Suddenly the floor opens up and you fall into a deep pit!!!!!\n");
      tell_room("/players/emerald/perilous/frost/pit", 
        next->query_name()+" hits the bottom with a thud!\n");
      this_player()->move_player(
        "suddently downwards!#/players/emerald/perilous/frost/pit");

      next->hit_player(40);
      tell_object(next,"You hit the bottom with a thud!\n");
    }
    next = temp;
  }
  return 1;
}
