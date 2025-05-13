#include "/players/gareth/define.h"
#define RN TP->query_real_name()
inherit "/room/room";
int shield;
string who;

int i;
reset(arg) {
   if (!arg) {
   set_light(1);
   short_desc= "Gareth's workroom";
   long_desc= 
      "             You are now in Wonderland!          \n\n"+
      "This hexagonal room is decorated with mosiac tiles. \n"+
      "The mosiac covers the entire room, walls the floor and \n"+
      "the ceiling. One scene shows a man in white armour riding\n" +
      "a white dragon. A young woman wearing a golden crown is \n" +
      "sitting in front of the man.  Another scene shows elves \n" +
      "playing in some woods while a white dragon watches over \n" +
      "them.  On another wall, is a scene showing a bright pool \n" +
      "of water. Several mermaids swim and frolic in the water. \n" +
      "The design on the ceiling shows the crowned maiden, the \n" +
      "man in white armour, and the white dragon asleep in a \n" +
      "beautiful meadow. There is a gleam that orginates from a\n"+
      "statue located in one of the corners of the room.\n";
   items = ({
              "statue", "A gold Statue of Gareth, rather handsome too",
   });
   dest_dir =({
     "room/church","church",
     "room/post","post",
     "players/colossus/workroom","colossus",
     "players/airborne/workroom","air",
     "players/gareth/cell","cell",
     "players/gareth/think","think",
     "players/gareth/room","room",
     "players/gareth/evil/cave/entcave","area",
     "players/mangla/workroom","mangla",
     "players/talos/workroom","talos",
     "players/apollo/workroom","apollo",
             });
   property =({
     "no_sneak","no_steal","no_invisible","no_camoflage",
             });
   }

}

init() {
  ::init();
  AA("set_shield", "shield");
  AA("expel", "expel");
  check();
  }

set_shield(str) {
  if((RN !="gareth") && (RN !="balan") && (RN !="mangla")) return;
  if(!str) {
    write("Defense field is currently " + shield +".\n");
    return;
  }

if(str == "on") {
   write("You press a button and activate a Defensive Perimeter.\n");
   say ("Gareth activates a defensive perimeter around the room.\n");
   shield=1;
   return 1;
}

if(str == "off") {
   write("You lower the power to the shields.\n");
   say ("Gareth lowers the power to the defensive barriers.\n");
   shield=0;
   return 1;
}
}

check() {
  if(shield && (RN !="gareth") && (RN !="balan") && (RN !="mangla")) {
  write("A fleet of battle cruisers with engery shields prevents you from\n"+
        "breaking through the other side - Adios.\n");
  say(TPN + " tried to enter but was blocked by the USS ENTERPRISE.\n");
  MO(TP, "/players/gareth/think");
  }
  return 1;
}

expel(arg) {
  object player;
  if((RN !="gareth") && (RN !="balan") && (RN !="mangla")) return;
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
