inherit "room/room";

object troll, money;
int i;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Small Bridge";
    long_desc =
"A small wooden bridge leads across a frozen\n"+
"stream. The smell of rotting flesh comes from\n"+
"the corpses of small animals and fish which\n"+
"lie on either side of the stream.\n";
    dest_dir = ({
"players/ted/cold/ice_south", "north",
"players/ted/cold/snow", "south"
    });
  }
  i = 0;
  if(!present("ice troll")) {
    while(i < 3) {
    i += 1;
    troll = clone_object("players/ted/monsters/ice_troll");
    move_object(troll, this_object());
    money = clone_object("obj/money");
    call_other(money, "set_money", random(200)+100);
    move_object(money, troll);
  }
 }
}
