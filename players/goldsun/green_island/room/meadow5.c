inherit "/room/room";
#define PATH "/players/goldsun/green_island/room/"
#define TP this_player()

reset(arg){

if (!arg){
 clone_list=({1,1,"bucket","/players/goldsun/green_island/obj/bucket",0});
 set_light(1);
 short_desc=("On a meadow");
 long_desc=
   ("You are standing on the beautiful green meadow. The grass is\n"+
    "waving in the wind and the drops of dew are shining in the sunbeams.\n"+
    "In the middle of the meadow are small cottage with stony well.\n"+
    "Fresh air gives you a pleasant feeling. If you didn't know you\n"+
    "are on the Green Island, you would think you are in the paradise.\n");

 smell="You smell fresh air.";
 property=({"has_water"});
 dest_dir=({ PATH + "coast6",  "north",
	     PATH + "coast7",  "northwest",
	     PATH + "meadow4", "west",
	     PATH + "meadow3", "southwest",
	     PATH + "meadow2", "south",
	     PATH + "meadow1", "southeast",
	     PATH + "coast5",  "east"});

 items=({"grass","A very nice grass with drops of dew",
	 "drops","The drops of dew. They looks like diamonds",
         "well","You cannot see more than a few feet into the well, but"+
	   	    " you sure\nit is very deep",
         "cottage","A wooden cottage"
         });
  }
 ::reset(arg);
}

 init(){
  ::init();
  add_action("lsten","listen");
  add_action("enter","enter");
  }

int enter(string str){
 if (str=="cottage"){
   TP->move_player("into the cottage#players/goldsun/green_island/room/cottage");
   return 1;
 }
 notify_fail("Enter what?\n");
}

int lsten(){
      write("You can hear a sheep sound.\n"); 
  return 1;
  }              

