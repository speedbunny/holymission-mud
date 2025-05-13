// Code originally by Sherman of Holy Mission //
// re-coded and enhanced by Jewel of Holy Mission May 1996 //

/* read function added because players got confused by the response
   of Cashimor's locket to 'read inscription'. Uglymouth 930905 */

inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="A grave with a huge stone.";
    long_desc=
        "You see a grave with a huge gravestone.\n"+
         "There is an inscription on it.\n";
    items=({
        "grave","This is a grave with a huge gravestone",
        "stone","A very large, heavy gravestone",
        "gravestone","A very large, heavy gravestone",
        "inscription","It reads: Here rests Patience not in peace because he\n"+
        "didn't bring back the ninjas"
          });
    dest_dir=({
        "/players/jewel/quest/grave1","south",
        "/players/jewel/quest/grave5","east",
        "/players/jewel/quest/grave7","north"
             });
}

init() {
     ::init();
     add_action("read","read");
     }

read(str) {
     if(str!="inscription") return;
     write("It reads: Here rests Patience not in peace because he\n"
         + "didn't bring back the ninjas.\n");
     return 1;
     }

dig() {
    write("You find nothing.\n");
    say(this_player()->query_name() +" digs and finds nothing.\n");
    return(1);
}

