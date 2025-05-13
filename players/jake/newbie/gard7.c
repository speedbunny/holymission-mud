/* Recoded by Kryll on 2/20/97 to fix berries and also to make it legible */
inherit "room/room";
 
void reset(int arg) {
  set_light(3);
  short_desc = "gard7"; 
  long_desc =
    "You have entered the land of the smurfs. "+
    "There are mushroom houses to the east and to the south. "+
    "To the north you hear chirping sounds.\n";
  items = ({
    "house","A cute little mushroom house with smoke coming from the chimney"
  });
  dest_dir = ({
    "players/jake/newbie/gard8","west",
    "players/jake/newbie/smurf1","south",
    "players/jake/newbie/smurf2","east",
  });
  clone_list=({
    1,5,"smurf","obj/monster", ({
      "set_name","smurf",
      "set_short","smurf",
      "set_long","A little blue smurf.\n He has white pants and a white hat on.\
n",
      "set_level",3,
      "set_al",200,
      "add_money",75,
    }),
    -1,1,"berry","/players/jake/newbie/stuff/berries",0,
  });
  ::reset();
  replace_program("/room/room");
}

