inherit "room/room";

object mingua;

reset(arg) {
  ::reset(arg);
  if(!arg){
    if(!mingua) {
      mingua=clone_object("players/dice/obj/mingua");
      move_object(mingua,this_object());
    }
    set_light(1);
    no_obvious_msg="";
    property = "no_teleport";
    no_castle_flag = 1;
    short_desc = "Treasury room";
    long_desc =
     "This is the treasury room, but as you look, there is nothing here.\n"+
     "Rumour is that a HUGE treasure was stored here,\n"+
     "but nothing of that can be found here.\n"+
     "Very strange walls are surrounding you. \n";
    items =({
           "western wall",
           "A strange looking wall made out of solid bricks, maybe you could pass it",
           "wall","Which wall, north, south, east, or west",
           "walls","Which wall, north, south, east or west",
           "eastern wall","A strange looking wall, made out of solid bricks",
           "north wall","A strange looking wall, made out of solid bricks",
           "guard","A mean looking guard, waiting you to make a wrong move",
           "east wall","A strange looking wall, made out of solid bricks",
           "room","Treasury room",
           "treasury room","A room to keep treasures",
           "south wall","A strange looking wall, made out of solid bricks",
           "northern wall","A strange looking wall, made out of solid bricks",
           "southern wall","A strange looking wall, made out of solid bricks",
           "bricks","Magical bricks",
           "solid bricks","Magical bricks",
           "magical bricks","Solid cold bricks protected by a strong force",
           "west wall","A strange looking wall, maybe you could pass it",
           });
  }
}

init() { 
  ::init(); 
  add_action("pass","pass"); 
}

pass(str) {
  if(!str) {
    notify_fail("Pass what?\n");
    return 0;
  }
  if(str=="wall") {
    notify_fail("Which wall, northern, eastern, western or southern?\n");
    return 0;
  }
  if((str=="western wall")||(str == "west wall")) {
    write("You pass the western wall, and feel transferred somewhere.\n");
    this_player()->move_player("through the wall#players/dice/rooms/vill1");
    return 1;
  }
  notify_fail("Pass what?\n");
  return 0;
}
