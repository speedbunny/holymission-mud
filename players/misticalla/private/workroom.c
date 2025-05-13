#include "/players/misticalla/defs.h"
inherit "room/room";


int shield;

reset(int arg) {

  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc="Misticalla's Workroom";
  long_desc=
              "                 Hey, aren't you lucky to be here!\n"
              "                   Bow to the great Misticalla!\n"
              "    \n"
              "You see only a few things here. There is a computer "+
              "and a comfortable chair. She has a dartboard on the wall "+
              "and some pictures. There is a stereo on a table in the "+
              "corner where she plays her favorite CD's.\n"        
              "    \n";

  dest_dir=({                           
              "/room/adv_guild", "adv",
              "/players/apollo/workroom","apollo",
              "/players/gareth/workroom", "carlos",
              "/room/church", "church",
              "/players/morrolan/workroom","cutie",
              "/players/warlord/guild/room", "monks",
              "/room/post", "post",
              "/room/prison","jail",
              "/room/purgatory","purg",
              "/players/jewel/workroom","amazon",
              "/players/tuppence/workroom","tupper",
              "/players/beelzebub/workroom","cleaner",
              "/players/beezlebub/workroom","rob",
              "/players/matt/newworld/city/rooms/votebooth","vote",
              "/players/misticalla/rooms/test", "test",
              "/players/sauron/workroom","sauron",
              "/players/silas/workroom", "tom",
              "/players/exos/workroom","exos",
              "/players/mangla/workroom.","teflon",
              "/players/misticalla/area/rooms/vine01", "vine",
              "/players/misticalla/rooms/deck","deck",
              "/players/misticalla/guild/rooms/entrance","new",
           });

  items=({
     "dartboard","It has pictures of Pretzel on it",
     "computer","A slow but working 486DX",
     "chair","It is comfy and blue, well worn",
     "stereo","Imported, an AIWA CD3 with 3way twin duct bass reflex speakers",
     "cds","There are 150 at least, take your pick",
        });

  property=({
              "no_steal",
              "no_snoop",
              "no_teleport",
              "no_assassinate",
              "has_fire",
            });
}

init() {

  ::init();
  this_player()->set_smell("You smell like Misticalla's Chloe parfume !!!"); 
  add_action("set_shield","shield");
  check();
}

int set_shield(string str) {

  if (RN != "misticalla") {
    say(RN+" attempted to raise the shield! You laugh as "+RN+
        " disintegrates!!\n");
    write("You are a fool for attempting to raise Misticalla's shield.\n");
    write("Enjoy logging in again!\n");
    destruct(TP);
    return 1;
  }
  if (!str) {
    if (shield == 1) {
      write("You feel the shield is up.\n");
      return 1;
    }
    write("You feel the shield is down.\n");
    return 1;
  }

  if (str == "on") {
    shield = 1;
    say("Misticalla bumps the wall with her hip and a shield raises.\n");
    write("You skillfully bump the wall with your hip, raising the shield.\n");
    return 1;
  }
  shield = 0;
  say("Misticalla kicks the wall and the shield lowers.\n");
  write("You kick the wall and the shield lowers.\n");
  return 1;

}

int check() {

   if(RN !="misticalla") {
       write("As you enter you are forced down on your knees to worship "+
              "Sage Misticalla. You are humbled by her presence.\n");
       say(TPN+" falls to the ground in worship, upon entering the humble "+
             "workroom of Sage Misticalla.\n");
   }
   if(RN == "pretzel") {
      write("You were supposed to ask first, go back to your workroom!\n");
      say(TPN+" was disrespectful and attempted to enter your workroom"+
              " without asking!\n"); 
      move_object(this_player(),"/players/pretzel/workroom");

   }         
   if (shield && (RN != "misticalla")) {
      write("How dare you try to enter Misticalla's workroom!!\n");
      write("Get back to your own!!\n");
      move_object(TP,"/players/"+RN+"/workroom");
      if (find_living("misticalla"))
        tell_object(find_living("misticalla"), RN+" attempted to enter "+
                                                "your workroom!\n");
  }
  return 1;
}
