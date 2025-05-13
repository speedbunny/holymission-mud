inherit "room/room";
reset (arg) {
if (arg) return;
set_light(2);
short_desc = "c22 Southwest corner";
long_desc =  
       "The southwest corner of the castle.\n"
    +  "The brown carpet ends here, and a black one picks up.\n"
    +  "A door in the southwest corner of the room.\n"
    +  "There is a small window in the south and west wall.\n";
items = ({
"floor","The floor is made of red stone",
"ceiling","The ceiling is made of white stone",
"wall","The walls are made of grey stone.  Small windows in the south and west walls",
"doorway","A wood-framed doorway leading southwest",
"carpet","A brown carpet ending, and a black one ending.\nThey overlap each other",
"window","You see a forest to the west, and a forest to the south",
});
dest_dir = ({
"players/jake/goblin/castle/c21","north",
"players/jake/goblin/castle/c23","east",
"players/jake/goblin/castle/c22a","southwest",
});
}
