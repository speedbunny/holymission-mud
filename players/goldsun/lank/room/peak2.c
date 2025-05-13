inherit "/room/room";

reset(arg){
 ::reset(arg);
 if (arg) return;
 set_light(1);
 short_desc=("On the Lankpeak");
 long_desc=
  "You are on the Lankpeak. Far above your head you can see\n"
 +"the tall, snow-topped peak of Lankbourg mountains. To the\n"
 +"west you can see a path of island. A dense vine is here.\n";
                                                                      
 smell="You smell could and damp air.";
 no_castle_flag=1;
 dest_dir=({"/players/goldsun/lank/room/coast15","down"});
 items=({"island","It is Lank",
	 "peak","A snow-topped peak. Its named Lankpeak and it is tall",
	 "vine","A nice green vine. It is very dense and it can hide\n"+
	     	  "something",
         "hole","Small dark entrance to the mountains"
        });

}
init(){
 ::init();
add_action("do_search","search");
add_action("do_enter","enter");
}

int do_search(string str){
 if (str=="vine"){
     write("As you search the vine, you find a small hole.\n");
     say(this_player()->query_name()+" searches a vine.\n");
     return 1;
    }
 write("Search what ?\n");
 return 1;
}

int do_enter(string str){
 if (str=="hole" || str=="mountains"){
  write("You enter the hole.\n");
  this_player()->move_player("into the hole#players/goldsun/lank/room/mine3");
  return 1;
 }
 write("There is no "+str+" here.\n");
 return 1;
}

