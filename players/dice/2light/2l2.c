inherit "room/room";
query_no_teleport() { return 1; }
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Village green";
    no_castle_flag = 1;
    long_desc = 
	"You are at an open green place south of the village church.\n" +
            "You can see a road further to the east. To the west you see\n" +
            "some strange things happening, but you are too far away\n"+
            "to see what really is happening\n";
    dest_dir = ({
                 "players/dice/2light/2lchurch","north",
                 "players/dice/2light/2l3","west",
                 "players/dice/2light/2l7","east"
                 });
          items = ({
              "things","Strange things happening to the far west",
              "road","A strange road, it seems to be leading nowhere",
              "church","It seems like a normal church",
              "place","A green open place",
              "green place","A green open place south of the church",
              "open place","A green open place south of the church",
              "green open place","A green open place south of the church"
              });

    smell = "The air smells weird here.";
}

