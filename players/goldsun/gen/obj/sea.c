inherit "/room/room";
#define TP this_player()

void reset(int arg){

if (!arg){
 set_light(1);
 short_desc=("Eastern Sea");
 long_desc="You are in the sea.\n";
  }
 ::reset(arg);
 replace_program("room/room");
}

