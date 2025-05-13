inherit "room/room";
reset (arg) {
if (arg) return;
set_light(2);
short_desc = "center hallway";
long_desc = 
         "A grand looking hallway.\n"
           + "A large chandelier hangs from the ceiling.\n"
           + "There are tapestries hanging from the walls, and\na bear-skin rug on the floor.\n";
items = ({
 "floor","It is made of red stone, and has a bear-skin rug on it",
 "ceiling","Pearl white stone with a crystal chandelier hanging from it",
 "chandelier","A crystal chandeleir",
 "tapestries","Beautiful cloth wall-hangings with pictures of goblin wars, and dragons on them",
 "rug","The skin of a poor bear",
 "wall","Grey stone walls",
});
dest_dir = ({
 "players/jake/goblin/castle/h2","south",
  "players/jake/goblin/castle/r3","east",
 "players/jake/goblin/castle/h4","north",
});
}
