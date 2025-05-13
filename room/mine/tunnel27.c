/* 12.10.93 Airborne: Fixed. */

inherit "room/room";

reset(arg){
  if(arg) return;
  short_desc = "Tunnel";
  long_desc = "Tunnel into the mines.\n";
  dest_dir = ({ "room/mine/tunnel26", "south",
                "players/moonchild/trollslayer/altar", "north",
              });

replace_program("room/room");
}
