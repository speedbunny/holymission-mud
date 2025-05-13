
inherit "room/room";
query_no_teleport() { return 1; }

reset(arg) {

if (arg) return;

   set_light(1);
   no_castle_flag = 1;
   property = "no_teleport";
   short_desc = "MYSTERY ZONE";
   long_desc =
     "You are about to enter the MYSTERY ZONE.\n"+
     "Once entered you must clear the maze, otherwise there will\n"+
     "be no way to get out.\n"+
     "You can see a strange sign standing in the middle of a cloud.\n";

    dest_dir = ({
              "players/dice/2light/2l7","south",
              "players/dice/2light/mz2","north"
              });

   items =({
           "ZONE","MYSTERY ZONE",
           "zone","Mystery zone",
           "MYSTERY ZONE","A black hole between space and time",
           "mystery zone","A black hole between space and time",
           "maze","You look north and see a strange black hole in\n"+
                  "the fabric of space and time",
          "cloud","A white-colored cloud",
          "sign","A strange sign, maybe you can read it",
          });



   smell = "The smell of fear and pleasure mixed very well";
}
init(){
   ::init();
     add_action("read_sign","read");
               ("enter_hole","enter");
      }
read_sign(str){
    if(!str){
     notify_fail("Read what ?\n");
     return 0;
     }
     if((str=="sign")||(str=="strange sign")){
     write("!! ENOZ YRETSYM \n");
     return 1;
     }
    }
enter_hole(str){
    if(!str){
    notify_fail("Enter what ?\n");
    return 0;
    }
    if((str=="hole")||(str=="black hole")||(str=="black hole")){
    this_player()->move_player("Through the hole#/players/dice/2light/2l1");
    return 1;
    }
}
