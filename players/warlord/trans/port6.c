// Whisky: That ninjas can reach their guild quickly without teleport :*)

inherit"room/room";
reset(arg) {
 if(arg) return;
 set_light(1);
  short_desc = "[Ezo] Dragon Port 6.\n";
 long_desc="This is one of the many ports of Dragon Airways. If you wait here long \n"+
"enough a Dragon will be by to pick you up.\n";
 dest_dir=({
 "/players/patience/ezo/meadow19", "down",
});
  "players/warlord/trans/port1"->xxx();
 return 1;
 }
