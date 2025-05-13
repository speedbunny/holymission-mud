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
    "to the south and southeast. You have a nice view on the blue sea\n"+
    "from this place. Fresh air gives you a pleasant feeling.\n"); 

 smell="You smell fresh sea air.";
 
 dest_dir=({ PATH + "coast7", "northeast",
             PATH + "meadow4","east",
             PATH + "meadow3","southeast",
	     PATH + "hill3",  "south",
	     PATH + "hill2",  "southwest"});
 
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

