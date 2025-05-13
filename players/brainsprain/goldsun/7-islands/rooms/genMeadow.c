inherit "/room/room";
#include "/players/goldsun/stand.h"
 
void reset(int arg){
if (!arg){
 set_light(1);
 short_desc=("On the Emerald");
 long_desc=
"You are in the middle of a meadow on a beautiful island.  High green "+
"grass is slowly waving in the wind and you want to lie here and watch "+
"the clouds above.  The whole island is hilly and grassy.\n";

 smell="You smell many herbs in the air.";

 items=({"hill","A small hill",
	 "island",long_desc,
         "grass","It is waving in the wind"
         });
 }
 ::reset(arg);

}

 init(){
  ::init();
  add_action("do_get","get");
  add_action("do_get","tear");
  add_action("lie","lie");
  add_action("dig","dig");
  }

int dig(string str){
 notify_fail("Dig where?\n");
 if (str=="down"){
  write("The ground it too hard here.\n");
  say(this_player()->query_name()+" tries to dig down.\n");
  return 1;
  }
}

int lie(string str){
 if ( !str || str=="down" || str=="in the grass"){
  write("You lie down in the grass.\n");
  say(OPN+" lies down.\n");
  return 1;
 }
}

int do_get(string str){
  if (str=="grass"){
   write("The grass is too sharp to tear it.\n");
   say(OPN + "tries to tear a grass.\n");
   return 1;
  }
 }

