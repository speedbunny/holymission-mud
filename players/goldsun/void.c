inherit "/room/room";

void reset(int arg){
 if (arg) return;
  set_light(1);
  short_desc=("Void");
  long_desc=("Goldsun's void.\n");  
  dest_dir=({"/room/church","church"});
  replace_program("room/room");
 }

