inherit "/room/room";
#define PATH "/room/shore/"

reset(arg){

if (!arg){

 set_light(1);
 short_desc=("Ocean shore");
 long_desc=
   "You are on the road leading south next to the ocean shore. Huge waves roll\n"+
   "towards the land. You notice seagulls in the far distance.\n";
   
 smell="The air smells salty here";

 dest_dir=({ PATH + "s01",   "southwest"});
 
 items=({ "ocean","The wild green ocean",
          "wave","It rolls exactly in your direction",
          "waves","They roll and roll and roll and ....",
          "tide","The flood is on its highest level",
          "land","Almost as much as water",
          "birds","Seems to be a group of seagulls",
          "seagulls","Wow, more than one seagull in fact",
          "distance","Seems far away" });
  }
 ::reset(arg);
 replace_program("room/room");
}


