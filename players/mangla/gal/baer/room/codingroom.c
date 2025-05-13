inherit "/room/room";

#include "/players/matt/defs.h"
#define PPATH "/players/tatsuo/guild/"
#define SUPERWIZ ({"tatsuo","haplo","baer"})
#include "/players/whisky/genesis/sys/break_string.h"

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Tatsuo's Coding Room";
  long_desc = break_string(
	"This is Tatsuo's Private Coding Room. I do all my coding online, "+
        "so please do not interupt as you cannot enter, tell or shout "+
	"into this room. DO NOT TRANS ME OUT OF THIS ROOM, as you will "+
	"be affected by the shadow as well, shadow not dested on trans. "+
	"PLEASE USE A QUICK MAIL MESSAGE IF YOU NEED TO SPEAK.\n",65);
dest_dir=({"/players/tatsuo/friends","out"});
property =({"no_teleport"});
}

void init() {
  ::init();
  if(interactive(TP)) {
    add_action("rshad", "rshad");
    (CLONE(PPATH + "listenshad"))->start_shad(TP);
  }
 if(interactive(this_player()) && member_array(this_player()->query_real_name(), SUPERWIZ)==-1){
 tell_object(this_player(), "You are not permitted into the coding room, please use mail. DO NOT TRANS.\n");
 call_out("not_allowed",1,this_player());
}
}
  
void not_allowed(object boot){
if(boot){
if(boot->query_level()>29)
boot->hit_player(boot->query_level());
tell_object(boot,"Tatsuo beats you about the head and sends you away\n");
boot->move_player("X#room/church");
}
}
int rshad() {
  object shad;
  shad = shadow(TP, 0);
  if(shad) {
    destruct(shad);
    write("Shadow dested.\n");
    return 1;
  }
  write("No shadow detected.\n");
  return 1;
}

void exit(object obj) {
  object shad;
  if(obj && interactive(obj)) {
    shad = shadow(obj, 0);
    if(shad) destruct(shad);
    TELL(obj, "DEBUG: Shadow dested.\n");
  }
}
