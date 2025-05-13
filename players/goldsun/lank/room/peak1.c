inherit "/room/room";
status is_moved;

reset(arg){
 ::reset(arg);
 if (arg) return;
 set_light(1);
 short_desc=("On the Lankpeak");
 long_desc=
  "You are on the Lankpeak. Far above your head you can see\n"
 +"the tall, snow-topped peak of Lankbourg mountains. To the\n"
 +"east you can see a path of island. There are many rocks around\n"
 +"you.\n";

 smell="You smell could and damp air.";
 no_castle_flag=1;
 dest_dir=({"/players/goldsun/lank/room/coast8","down"});
 is_moved=0;
 items=({"island","It is Lank",
	 "peak","A snow-topped peak. Its named Lankpeak and it is tall",
	 "rock","A dark rock. It is not very huge. You can move it",
	 "rocks","There are many dark rocks. Some of them aren't very huge"
        });

}
init(){
 ::init();
add_action("do_move","move");
add_action("do_enter","enter");
}

int do_move(string str){
 if (str=="rock")
   if (!is_moved){ 
     write("As you move a rock, you find a small hole.\n");
     say(this_player()->query_name()+" moves a rock.\n");
     items += ({"hole","Small dark entrance to the mountains"});
     is_moved=1;
     return 1;
    }
   else{
    write("You move a rock.\n");
    say(this_player()->query_name()+" moves a rock.\n");
    return 1;
   }
 write("Move what ?\n");
 return 1;
}

int do_enter(string str){
 if ((str=="hole" || str=="mountains") && is_moved){
  write("You enter the hole.\n");
  this_player()->move_player("into the hole#players/goldsun/lank/room/mine1");
  return 1;
 }
 write("There is no "+str+" here.\n");
 return 1;
}

