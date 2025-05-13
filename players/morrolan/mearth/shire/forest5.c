inherit "/room/room";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "In the Hobbit forest";
    long_desc =
    "There are many things that make you nervous here. For one thing,\n"+
    "there is the silence, second is the total lack of motion, and\n"+
    "finally, the trees. It's not a question of what's wrong with them\n"+
    "but what's right with them... While you feel that there is no evil\n"+
    "in this place, you feel that there is no good too.\n";

    dest_dir = ({
      "/players/colossus/mearth/shire/forest2", "north",
      "/players/colossus/mearth/shire/forest4", "east",
  /*   "players/texas/rooms/forest/f_01", "west",  Texas is Appr  */
      "/players/colossus/mearth/shire/forest8", "south",
    });

    items = ({
      "trees", "You just cannot place it but the trees are definitely odd",
    });

}
