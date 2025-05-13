inherit "room/room";
#define PM "/players/meecham/"
reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc="Entrance to Coldrik's realm";
    long_desc=
      "You have entered the domain of the mighty Coldrik.  You stop and\n\
survey your surroundings.  A great bridge spans a huge chasm a short\n\
distance to the north.  A slim path appears to branch off to the east and\n\
west possibly around the bridge.  You can travel back to the south or continue\n\
north towards the bridge.\n";
    items=({
      "bridge","A great bridge starts further north",
      "path","There appears to be slim paths leading around the chasm",
      "chasm","A yawning chasm stretches far to the north",
    });
    dest_dir=({
      PM+"col_realm/bridge","north",
    });
  }
}
 
