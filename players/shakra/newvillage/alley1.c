/*
 * Author : Uglymouth
 * Date   : 5-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="An obscure alley";
  long_desc="You've entered a small, obscure alley. It breathes an atmosphere like you\n"
	+ "might be attacked any minute. North of you the bright daylight shines on\n"
	+ "Main Street. To the east an abandoned station is standing and west rises\n"
	+ "the dark wall of the churchyard. The alley continues south.\n";
  dest_dir=({PATH+"street4","north",
	PATH+"station", "east",
	PATH+"alley2","south" });
  items=({
	"alley","It's a small backstreet of this village. Junk lingers everywhere",
	"junk","Worthless junk where the mice play in",
	"main street","The way back to safety..",
	"station","The dark building is in a very bad shape. You wonder if it's still in use",
	"mice","Some mice are running openly through the junk that lies here",
	"wall","Although the wooden wall looks rotten, it still feels quite solid",
	"churchyard","Climb the wall if you really want to see it from this side",
	});
}

void init() {
  ::init();
  add_action("search_junk","search");
  add_action("get_it","get");
  add_action("get_it","take");
  add_action("climb_wall","climb");
}

/* search the junk */
int search_junk(string str) {
int findtime;
  if(str!="junk") return 0;
  if(findtime + 600 > time()) return 0;
  if(!random(5)) {
    write("You search through the rubbish and find some money.\n");
    say(this_player()->query_name() + " searches through the junk.\n");
    this_player()->add_money( 1 + random(10) );
    findtime = time();
    return 1;
    }
  write("You search through the junk, but find nothing of interest.\n");
  say(this_player()->query_name() + " searches through the junk.\n");
  return 1;
  }

/* try to take junk or mice */
int get_it(string str) {
  if(str=="junk") {
    write("Why would you risk catching some contagious disease? \n");
    return 1;
    }
  if(str=="mice" || str=="mouse") {
    write("It bites in your thumb and quickly disappears in the junk. \n");
    say(this_player()->query_name() + " runs after a mouse like a madman.\n");
    return 1;
    }
  return 0;
  }

int climb_wall(string str) {
object ob;   
   if(str!="wall") return 0;
   if(this_player()->query_dex() < random(50)) {
      write("You try to climb the wall, but the wood is so slippery you slide down again.\n");
      return 1;
      }
   (PATH+"churchyard1")->dummy();
   ob = find_object( PATH+"churchyard1" );
   write("You climb to the top of the wall, but it's so slippery you lose your balance\n"
       + "and fall down again at the other side of the wall.\n");
   tell_room(ob,"Someone tumbles down from the east wall of the churchyard.\n");
   this_player()->move_player("over the wall#" + PATH + "churchyard1");
   return 1;
   }

