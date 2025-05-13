inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Marble Hallway";
    long_desc =
"This well lit hall is made of marble, beautifuly carved and\n"+
"shined. It is very clean and you almost can't tell your\n"+
"underground at all.\n";
    dest_dir = ({
"players/ted/frost/guard", "northeast",
"players/ted/frost/entrance", "northwest"
    });
  }
}
