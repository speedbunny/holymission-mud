inherit "/room/room";
object guard, door;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Main hall of the Shire guard station";
    long_desc=
    "Here you stand at the main chamber of the Shire shiriff station.\n"+
    "Due to the large number of crimes and violence in the city the\n"+
    "shiriff station is actually one of the busiest places of the Shire.\n"+
    "The main hall is a 40' X 40' in dimension. Various doors lead to\n"+
    "different rooms.\n";
    dest_dir = ({
      "/players/colossus/mearth/shire/quest/hall5", "southeast",
      "/players/colossus/mearth/shire/quest/hall1", "northwest",
      "/players/colossus/mearth/shire/quest/hall2", "west",
      "/players/colossus/mearth/shire/sheriff2", "north",
      "/players/colossus/mearth/shire/quest/hall3", "southwest",
      "/players/colossus/mearth/shire/quest/hall4", "south",
    });
    items = ({
      "doors", "Doors that lead to different rooms",
      "hall", "The hall is a structure 40' X 40' in dimension",
    });
}
