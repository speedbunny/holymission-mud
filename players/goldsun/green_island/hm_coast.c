inherit "/room/room";
#define PATH "/room/shore/"


reset(arg){
  ::reset(arg);

   if (!present("hook",this_object()))
     move_object("players/goldsun/green_island/monster/hook",this_object());

   if (!present("stilt house",this_object()))
     move_object(clone_object("players/goldsun/green_island/obj/cott"),
          this_object());

if (!arg){
 set_light(1);
 short_desc=("Ocean shore");
 long_desc=
   "You are on the road leading south next to the ocean shore. Huge waves roll\n"+
   "towards the land. You notice seagulls in the far distance.\n";
   
 smell="The air smells salty here";

 dest_dir=({ PATH + "s03",   "west",
	     PATH + "s04",   "south"});
 
 items=({ "ocean","The wild green ocean",
          "wave","It rolls exactly in your direction",
          "waves","They roll and roll and roll and ....",
          "tide","The flood is on its highest level",
          "land","Almost as much as water",
          "birds","Seems to be a group of seagulls",
          "seagulls","Wow, more than one seagull in fact",
          "distance","Seems far away" });
  }
}


