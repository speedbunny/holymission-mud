inherit "room/room";

#define TO (this_object())

reset(arg) {
    if(!arg) {

    short_desc="Cage of Death";

    long_desc="You have entered Jewel's testing cage where she maims and \n" +
              "mutilates perspective creatures for her area, or a wayward player.\n" +
              "Fear for your life.\n";

    set_light(1);




dest_dir= ({"players/jewel/workroom","out",
            "players/jewel/rooms/amazon","ama"});
    }
/*
  if(!monster || !living(monster)) {
    monster=clone_object("/players/mangla/monsters/ogre");
    move_object(monster,TO);
    weapon=clone_object("/players/mangla/weapons/og_weap");
    transfer(weapon,monster);
    command("wield club",monster);
  }
*/
}


init()
{
  ::init();
}
