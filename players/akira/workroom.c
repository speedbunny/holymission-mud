#define NAME "akira"
/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */
inherit "room/room";
#include "/players/akira/define.h"
#define RN TP->query_real_name()
int shield;
string who;

int i;
#define CNAME   capitalize(NAME)

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */
reset(arg) {
    /* do the following block only the first time !! */
    if(!arg) {
        /* first we need some light in here */
        set_light(1);

        /* then lets set a short description in case we are in brief-mode */
        short_desc= "Mt. Olympus";

        /* now the long standard room description */
        /* change this to fit your style *grin* */
        long_desc=
        "This is the Great Mt. Olympus, home of the Gods! You are"+
        "standing in the Grand Hall of a huge temple. All around"+
        "you are huge pillars reaching high into the shy. From "+
        "here you can look down on the world of Holy Mission.\n";
      

        /* we need some exits too ... lets set the destination directions */
        dest_dir=({
            "room/post", "post",
	    "room/church", "church",
            "room/adv_guild", "guild", 
                 });

        /* here could follow some item descriptions, like ...*/
        items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
              });
        /* Properties can be set like the following */
        property = ({
                     "no_teleport","no_sneak","no_steal",
                    });
        /* Smell is set like this... */
        smell = "This place is a bit dusty";
    }
}

init()
{
  ::init();
 AA("set_shield", "shield");
  AA("expel", "expel");
  check();
  }

set_shield(str) {
if((RN !="akira") && (RN !="omnicronus") && (RN !="trout")) return;
  if(!str) {
    write("Defense field is currently " + shield +".\n");
    return;
 }

if(str == "on") {
write("YOU WAVE YOUR HAND, BLOCKING MORTALS FROM THIS REALM!\n");
say ("Akira activates a shield around this realm!\n");
  shield=1;
   return 1;
}

if(str == "off") {
write("You allow mortals back into the realm.\n");
say("Akira lowers the barriers of his realm.\n");
   shield=0;
   return 1;
}
}

check() {
 if(shield && (RN !="akira") && (RN !="omnicronus")&& (RN !="mangla")&&(RN !="trout")){
write("YOU ARE NOT WELCOME ON MT. OLYMPUS. GO BACK TO THY OWN REALM!\n");
say(TPN + " tried to enter Mt. Olympus, but was blocked by Akira.\n");
MO(TP, "/players/gareth/think");
  }
  return 1;
}

expel(arg) {
  object player;
if((RN !="akira") && (RN !="omnicronus")&& (RN !="mangla")&&(RN !="trout"))
return;
if(!arg) {
    write("Who do you want to expel?\n");
   return 1;
    }
 player = present (arg, TO);
  if(!player) {
 write("That person is not here.\n");
    return 1;
  }
  write("You kick " + TPN + " out of your room.\n");
  player->move_player ("to the church#/room/church");
 tell_room(TO, TPN + "got transported else where.\n");
 return 1;
  }
