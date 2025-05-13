inherit "/room/room";
#include "../light.h"
#include "../shake.h"
#include "../climb.h"
#include "../cut.h"
#include "../tear2.h"
#include "../dig.h"

reset(arg){
 if (!arg){
 clone_list=({1,1,"hern","/players/goldsun/sherwood/monster/hern",0});
 set_light(1);
 short_desc=("The hill");
 long_desc=("You are on a hill. There are small bushes and green moss\n"
		+"around you."
 	   +" The trees seems to be very mystical.\n"
	   +"Something in your mind tells you that this place is very holy.\n"
           +"From time to time you can hear an animal sound from"
                 +" the forest.\n");

 smell="You feel common dump forest air.";
 dest_dir=({"/players/goldsun/sherwood/room/shwood38", "north"});
 property=({"no_steal","no_fight"});
 items=({"forest","The forest looks strange",
	 "green moss","The mopss is really green",
	 "soft moss","The moss is soft and green",
	 "grass","The grass is waving in the wind",
	 "bush","The bush is dense and small",
	 "tree","Old tree which seems to be mystical",
	 "old tree","Old tree which seems to be mystical",
	 "old trees","The trees seems to be mystical",
	 "trees","The trees seems to be mysrical",
	 "dense bush","This bush is very dense",
	 "dense bushes","The bushes are dense and small",
  	 "small bush","The bush is dense and small",
	 "tree","The tree is grow up for many years",
	 "small bushes","The bushes are dense and small",
         "moss", "The moss is green and soft",
         "hill", "The hill is covered by the moss and small bushes",
         "bushes", "The bushes are small and dense"});
 }
 ::reset();
}

 init(){
  ::init();
  add_action("lsten","listen");
  add_action("pass","pass");
  add_action("tear2","tear");
  add_action("shake","shake");
  add_action("cut","cut");
  add_action("light","light");
  add_action("climb","climb");
  add_action("dig","dig");
  add_action("cut","chop");
  }

 lsten(){
   if (random(5)<=1) {
      write("You can hear an animal sound at this moment.\n"); }
      else{ write("You can hear a slight breeze in the branches above.\n");}
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
