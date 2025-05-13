inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    property = "no_teleport";
    short_desc = "Treetop";
    no_castle_flag = 1;
    long_desc=
    "You are sitting on top of a tree.\n"+
    "The green leaves are waving in the wind.\n"+
    "It's really cold up here.\n";
    items = ({
      "plain","A large plain at the bottom of the tree",
      "top","The top of a tree", 
      "leaf","A green leaf",
      "tree","A single tree, standing in the middle of a plain",
      "leaves","Normal leaves",
      "green leaves","Normal green leaves",
      "cold","Brrrr, you're shivering",
    });
    dest_dir = ({ "players/dice/quest/q_entr","down" });

    smell = "The cold air is torturing your nose.";
}
