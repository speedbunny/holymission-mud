#include "/players/redsexy/defs.h"

inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="A restaurant in the Upper Jedi sanctums";
  long_desc="The dining area of the upper sanctum is manned by the haphazard chef, Doofy. "+
            "Despite his chaotic flailings around the kitchen, everything in here smells  "+
            "great and you long taste some of the Jedi delights he is cooking up.  "+
            "There is a menu here, perhaps you should read it?\n ";

  dest_dir=({"/players/mangla/guild/rooms/hall","west",
           });

  items=({"area","There are large comfortable leather seats dotted around tables here ",
          "kitchen","Behind the servery counter you can see pots and pans on the boil",
          "doofy","Doofy looks like a clumsy Wookie, but actually he is a yummy cook",
          "chef","Doofy laughs as you look at him!",
          "pots","Pots are on the boil",
          "pans","The pans are frying up some delights",
          "delights","These morsels of food look scrummy!",
          "menu","A menu.  Try reading it",
         });

  ::reset();
 
}

init() {

    AA("order","order"); 
    AA("order","buy"); 
    AA("read","read"); 
    ::init();
}

read(str) {

  if (str=="menu" || str=="sign") {
     write(
      "*******************************************************\n"+
      "                   THE SANCTUM SERVERY              \n"+
      "*******************************************************\n"+
      "Meals now being served:\n"+
      "1   Sarlacc Steaklets                  1000 credits \n"+
      "2   Whipid Style Wholehog               800 credits \n"+
      "3   Darkside Fries                      600 credits \n"+
      "4   Wildveg		                300 credits \n"+
      "5   Seaweed	                        200 credits \n"+
      "*******************************************************\n"


      );
  return 1;
  }
}


order(str) {

  string name, short_desc,art, mess;
  int value, cost, strength, heal,i;
  object dummy;

  if (!str) {
      write("Renade glances over, looking seductively puzzled.\n");
  return 1;
  }


  if (str == "steaklets" || str == "sarlacc" || str == "1") {
  if(this_player()->query_money()<1000){
      write("Doofy says: The Sarlacc Steaklets cost 1000 credits.\n");
      return 1;
  }
      mess = "Doofy cooks up some tender Sarlacc Steaklets, sizzling \n" +
             "as he serves them.  You savour every mouthful.";
      heal = 400;
      value= 1000;
      strength = 25;
      art ="food";
  }
  else
  if (str == "whipid" || str == "wholehog" || str == "2") {
  if(this_player()->query_money()<800){
      write("Doofy says: The Whipid Wholehog costs 800 credits.\n");
      return 1;
  }
      mess = "This dish turns out to be a crispy skinned whole piglet! Yummy!";
      heal= 300;
      value= 800;
      strength = 13;
      art ="food";
  }
  else
  if (str == "darkside" || str == "fries" || str=="3") {
  if(this_player()->query_money()<600){
      write("Doofy says: The Darkside Fries costs 600 credits.\n");
      return 1;
  }
      mess = "These fries come smothered in a dark sauce, and you eat the plateful greedily.";
      heal = 200;
      value=600;
      strength = 8;
      art = "food";
  }
  else
  if (str == "wildveg" || str == "4") {
if(this_player()->query_money()<300){
      write("Doofy says: Wildveg costs 300 credits.\n");
      return 1;
  }
      mess = "The wildveg are fresh and juicy, making you feel better.\n";
      heal = 50;
      value= 300;
      strength = 3;
      art = "food";
  }
  else
  if (str == "seaweed" || str=="5"){
  if(this_player()->query_money()<200){
      write("Doofy says: Seaweed costs 200 credits.\n");
      return 1;
  }

      mess = "Doofy says: Seaweed is food for the brain.\n"+
             "You feel ready for anything now!\n";
      heal = 200;
      value = 200;
      strength = 25;
      art = "special";
  }
  else
  {
  write("Doofy looks puzzled.\n");
  return 1;
  }

 if (art=="food") {
      if (!call_other(TP,"eat_food",strength)){
         write("Doofy says: Yer fat enough already pal\n");
         say(TPQN+" shouldn't really eat anymore...\n");
      return 1;
      }
  }
 if (art=="soft") {
      if (!call_other(TP,"drink_soft",strength)){
         write("Doofy says: Get outta here ya pansy!\n");
      return 1;
      }
  }

  write("You pay for your meal.\n");
  write("You pay " + value + " coins.\n");
  this_player()->add_money(-value);


  if(art=="special") TP->restore_spell_points(heal);
  else 
    TP->heal_self(heal);
    write(mess + "\n");
    
  
  return 1;
}
