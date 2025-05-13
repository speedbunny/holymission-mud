inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_light(1);
    short_desc="GUILD_ROOM";
    long_desc="GUILD_ROOM for mages.\n Pretzel, Saffrin and I run this place\n";
    dest_dir=({
      "/players/saffrin/workroom","SAFFY",
      "/players/pretzel/workroom","PRETZ",
      "/players/waldo/workroom","WALLY",
      "/players/waldo/guild/room","new_guild",
             });

    }
  }

init()
{
  ::init();
  return 1;
  }
