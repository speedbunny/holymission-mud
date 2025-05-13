// /players/jewel/rooms/amazon  Coded by Jewel of Holy Mission May 10,1995
#include "/players/jewel/defs.h"
#include "/obj/lw.h"
#define fail(x)     return (int)notify_fail(x)
 
inherit "room/room";
 
string *guests;
 
int _allow(string str) {
  string guest;
  object ob;
  if(TP->query_gender()!=2 || TP->query_level()<20) return 0;
  if(!str) fail("Syntax: allow <name> to speak.\n");
  if(!sscanf(str,"%s to speak",guest)) fail("Allow what?\n");
  if(!ob=present(guest)) fail(CAP(guest+" isn't here right now though.\n"));
  if(member_array(CAP(ob->RNAME),guests)!=-1) {
    write(ob->query_name()+" can already speak.\n");
    return 1;
  }
  write("You allow "+ob->query_name()+" to speak.\n");
  TELL(ob,lw("Amazon "+CAP(TP->RNAME)+" allows you to speak.\n"));
  guests+=({CAP(ob->RNAME)});
  return 1;
}
 
int _deny(string str) {
  string guest;
  object ob;
  if(TP->query_gender()!=2 || TP->query_level()<20) return 0;
  if(!str) fail("Syntax: deny <name> from speaking.\n");
  if(!sscanf(str,"%s from speaking",guest)) fail("Deny what?\n");
  if(!ob=present(guest)) fail(CAP(guest+" isn't here right now though.\n"));
  if(member_array(CAP(ob->RNAME),guests)==-1) {
    write(ob->query_name()+" can't speak.\n");
    return 1;
  }
  write("You deny "+ob->query_name()+" from speaking.\n");
  TELL(ob,lw("Amazon "+CAP(TP->RNAME)+" denies you from speaking.\n"));
  guests-=({CAP(ob->RNAME)});
  return 1;
}
 
status _list(string str) {
  int i;
  string list;
  if(TP->query_gender()!=2 || TP->query_level()<20) return 0;
  if(!str || str!="allowed") fail("Syntax: list allowed.\n");
  if(!sizeof(guests)) {
    write("*CACKLE* There are no free men!\n");
    return 1;
  }
  else {
    list="The list of free men includes:\n";
    for(i=0;i<sizeof(guests);i++) {
      list+="\t"+guests[i]+"\n";
    }
    write(list);
    return 1;
  }
}
 
int _say(string str) {
  if(!str) return 0;
  if(TP->query_gender()==2) return 0;
  if(member_array(CAP(TP->RNAME),guests)!=-1) return 0;
  write("You try to speak, but all that comes out is: Yes Mistress.\n");
  say(lw(TP->query_name()+" tries to speak, but all that comes out is: Yes"
                         +" Mistress.\n"));
  return 1;
}
 
int _emote(string str) {
  if(!str) return 0;
  if(TP->query_gender()==2) return 0;
  if(member_array(CAP(TP->RNAME),guests)!=-1) return 0;
  writelw("You try to emote, but instead you fall on your knees in worship of"
         +" the AMAZONS!\n");
  say(lw(TP->query_name()+" tries to emote, but instead "+TP->PRO
                         +" falls on "+TP->POS
                         +" knees in worship of the AMAZONS!\n"));
  return 1;
}
 
void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc="AMAZON room";
    long_desc="You have entered the realm of the AMAZON. This is where true"
             +" AMAZONS come to rest, be waited on hand and foot by men"
             +" slaves, and to unwind from the everyday stresses of AMAZON"
             +" life. About you are privileged slave men who are allowed out"
             +" of the cages in order to serve you. There are cages to the"
             +" east. To the west you see a board where the mighty AMAZONS"
             +" post their thoughts and triumphs.\n";
    dest_dir=({
      "/players/apollo/area2/rooms/entrance","down",
      "/players/jewel/rooms/www","east"
    });
    items=({
      "floor","It is a dirt floor. You can see drops of blood spilled by"
             +" slaves",
      "walls","The walls are made of rock and cool to the touch",
      "wall","The wall is made of rock and cool to the touch",
      "cage","A cage with strong wrought-ironed bars. You see several"
            +" starving yet strangely happy looking men slaves",
      "cages","To the east are several cages filled with men slaves",
    });
    smell="This room smells of the blood and sweat of men slaves.";
    property=({"no_steal","no_fight","no_teleport","no_sneak"});
    guests=({
    });
    transfer(clone_object("/boards/private_boards/jewel_amazon"),this_object());
  }
}
 
void init() {
  ::init();
if(TP->query_gender()!=2) write("A feeling of servitude overcomes you.\n\n");
  add_action("_allow","allow");
  add_action("_deny", "deny");
  add_action("_list", "list");
  add_action("_say",  "say");
  add_action("_say"); add_xverb("'");
  add_action("_emote","me");
  add_action("_emote","emote");
}

