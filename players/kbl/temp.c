#define who this_player()
#include "/players/acdc/city/path.h"
inherit "room/room";

object wizard;
int port=0;
reset(arg) {
::reset(arg);
if(!wizard) {
  wizard=clone_object(PATH+"obj/melgemar");
  transfer(wizard,this_object());
}
if(arg) return 1;

  set_light(1);
  short_desc="Travel Agency";
  long_desc=
    "You are very dazed from the entrance.  It is very large in here\n"
   +"There is a tall throne in the center of the room.  Sitting in the\n"
   +"throne is Melgemar, The Greatest Teleporter.  If you tell him \n"
   +"where you want to go, he will send you there for a price of course\n"
   +"If you know another great wizards name and say it in his presence\n"
   +"Melgmar will send you to his territory.  Read the sign for some\n"
   +"other areas of interest.\n";
  items=
   ({
     "throne","Melgemar is always siting in it.  The throne is covered\nwith jewels and gold",
     "entrance","The entrance is tiny compared to the size of the inside",
    "room","It is magical that is why it seems large",
    "sign","You don't look at a sign you read it",
  });
dest_dir =
  ({
   "/players/acdc/city/town32","out",
  });
}
init() {
::init();
  add_action("wake_me","wake");
  add_action("teleport_you","teleport");
  add_action("enter_portal","enter");
}

wake_me(str) {
  if(!str || str=="melgemar" || str=="wizard" || str=="teleporter") {
    switch(random(5+1)) {
     case 1: tell_object(who,
               "Melgemar laughs and says: This is a mere warning!!!\n");
             tell_object(who,
               "You feel yourself being teleported through the air\n"
              +"at a great height!  You wonder if it will hurt when\n"
             +"you land upon the ground!\n");
             who->heal_self(random(40)+50-100);
             transfer(who,"/room/slope");
             return 1;
             break;
     case 2: tell_object(who,
               "Melgemar raises his hands and throws a flash at you!\n");
             who->heal_self(random(50)-120);
             return 1;
             break;
     case 3: tell_object(who,
               "Melgemar shouts: What the hell are you doing! \n");
             tell_object(who,
               "You feel your whole body breaking apart!\n");
             command("scream",who);
             transfer(who,PATH+"entrance");
             return 1;
             break;
     case 4: tell_object(who,
                "Melgemar waves his hands and produces a floating cage.\n"
               +"You blink and come to realize you are in the cage.\n"
               +"Next thing you know a Silver dragon is coming right\n"
               +"at you.  What do you do know!\n");
             transfer(who,PATH+"cage");
             return 1;
             break;
    case 5: tell_object(who,
              "Melgemar chuckles and says: I am very evil!\n"
             +"He lifts one hand and you start to feel stiff!\n"
             +"You slowly realize that he has petrified you somehow.\n");
              return 1;
            /* somehow hold the player...maybe a prison */
    }
    }
}

teleport_you(str) {
 string mess;

  if((sscanf(str,"me to %s",mess)) || (sscanf(str,"me %s",mess))) {
    if(mess=="acdc") {
      tell_object(who,
       "Melgemar chuckles and says: Are you not already in this\n"
     +"                             great land of his!\n");
      return 1;
     }
     else if(mess=="alian") {
       if(who->query_money() > 2000) {
         /* create portal */
         return 1;
       }
       else {
          tell_object(who,
           "Melgemar groans and says: You do not have the funds to \n"
          +"                          travel that far!\n");
          return 1;
        }
      }
      else {
        tell_object(who,
          "Melgemar whispers: I am not familiar with that area.\n");
         return 1;
      }
   }
}
create_portal() {
  object portal;

  portal=clone_object("/obj/treasure");
  portal->set_name("Voidless portal");
  portal->set_alias("portal");
  portal->set_weight(100);
  portal->set_long("A swirling massless cloud.  If you look closely\n"
                  +"you can see your destination.\n");
  portal->set_value(0);
  port=1;
}
enter_portal(str) {
  string mess;
  if(sscanf(str,"%s",mess)) {

    if(mess=="portal" && port==1) {
      tell_object(who,
       "You enter the swirling cloud and you are where you want to be.\n");
      return 1;
    }
    else {
      tell_object(who,"Enter what?!?\n");
      return 1;
    }
 }
}
