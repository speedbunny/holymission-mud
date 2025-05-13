/* Room you slide into from tower 6 */

inherit "room/room";
#define LS "/players/kbl/objs/lizard_skin"

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    short_desc = "Escape chute in tower 6";
     long_desc = "You enter a room full of straw. The walls are stone\n"+
                 "blocks tightly placed together. A red arrow on the\n"+
                 "east wall reads: PRESS here to exit. The walls glow\n"+
                 "green from some magic spell.\n";
     dest_dir = ({"players/kbl/dungeon/dun3","press",
                  "players/kbl/dungeon/dun3","exit"});
     items = ({"straw","Moldly straw thats been here for ages. Still its\n"+
                       "in good shape considering the straws obvious age",
               "stone","Finest stonework",
               "stonework","looking closer you see the initials MEC inscribed"+
                           "into some of the stones",
               "walls","Made of stone blocks",
               "blocks","Finest stonework",
               "arrow","The arrow is painted red and reads: Press here to exit",
               "red arrow","Its painted with pigs blood"});
    transfer(clone_object(LS),this_object());
    smell = "Musty and moldy straw";
    property = "no_steal";
  }
}

init()
{
  ::init();
  command("sneeze",this_player());
}
