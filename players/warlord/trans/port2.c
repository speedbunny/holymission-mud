inherit"room/room";
reset(arg) {
 if(arg) return;
 set_light(1);
 short_desc ="[Rasta City] Dragon Port 2";
 long_desc="This is one of the many ports of Dragon Airways. If you wait here long \n"+
"enough a Dragon will be by to pick you up.\n";
 dest_dir=({
// "players/rasta/room/raspath","down",
});
  "players/warlord/trans/port1"->xxx();
 return 1;
 }
