
/* room for boats. there are boats that sail to the harbour */

inherit "/room/room";
#define TP this_player()

void reset(int arg){

if (!arg){
 set_light(1);
 short_desc=("Eastern Sea");
 long_desc="You are in the sea.\n";
 property=({"no_clean_up"});
  }
 ::reset(arg);
 replace_program("room/room");
}

