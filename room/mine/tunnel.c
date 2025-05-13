/* 12.10.93 Airborne: Re-write for room/room and other fun stuff. */

inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "Mine entrance";
  long_desc =
             "This is the entrance to a large mining system. " +
             "North leads further under the mountains while a " +
             "rubble strewn embankment leads up into the light.\n";
  dest_dir = ({
               "room/mount_pass", "up",
               "room/mine/tunnel2", "north",
             });

replace_program("room/room");
}                       
