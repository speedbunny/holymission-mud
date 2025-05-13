/* A sea room coded by Sauron: last change 080595 */
/* Inherit this room if all exits are possible. */

inherit "/room/room";

#include "/obj/lw.h"

int i,j,k,sea_floor,surface;
object *inv, pl;
static private object trigger;
static private string swim_desc;
static private string ld;
static private string *swim_dir;

void add_swim_exit(string dir,string short_dir,string path) {
  if(!swim_dir) swim_dir=({});
  swim_dir+=({dir,short_dir,path});
}

string query_swim_dir(int i) {
  return swim_dir[3*i];
}

string query_swim_path(int i) {
  return swim_dir[(3*i)+2];
}

void set_sea_floor() {
  sea_floor=1;
}

int query_sea_floor() {
  return sea_floor;
}

void set_surface() {
  surface=1;
}

int query_surface() {
  return surface;
}

void set_trigger(object ob) {
  trigger=ob;
}

object query_trigger() {
  return trigger;
}

void set_swim_desc(string str) {
  swim_desc=str;
}

string query_swim_desc() {
  return swim_desc;
}

void do_swim(int i) {
  write("You swim "+query_swim_dir(i)+".....\n");
  this_player()->move_player("swimming "+query_swim_dir(i)
                            +"#"+query_swim_path(i));
}

int valid_swim(string str) {
  for(j=0;j<sizeof(swim_dir);j+=3) {
    if(swim_dir[j]==str) {
      return j/3;
    }
    else continue;
  }
  for(k=1;k<sizeof(swim_dir);k+=3) {
    if(swim_dir[k]==str) {
      return (k-1)/3;
    }
    else continue;
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

void set_long(string desc) {
  ld=desc;
}

mixed long(string str) {
  if(!str) {
    writelw(process_string(ld));
    writelw("    You could swim "+query_swim_desc()+".\n");
    return;
  }
  return ::long(str);
}

void init() {
  ::init();
  if(interactive(this_player())) {
    set_trigger(this_player());
    tell_room(this_object(),"BULP.....\n");
    set_heart_beat(1);
  }
  add_action("swim_to","swim");
}
