inherit "room/room";

object monster;

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "Castle Opening";
  long_desc = "To the north is Ace's Castle.  Beware, only the strong\n"+
              "will survive in such an evil place.\n";
  monster = clone_object("/players/ace/castle/monsters/squirrel.c");
  move_object(monster, this_object());
dest_dir = ({
             "/players/ace/castle/rooms/open.c", "south",
             "/players/ace/castle/rooms/moat.c", "north",
             "/players/ace/castle/rooms/open3.c", "east",
             "/players/ace/castle/rooms/open5.c", "west" 
             });
}
