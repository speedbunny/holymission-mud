
inherit "room/room";

object bigdiamond;

reset(arg){::reset(arg);
   if(!arg){
           if(!bigdiamond)
        bigdiamond=clone_object("/players/dice/obj/bigdiamond");
        move_object(bigdiamond,this_object());
        }

 if (arg) return;

   property="no_teleport";
   set_light(1);
   no_obvious_msg="";
   no_castle_flag = 1;

   short_desc = "Treasury room";
   long_desc =
     "This is the treasury room, but as you look, there is nothing here.\n"+
     "Except maybe something valuable.\n"+
     "Strange walls are surrounding you.\n";


   dest_dir = ({
       });

   items =({
           "western wall","A strange looking wall made out of solid bricks, maybe you could pass it.",
           "rooms","Treasury room",
           "something","It's not here anymore",
           "wall","Which wall, north, south, east, or west ??",
           "walls","Which wall, north, south, east or west ??",
           "eastern wall","A strange looking wall, made out of solid bricks",
           "north wall","A strange looking wall, made out of solid bricks",
           "south wall","A strange looking wall, made out of solid bricks",
           "east wall","A strange looking wall, made out of solid bricks",
           "west wall","A strange looking wall, maybe you could pass it",
           "northern wall","A strange looking wall, made out of solid bricks",
           "southern wall","A strange looking wall, made out of solid bricks",
           "north wall","A strange looking wall, made out of solid bricks",
           "south wall","A strange looking wall, made out of solid bricks",
           "east wall","A strange looking wall, made out of solid bricks",
           "west wall","A strange looking wall, made of solid rocks, maybe you can pass it.",
           "brick","A magical brick",
           "bricks","Magical bricks"
            });


 }

init() { ::init(); add_action("enter","pass"); }
enter(str) {
  if(str=="wall") {
    write("Which wall, northern, eastern, western or southern ?\n");
    return 1;     }
  if(str=="western wall" || str == "west wall") {
    write("You pass the western wall, and feel transferred somewhere.\n");
    this_player()->move_player("through the wall#players/dice/rooms/vill1");
    return 1;
  }
  else {
    write("You fail to pass the wall\n");
    return 1;
  }
}
