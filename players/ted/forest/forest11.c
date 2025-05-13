inherit "room/room";

int i;
object orc, warg, money;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc = "Dread Forest";
    long_desc =
"A large circle has been cleared of trees and bushes here.\n"+
"It looks well used. Bones and pieces of broken weapons\n"+
"and armor lie scattered around the edge of the clearing.\n"+
"In the center is a large raised mound with a crude kind\n"+
"of throne on it.\n";
    dest_dir = ({
"players/ted/forest/forest21", "south",
"players/ted/forest/forest12", "east"
    });
    items = ({
"mound","This is a large mound of dirt, almost in the center\n"+
        "of the clearing",
"throne","This throne is made of stout timber and adorned\n"+
         "with human skulls!!"
    });
  }
  if(!present("orc chieftan")) {
    i = 0;
    while(i<2) {
      i ++;
      orc = clone_object("players/ted/monsters/orc_chieftan");
      move_object(orc, this_object());
      call_other("players/ted/random_armor","make_item",orc,5);
      call_other("players/ted/random_weapon","make_item",orc,5);
    }
  }
  i = 0;
  if(!present("warg")) {
    while(i<3) {
      i ++;
      warg = clone_object("players/ted/monsters/warg");
      move_object(warg, this_object());
      money = clone_object("obj/money");
      call_other(money, "set_money", 50+random(100));
      move_object(money, warg);
      call_other("players/ted/random_treasure","make_item",warg,5);
    }
  }
}
