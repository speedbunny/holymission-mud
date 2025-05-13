// Virtual area border room.			Written by Sauron, 220897.

inherit "/room/room";

#include "/players/sauron/include/virtual.h"
#include "/players/sauron/include/virtual_functions.c"

private mapping exits;

void add_exit(string dir,string file) {
  if(!exits)
    exits=([]);
  exits[dir]=allocate(2);
  exits[dir][0]=file;
}

void check_exits() {
  string *dirs,master;
  int i,j,x,y,z;
  object ob;

  if(!dest_dir)
    dest_dir=({});
  if(!exits)
    exits=([]);

  dirs=m_indices(exits);
  for(i=0;i<sizeof(dirs);i++) {
    if(sscanf(exits[dirs[i]][0],"%s,%d,%d,%d",master,x,y,z)==4) {
      if(!exits[dirs[i]][1]) {
        master->initialise_exits(({x,y,z}));
        exits[dirs[i]][1]=master->clone_room(({x,y,z}));
      }
      ob=exits[dirs[i]][1];
      j=member_array(dirs[i],dest_dir);
      if(j==-1)
        dest_dir+=({file_name(ob),dirs[i]});
      else
        dest_dir[j-1]=file_name(ob);
    }
    else {
      j=member_array(dirs[i],dest_dir);
      if(j==-1)
        dest_dir+=({exits[dirs[i]][0],dirs[i]});
      else
        dest_dir[j-1]=exits[dirs[i]][0];
    }
  }
}

int move(string str) {
  check_exits();

  return ::move(str);
}

void reset(int arg) {
  if(!arg) {
    check_exits();
  }
  ::reset(arg);
}

void init() {
  check_exits();

  ::init();
}
