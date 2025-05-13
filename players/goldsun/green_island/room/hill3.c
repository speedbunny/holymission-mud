inherit "/room/room";
#define PATH "/players/goldsun/green_island/room/"

reset(arg){
if (arg) return;
 set_light(1);
 short_desc=("On a plain");
 long_desc=
   ("You are standing on the high, beautiful green plain. The grass is\n"+
    "waving in the wind and the drops of dew are shining in the sunbeams.\n"+
    "The small white rocks lie somewhere on grass. The plain continues\n"+
    "to the south, west and north. You have a nice view on the blue sea\n"+
    "from this place. Fresh air gives you a pleasant feeling.\n"); 

 smell="You smell fresh sea air.";
 
 dest_dir=({ PATH + "hill4",   "north",
             PATH + "meadow4", "northeast",
             PATH + "meadow3", "east",
             PATH + "coast4",  "southeast",
	     PATH + "hill1",   "south",
	     PATH + "hill2",   "west"});
 
 items=({"grass","A very nice grass with drops of dew",
	 "drops","The drops of dew. They looks like diamonds"
	 "rock","A white rock. It lies on the grass",
	 "rocks","Several rocks. They lie on the grass" 
         "sea","The sea rustles deep under you",
	 "plain","@@long_desc@@"
         });
 ::reset(arg);

}

 init(){
  ::init();
  add_action("lsten","listen");
  }

 lsten(){
      write("You can hear a sheep sound.\n"); 
  return 1;
  }              

