inherit "room/room";
object goblin;
reset (arg) {
goblin=clone_object("players/jake/goblin/castle/monsters/drunkard"),
move_object(goblin,this_object());
if (arg) return;
set_light(2);
short_desc = "ballroom closet";
long_desc =
     "A small and cramped closet.\n"
  +  "The room is empty except for a few dust balls on the floor.\n"
  +  "And this drunken fellow here.\n";
items = ({
 "floor","A small red stone floor covered with dust",
 "ceiling","A large white stone makes the ceiling",
 "wall","Barren grey stone walls",
 "dust","Dust balls",
});
dest_dir = ({
 "players/jake/goblin/castle/h5","west",
});
}
