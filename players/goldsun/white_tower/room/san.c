inherit "/room/room";
#define PATH "/players/goldsun/white_tower/room/"
#define TP this_player()
#define SAY(x) tell_room(this_object(),x)

string *name;   /* name of victime */

void knight(object pl){
 object co;
 SAY("Knight arrives.\nKnight tries to leave west.\nSphinxes open "+
       "their eyes and lightning bolts smash knight.\nKnight died.\n");
 co=clone_object("/players/goldsun/white_tower/obj/k_corpse");
 transfer(co,this_object());
 return;
}

reset(arg){

if (!arg){

 set_light(1);
 short_desc=("San Donorico");
 name=({});
 long_desc=
   "This is Moon valley. This place is also called San Donorico.\n"+
   "You can see tall rocky peaks to the north and south. Valley\n"+
   "continues to the west. There are HUGE SPHINXes from the both\n"+
   "side of the valley.\n";
   
 smell="The air smells dusty here";

 dest_dir=({ PATH + "vall_road",     "west",
	     PATH + "rocky_path",   "east" });
 
 items=({ "valley","Moon valley alias San Donorico",
 	  "sphinx","Her eyes are closed",
          "sphinxes","Their eyes are closed"
           });
  }
 ::reset(arg);

}

init(){
 ::init();

call_out("knight",1,TP);
add_action("g_west","west");
add_action("sneak","sneak");
}

int sneak(){
 write("You don't want to do that.\n");
 return 1;
}

int g_west(){

 if (!present("west_pass_valley_goldsun",TP) )
    if (member_array(TP->query_real_name(),name)==-1)
    {
      write("Invisible force whispers you: Try it again and you will see golden"+
          " flash.\n");
      name +=({TP->query_real_name()});
      return 1;
     }
     else
     {
       transfer(TP, PATH+"dt");
       return 1;
      }
}
