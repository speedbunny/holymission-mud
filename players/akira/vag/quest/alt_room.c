inherit "room/room";

/* this room is the alternate start room... in the exit to leads to
this room... only players that have not done the quest or/and the area
is locked. because someone is doing the quest can enter this room... else
they should go to ther normal room */


void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Alternate Reality";
    long_desc =
    "You have entered a another part of the 4th, but you sense\n"+
    "something wrong here.  Like something is wrong with the\n"+
    "space/time continum and like you feel that your destined to\n"+
    "to correct it.\n"+
    "\n"+
    "\n";

    dest_dir = ({
      "/players/akira/vag/quest/crossroads", "east",
    });

    property = ({ "vag_quest", "no_teleport" });

}
