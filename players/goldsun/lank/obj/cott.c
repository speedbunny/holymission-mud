inherit "/obj/treasure";
#include "/players/goldsun/stand.h"
#define INSIDE "/players/goldsun/lank/room/cottage"

status is_lighted;
object me;

int kamikadze(){ 
 destruct(me);
 return 1;
 }

 
reset(arg){


if (arg) return;
is_lighted=0;
me=this_object();
set_id("cottage");
set_short("An old wooden cottage");
set_long("An old wooden cottage. It seems to be fisherman or\n"
     +"sailor cottage. The wood is very dry.\n");
}

get(){
 return 0;
}


init(){
 ::init();

add_action("enter","enter");
add_action("light_it","light");
}

int enter(string str){
 if (str=="cottage"){
  if (is_lighted==1){ write("You don't want to burn into heap of ash.\n"); 
         return 1;}
  write("You enter the cottage.\n");
  this_player()->move_player("in#/players/goldsun/lank/room/cottage");
  }
 else write("Enter what ?\n");
 return 1;
}

int light_it(string str){
  if (str=="cottage" || str=="wood"){
    write("You light the cottage !\n");
    is_lighted=1;
    say(OPN+" lights the cottage.\n");
    INSIDE->start_fire();
    tell_room(INSIDE,"Someone lights the cottage !!!\n");
    return 1;
  }
 }

