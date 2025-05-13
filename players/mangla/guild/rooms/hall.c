inherit "/room/room";

void reset(int arg) {
  if(!arg) {

    set_light(1); 
    short_desc="A short hallway entering the Jedi guild";
    long_desc="This is a pure white room with light illuminating from the "
               "floor and ceiling.  It feels peaceful and calm here.  To "
               "the north you hear glasses clinking and people talking.  To "
               "the east is the famous Sanctum Servery.  You feel the force "
               "is strong in this place.\n";
    dest_dir=({
              "/players/mangla/guild/room","south",
              "/players/mangla/guild/rooms/bar","north",
              "/players/mangla/guild/rooms/food","east",
     });
  }
  ::reset(arg);
  replace_program("/room/room");
}
