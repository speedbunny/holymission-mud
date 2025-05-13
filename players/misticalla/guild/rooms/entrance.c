inherit "room/room";


reset(arg) {

     short_desc="Entrance of an abbey";

    long_desc=
       "You have arrived at the entrance of the abbey where the "+
       "monks have their guild. From here you can see the courtyard "+
       "ahead of you. The engagement chapel lies to the east and "+
       "the guild room of the monks lies to the west. "+
       "You hear chanting in the distance and wonder where it is coming "+ 
       "from.\n";
   
    set_light(1);

    items=({"nothing","You see alot of nothing in here",
          });

    property=({ "no_teleport" });   


   dest_dir=({
	"players/misticalla/guild/rooms/guildroom","west",
	"players/misticalla/guild/rooms/chapel","east",
	"players/misticalla/guild/rooms/courtyard1","north",
             });

 
}
init() {
    ::init();
    add_action("check_move","north");
}
 
check_move() {
    if (this_player()->query_guild() !=7) {
        write("That room is for monk guild members only!!!\n");
        say(this_player()->query_name()+" tried to go "+query_verb()+"!\n");
        return 1;
    }
    else { return 0; }
}

