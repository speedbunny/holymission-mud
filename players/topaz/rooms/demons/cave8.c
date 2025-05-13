inherit "room/room";

#include "/players/topaz/defs.h"

object topazdemon;
int found;
reset(arg) {
  found=0;
  if(!topazdemon) {
    move_object(topazdemon=clone_object(MDEMONS + "guard2"),TO);
}
  if(arg) return;

     short_desc = "Demon lounge";
     long_desc = "You walk into the room and are amazed.\n" +
                 "It looks pretty nice in here.  There are some\n" +
                 "paintings on the walls and somehow music is playing.\n" +
                 "The music sounds strange, yet soothing.  There is a\n" +
                 "beautiful little chest on a shelf on the other side of\n" +
                 "the room.\n" +
                 "There are comfortable looking couches and chairs all\n" +
                 "over the room.  There is a table in the middle of the\n" +
                 "room which is obviously used for playing games, although\n" +
                 "you have no idea what kind of games demons would play.\n" +
                 "There is a fire burning in a little fireplace in one\n" +
                 "corner of the room.\n";

      dest_dir = ({"players/topaz/rooms/demons/cave9","west",
 
                     });

     items =({"cave","This is a place where the demons come to relax",
              "paintings","Ugh!  They show people being eaten alive!  You feel sick",
              "chest","It is open.  Perhaps you could search it",
              "little chest","It is open.  Perhaps you could search it",
              "table","It is covered with weird looking gamepieces",
              "walls","The walls are covered with blood",
              "couches","Look like they would be comfortable to sit or lie down on",
              "chairs","They look very comfortable",
              "fire","It gives off a cheery glow and comforting heat",
              "fireplace","A small fireplace with a cute little fire in it",
              "small table","Only the chest is on it",
              "gamepieces","They are really strange looking",
              });
       set_light (1);
        property = ({"has_fire"});
        smell = "You smell the smoke from the fire in the fireplace.";
}
init(){
  ::init();

        add_action("search", "search");
        }

search(str) {
     object torch;
     if(!id(str)) {
     write("Search what?\n");
     return 1;
}
    if(present("topazdemon")) {
    write("The demon won't let you do that!\n");
    return 1;
}
    if((str=="chest"||str=="little chest")  && !found) {
    write("You search the chest and find a torch!\n");
    say(this_player()->query_name() + " searches the chest and finds something.\n");
move_object(torch=clone_object("/obj/torch"),this_object());
    found=1;
    return 1; }
}
