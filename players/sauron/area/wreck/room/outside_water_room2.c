/* A sea room coded by Sauron: last change 080595 */
/* Inherit this room if some exits are blocked. */

inherit "/room/room";

#include "/obj/lw.h"

int i,j,k,l,m,n,sea_floor,surface;
object *inv, trigger, pl;
string swim_desc,no_swim_desc,long_desc;
string *swim_dir,*alt_swim_dir,*swim_path,*no_swim_dir,*alt_no_swim_dir;

string query_swim_dir(int i) {
  return swim_dir[i];
}

string query_swim_path(int i) {
  return swim_path[i];
}

string query_no_swim_dir(string str) {
  for(i=0;i<sizeof(alt_no_swim_dir);i++) {
    if(alt_no_swim_dir[i]==str) {
      return no_swim_dir[i];
    }
  }
  return str;
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

string query_no_swim_desc() {
  return no_swim_desc;
}

void heart_beat() {
  if(present(trigger,this_object()) && interactive(trigger)) {
    if(!random(8)) {
      tell_room(this_object(),"BULP.....\n");
      inv=all_inventory(this_object());
      for(j=0;j<sizeof(inv);j++) {
        pl=inv[j];
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
  for(k=0;k<sizeof(swim_dir);k++) {
    if(swim_dir[k]==str) {
      return k;
    }
  }
  for(l=0;l<sizeof(alt_swim_dir);l++) {
    if(alt_swim_dir[l]==str) {
      return l;
    }
  }
  for(m=0;m<sizeof(no_swim_dir);m++) {
    if(no_swim_dir[m]==str) {
      return 10;
    }
  }
  for(n=0;n<sizeof(alt_no_swim_dir);n++) {
    if(alt_no_swim_dir[n]==str) {
      return 10;
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
        case 10:
          switch(str) {
            case "down":
            case "d":
              write("The water below you is too cold to swim in.\n");
              return 1;
            case "up":
            case "u":
              write("The water above you is too cold to swim in.\n");
              return 1;
             default:
              write("The water to the "+query_no_swim_dir(str)
                   +" is too cold to swim in.\n");
              return 1;
          }
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
    writelw("    You could swim "+query_swim_desc()+", but the water "
      +query_no_swim_desc()+" feels too cold to swim in.");
    write("\n");    
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
