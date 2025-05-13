inherit "room/room";
#include "/players/izekiel/defs.h"
#define RN TP->query_real_name()
int shield;

reset(arg){
  if(!arg){
    
    set_light(1);
    short_desc="Ize's Workroom";

long_desc=
"  You have entered Izekiel's private hell. The room is surrounded by a \n"+
"thin veil of flame. The smell of brimstone is heavy here. To your left, \n"+
"you see a small desk with a pile of papers on it, as well as a dusty \n"+
"bible. There is a small sign on the wall. Maybe you can 'read' it.\n";

    items=({
"veil","A thin veil of flame, which envelops the room",
"flame","A thin veil of flame, which envelops the room",
"desk","A small desk, with a clutter of papers on it",
"clutter","An unorganized heap of paper",
"paper","One of many documents lying about. What a mess",
"papers","A pile of documents not yet examined by Mr. Izekiel",
"bible","Now why the hell is that in here??? =D",
"sign","Maybe you could 'read' it, genius"
    });
    dest_dir=({
      "room/church","church",
      "room/post","post",
      "players/gareth/workroom","gareth"
    });

    property=({
      "no_sneak","no_steal"
    });

 }
}

init(){
  ::init();
  AA("set_shield","shield");
  AA("expel","expel");
  AA("_smell","smell");
  AA("_read","read");
  check();
  }

set_shield(str){
  if((RN!="izekiel")&&(RN!="ezekiel")&&(RN!="mangla")) return;
  if(!str){
   write("The searing flames of protection are "+ shield + ".\n");
   return;

  }

  if(str == "on"){
write("You call up fiery protection engulfing the perimeter of this room!\n");
   say("Flames leap to life, surrounding this room!\n");
   shield=1;
   return 1;
  }

  if(str == "off"){
   write("You quench the flames surrounding this room.\n");
   say("It is suddenly much cooler, as the flames are quenched.\n");
   shield=0;
   return 1;
  }
}

check(){
  if(shield && (RN!="izekiel") && (RN!="ezekiel") && (RN!="mangla")){
   write("Intense flames prevent you from entering at this time.\n");
   say("The searing flames prevented "+ TPN +" from entering.\n");
   MO(TP,"room/church");
  }
  return 1;
}


_smell(str){
  if(!str){
   write("What do you want to smell?\n");
   return 1;
  }
  if(str == "brimstone"){
   write("You sear your nostrils as you attempt to smell the brimstone!\n");
   return 1;
  }
}


_read(str){
  if(!str){
   write("What do you want to read?\n");
   return 1;
  }
  if(str == "sign"){
   write("The sign reads:\n"+
         "\n'Confucius say:\n"+
         "Man who sleep with itchy butt, wake up with smelly finger.'\n");
   return 1;
  }
}

expel(arg){
  object player;
  if((RN!="izekiel") && (RN!="ezekiel") && (RN!="mangla")) return;
  if(!arg){
   write("Who do you want to expel?\n");
   return 1;
  }
  player = present (arg,TO);
  if(!player){
   write("That person is not present.\n");
   return 1;
  }
  write("You kick "+ TPN +" out of the room.\n");
  player->move_player("to the church#/room/church");
  tell_room(TO,TPN + "got expelled from the room.\n");
  return 1;
}
