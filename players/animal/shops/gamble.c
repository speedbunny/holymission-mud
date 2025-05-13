inherit "room/room";
 
reset(arg) {
     extra_reset();
    if (arg) return;
 
    ::reset(arg);
    set_light(1);
    set_outdoors(1);
    short_desc = "Gambling hall";
    no_castle_flag = 0;
    long_desc = "Gambling Hall\n\n" +
          "   You are in a smoky and scum-filled gambling hall.\n"
        + "   Many shady characters frequent this place. Here\n"
        + "   you can play poker or roulette.\n\n"; 
    dest_dir = 
        ({ 
        "players/animal/shops/pub", "south", 
        }); 
} 
 
query_light() { 
    return 1;  
} 
 
query_outdoorness() {  return 4; }
 
extra_reset() {
     if(!present("table",this_object()))
     move_object(clone_object("players/animal/obj/table"),this_object());
     if(!present("poker machine",this_object()))
     move_object(clone_object("players/animal/obj/poker"),this_object());
}
