inherit "room/room";

#include "/players/skeeve/area.h"

int nr;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_light(0);
    property = "no_teleport";
    short_desc = "Maze";
    long_desc =  "The holy maze.\n";
    smell="The air smells dusty and musty";
    items=({ 
        "walls",  "The walls are of cracked terra cotta",
        "floor",  "The floor is covered with sand"
    });
    if ( sscanf(file_name(this_object()),MAZE+"maze%d",nr) == 1){
  /* tell_object(find_player("skeeve"),"maze("+nr+") reset.\n");*/
      (MAZE+"chapel")->set_maze(nr,this_object());
    }
  }
}

set_monster(mon){
int i,b;
for (b=1,i=0;i<11;i++,b=b<<1)
  if (mon & b)
    move_object(clone_object(MONSTERS+"mmonster")->config(i),this_object());
}

set_dir(dir) {
  dest_dir = dir;
/*  update_actions(); */
}
