inherit"room/room";
reset(arg) {
 if(arg) return;
 set_light(1);
 short_desc="Dragon Port.\n";
 long_desc="This is one of the many ports of Dragon Airways. If you wait here long \n"+
"enough a Dragon will be by to pick you up.\n";
 dest_dir=({
});
 return 1;
 }
