inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave branches here to lead northwest and northeast.\n"+
"The southern part of the cave has more ice and snow than\n"+
"the rest of the cave.\n";
    dest_dir = ({
"players/ted/frost/cave11", "northeast",
"players/ted/frost/cave4", "northwest",
"players/ted/frost/cave2", "south"
    });
  }
}
