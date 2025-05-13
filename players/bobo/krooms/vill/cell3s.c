inherit "room/room";
#include "/players/mangla/defs.h" 
object prisoner;
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A prison cell";
    long_desc="You're in a cell in the prison of Red Rock Junction.\n"+
      "At the cell walls there are some lines of chalk.\n"+
      "There is a plank bed standing in a corner, the window of the cell\n"+
      "is grated.\n";  

    items=({
    "wall","The is a picture of a nice lady at one wall",
    "picture","Do you think I got nothing else to do than write this silly items",
    "walls","Really dirty walls",
    "lines","You can't count them",
    "bed","A simple plank bed",
    "plank bed","A bed like in every prison",
    "window","A grating is in front of the window and bars the way into liberty",
    });
    prisoner=clone_object("obj/monster");
    prisoner->set_name("troll");
    prisoner->set_alias("large troll");
    prisoner->set_level(15);
    prisoner->set_size(3);
    prisoner->set_race("troll");
    prisoner->set_al(-350);
    prisoner->set_hp(200);
    prisoner->set_short("A large troll");
    prisoner->set_long("He doesn't seem to be here for a long time.\n");
 /*   prisoner->load_chat(({"","",""})); */
    move_object(prisoner,this_object());

}
 
init() {
::init();
  add_action("north","north");
  add_action("search","search");
}
 
north() {
  if("players/bobo/rooms/vill/guardroom"->open(6))
    TP-MOVEP("north#players/bobo/krooms/vill/corridor3");
  else {
    write("A grating bars your way!\n");
    say(this_player()->query_name()+" tries to go north, but fails.\n");
    }
  return 1;
}
 
search(str) {
  if(str!="bed" && str!="plank bed") return;
  say(this_player()->query_name()+" searches in the bed.\n");
  write("You don't believe your eyes. This bed is really clean.\n");
  return 1;
}

