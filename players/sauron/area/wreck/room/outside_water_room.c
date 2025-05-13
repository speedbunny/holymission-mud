/* A sea room coded by Sauron: last change 6.2.95 */
/* Inherit this room if all exits are possible. */

inherit "/room/room";

#include "/obj/lw.h"

int i,j,k,sea_floor,surface;
object *inv, trigger, pl;
string swim_desc,long_desc,*swim_dir,*alt_swim_dir,*swim_path;

string query_swim_dir(int i) {
  return swim_dir[i];
}

string query_swim_path(int i) {
  return swim_path[i];
}

int query_sea_floor() {
  return sea_floor;
}

int query_surface() {
  return surface;
}

string query_swim_desc() {
  return swim_desc;
}

void heart_beat() {
  if(present(trigger,this_object()) && interactive(trigger)) {
    if(!random(8)) {
      tell_room(this_object(),"BULP.....\n");
      inv=all_inventory(this_object());
      for(i=0;i<sizeof(inv);i++) {
        pl=inv[i];
        if(living(pl)) {
          if(!pl->query_immortal()) {
            pl->hit_player(1);
          }
        }
      }
    }
  }
  else set_heart_beat(0);
}

void do_swim(int i) {
  write("You swim "+query_swim_dir(i)+".....\n");
  this_player()->move_player("swimming "+query_swim_dir(i)
                            +"#"+query_swim_path(i));
}

int valid_swim(string str) {
  for(j=0;j<sizeof(swim_dir);j++) {
    if(swim_dir[j]==str) {
      return j;
    }
  }
  for(k=0;k<sizeof(alt_swim_dir);k++) {
    if(alt_swim_dir[k]==str) {
      return k;
    }
  }
  return 11;
}

int swim_to(string str) {
  switch(str) {
    case "":
    case 0:
      write("You tread water.\n");
      say(this_player()->query_name()+" treads water.\n");
      return 1;
    case "down":
    case "d":
      if(query_sea_floor() && (str=="down" || str=="d")) {
        write("You are already on the sea floor.\n");
        return 1;
      }
    case "up":
    case "u":
      if(query_surface() && (str=="up" || str=="u")) {
        write("You are already at the surface.\n");
        return 1;
      }
    default:
      switch(valid_swim(str)) {
        case 11:
          write("Swim where?\n");
          return 1;
        default:
          do_swim(valid_swim(str));
          return 1;
      }
  }
}

mixed long(string str) {
  if(!str) {
    writelw(process_string(long_desc));
    writelw("    You could swim "+query_swim_desc()+".\n\n");
    return;
  }
  return (::long(str));
}

void init() {
  ::init();
  if(interactive(this_player())) {
    trigger=this_player();
    tell_room(this_object(),"BULP.....\n");
    set_heart_beat(1);
  }
  add_action("swim_to","swim");
}
