inherit "/players/goldsun/7-islands/emerald/room/genMeadow";
#define PATH "players/goldsun/7-islands/emerald/room/"
int _is;

reset(arg){
 _is=0;
 if (!arg){
 clone_list=({1,2,"raccoon","players/goldsun/7-islands/emerald/monster/raccoon",0});
 dest_dir=({ PATH+"coast7", "north",
	     PATH+"coast8", "west",
	     PATH+"meadow1","south",
	     PATH+"meadow5","east"
	   });
 }
 ::reset(arg);
}

int dig(string str){
 notify_fail("Dig where?\n");
 if (str=="down"){
  if (!_is){
     write("You dig down.\nYou find a stone.\n");
     move_object(clone_object("players/goldsun/7-islands/emerald/obj/emerald"),
         this_player());
     _is=1;
   } else  write("You dig down a small hole.\n");
  say(this_player()->query_name()+" digs down.\n");
  return 1;
  }
}

