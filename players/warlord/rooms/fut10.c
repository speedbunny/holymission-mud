

inherit "room/room";
object o1;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/monsters/sorclord");
move_object(o1,this_object());}
    if (arg) return;

    set_light(1);

    short_desc = "Sorceror Lord's Private chambers";
    no_castle_flag = 0;
    long_desc = 
       "You have not heeded any warnings given and have entered a forbidden\n"
      +"room. This room is the the private chambers of the Sorceror Lord\n"
      +"The room is black except for a large chair in the center where he sits.\n";
    items = ({
           "chair","The chair is large and encrusted with great gems.",
           });
    dest_dir = 
        ({
        "players/warlord/rooms/fut7", "north",
        "players/warlord/rooms/fut9", "northeast",
        "players/warlord/rooms/fut8", "northwest",
        });
}
