/*Room description corrected by Silas*/
inherit "room/room";
 
int passage;
 
#define me capitalize(this_player()->query_name())
 
reset(arg) {
    if(arg) return;
    passage=0;
    set_light(1);
#if 0
    set_outdoors(4);
#endif
    short_desc = "Ring of trees";
    long_desc = "Ring of trees.\n" +
         "\n" +
         "     You have came to a clearing in the forest. There is a\n" +
         "     small ring of trees surrounding the clearing to the west.\n" +
         "     You do not feel scared but the trees seem to emanate an\n" +
         "     aura of some hidden power.\n" +
         "\n";
    dest_dir = ({
        "/players/animal/light/light10", "east"
    });
    items = ({
        "squirrels","Many small squirrels run around here",
    });
    return;
}
 
long()  {
        ::long();
    if(passage) {
    write("\n");
    write("There is now a secret path leading west.\n");
     }
}
 
query_light() {
    return 1;
}
 
init() {
          ::init();
          add_action("_west","west");
          add_action("search","search");
}
 
 
search(str) {
    if (!str) str = "room";
    if (str == "room") {
          if(random(100) <35) {
       write("You search through the trees and find a path leading west.\n");
        say(me + " finds a hidden path leading west.\n");
        passage = 1;
        call_out("refresh", 6);
        return 1;
    }
     write("You find nothing unusual.\n");
     say(me + " searches the room.\n");
     return 1;
     }
}
 
_west() {
   if (passage) {
       call_other(this_player(),"move_player","west#players/animal/light/light22");
       return 1;
   }
   return 0;
}
 
refresh() {
     say("The trees cover the passage back up again.\n");
     passage = 0;
}
 
