inherit "/room/room";
#define OPN this_player()->query_name()

reset(arg){
 set_light(1);
 short_desc=("Top of hill");

 long_desc="You are standing on the top of hill. It is covered with\n"+
	   "moss, grass and bushes and continues to the west. You can\n"+
	   "see dense Sherwood forest to the east. From time to time you\n"+
           "can hear an animal sound from it.\n";

 smell="You smell common damp forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/hill1", "down",
           "/players/goldsun/nottingham/room/hill2", "west"});
        
 items=({"forest","The forest looks strange",
	 "green moss","The moss is really green",
	 "soft moss","The moss is soft and green",
	 "bush","The bush is dense and small",
	 "dense bush","This bush is very dense",
	 "dense bushes","The bushes are dense and small",
	 "large hill","The hill is large",
  	 "small bush","The bush is dense and small",
	 "small bushes","The bushes are dense and small",
         "moss", "The moss is green and soft",
         "hill", long_desc,
         "bushes", "The bushes are small and dense"});
 ::reset(arg);

}

 init(){
  ::init();
  add_action("lsten","listen");
  add_action("climb","climb");
  add_action("pass","pass");
  add_action("enter","enter");
  }

 lsten(){
   if (random(5)<=1) {
      write("You can hear an animal sound at this moment.\n"); }
      else write("You can hear a slight breeze in the branches above.\n");
  return 1;
  }              

climb(str){
   if (str=="up" || str=="hill up" || str=="hill"){
   write("Uf.\n");
   write("Uf.\n");
   write("You climb up the hill.\n");
   this_player()->move_player("up#/players/goldsun/sherwood/room/hill2");
   }
   else
    if (str=="down" || str=="hill down"){
     write("You climb down the hill.\n");
     this_player()->move_player("down#/players/goldsun/sherwood/room/shwood38");
    }
    else {
    write("What or where do you want to climb ?\n");
     say(OPN+" looks around.\n");
     }
 return 1;
}

pass(str){
 if (str=="bush" || str=="small bush" || str=="dense bush"){
  write("You don't think you could pass this bush.\n");
  say(OPN+" looks confused.\n");
  }
  else{
   write("What do you want to pass ?\n");
   say(OPN+" looks around.\n");
  }
 return 1;
}

enter(str){
 if (str=="cave" || str=="small cave"){
  write("You enter the cave.\n");
  this_player()->move_player("into the cave#/players/goldsun/sherwood/room/hillcave2");
  }
  else{
   write("What do you want to enter ?\n");
   say(OPN+"looks around.\n");
  }
return 1;
}
