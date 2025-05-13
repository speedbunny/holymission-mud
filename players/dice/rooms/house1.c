

inherit "room/room";

object minwife;

reset(arg) {
  ::reset(arg);
  if(!minwife){
      minwife=clone_object("players/dice/obj/minwife");
      move_object(minwife,this_object());
  }

  if (arg) return;

  set_light(1);

  short_desc = "Livingroom";
  long_desc =
     "Entering the house you see a soberly furnished room.\n"+
     "This room speaks of hard work, and less money than you have.\n"+
     "But you feel peace and rest surrounding you.\n"+
     "There is a small cellar below the house, maybe you could enter it...\n";

  dest_dir = ({
      "players/dice/rooms/vill1","south",
      "players/dice/rooms/house2","east",
      "players/dice/rooms/house3","west",
      "players/dice/rooms/house4","northwest",
      "players/dice/rooms/house5","northeast",
             });

  items =({
          "furniture","A chair, a table and a few lights can be seen",
          "house","A small coalminers house",
          "room","A soberly furnished room",
          "chair","The easy, very relaxing chair of the coalminer",
          "table","A table made up for dinner",
          "cellar","A small cellar below the house, maybe you could enter it..",
          "lights","Home-made lights, made by the coalminer",
          "light","Home-made light, made by the coalminer"
          });

}

init() {
    ::init();
    add_action("enter","enter");
}

enter(str) {
    if(str=="cellar"){
      write("You walk down the stairs into the cellar \n");
      this_player()->move_player("Down the cellar#/players/dice/rooms/house6");
      return 1;
    } else {
      notify_fail("Enter what ??\n");
      return 0;
    }
}


