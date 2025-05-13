inherit "room/room";
#include "/players/redsexy/defs.h"

reset(arg) {
  set_light(1);
  short_desc="A sophisticated bar in the Upper Jedi sanctums";
  long_desc="This is the Sanctum Bar, a suave and sophisticated place decorated in black "+
            "and white, serving a range of beverages to please even the most discerning "+
            "Jedi Knight.  Your host is Renade, a smooth and well educated Rodian, well "+
            "versed in the art of mixing cocktails.  There is a stairway in "+
            "one corner of the bar leading down to the lower sanctum of the "+
            "Jedi Guild.  There is menu on the wall, maybe you could read it.\n";

  dest_dir=({"/players/mangla/guild/rooms/inner","down",
             "/players/mangla/guild/rooms/hall","south",
           });

  items=({"bar","This is the Sanctum Bar",
          "decorations","The place is done out in black and white, and Renade wears a suit to match",
          "menu", "A wooden sign hangs on the wall with a list of cocktails",
          "beverages", "You notice a range of colorful drinks",
          "cocktails", "You notice a range of colorful drinks",
          "renade", "Renade is a cool and poised Rodian, serving drinks in the Sanctum bar ",
        });

  ::reset(arg);
 
}
init() {

    add_action("order","order"); 
    add_action("order","buy"); 
    add_action("read","read"); 
    ::init();
}

read(str) {

  if (str=="menu" || str=="sign") {
     write(
      "*******************************************************\n"+
      "                   THE SANCTUM BAR                      \n"+
      "*******************************************************\n"+
      "Cocktails now being served:\n"+
      "1   Sarlacc Spice                          1000 coins \n"+
      "2   Juri Juice                              900 coins \n"+
      "3   Dark Dreamer                            600 coins \n"+
      "4   Jedi Generation                         200 coins \n"+
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

  if (str == "spice" || str == "sarlacc" || str == "1") {
  if(this_player()->query_money()<1000){
      write("Renade says: The Sarlacc Spice costs 1000 coins.\n");
      return 1;
  }
      mess = "Renade gives you a Sarlacc Spice, the delicacy of the desert...\n" +
             "It goes down so smoothly, you declare that he is a genius";
      heal = 400;
      value= 1000;
      strength = 25;
      art ="alko";
  }
  else
  if (str == "juri" || str == "juice" || str == "2") {
  if(this_player()->query_money()<900){
      write("Renade says: The Juri Juice costs 900 coins.\n");
      return 1;
  }
      mess = "The juri juice is the bar speciality, Renade mixes it "+
             "expertly, and you knock it down in one.";
      heal= 350;
      value= 900;
      strength = 25;
      art ="alko";
  }
  else
  if (str == "dark" || str == "dreamer" || str=="3") {
  if(this_player()->query_money()<600){
      write("Renade says: A Dark Dreamer costs 600 coins.\n");
      return 1;
  }
      mess = "You drink a creamy Dark Dreamer, and feel kinda mellow for a while..";
      heal = 200;
      value = 600;
      strength = 25;
      art = "alko";
  }
  else
  if (str == "jedi" || str == "generation" || str=="4"){
      mess = "Renade says: The Jedi Generation is the only non alcoholic drink I serve.\n"+
             "You feel ready for anything now!\n";
      heal = 200;
      value = 200;
      art = "special";
  }
  else
  {
  write("Renade looks puzzled.\n");
  return 1;
  }

  if (art=="alko" || art=="boost") {
  if (!call_other(TP, "drink_alcohol", strength)) {
      write("Renade says: Get some food, sober up, and come back quickly, OK?\n");
     return 1;
     }
  }
  else
  if (art=="soft") {
      if (!call_other(TP,"drink_soft",strength)){
         write("Renade says: Get outta here ya pansy!\n");
      return 1;
      }
  }

  write("You pay for your cocktail.\n");
  write("You pay " + value + " coins.\n");
  this_player()->add_money(-value);


  if(art=="special") TP->restore_spell_points(heal);
  else 
    TP->heal_self(heal);
    write(mess + "\n");
    
  if(strength==50) say("Renade whispers to you"+ TP->query_name() +" is totally slaughtered." +
      "start tickling them for a laugh...\n");
  return 1;
}

   
