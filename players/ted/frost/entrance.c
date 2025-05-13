inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Marble Hallway";
    long_desc =
"This well lit hallway is made of marble, beautifuly carved\n"+
"and highly polished. It is very clean and bright, you almost\n"+
"can't tell you're underground at all.\n";
    dest_dir = ({
"players/ted/frost/cave17", "southeast",
"players/ted/frost/cave10", "southwest",
"players/ted/frost/study", "north"
    });
  }
}
