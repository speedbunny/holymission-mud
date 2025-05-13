/* Changed by Ethereal Cashimor, now also includes smellsetting */
/* Checked File - Exos 961028 */

inherit "players/cashimor/inherit/water";

reset(arg) {
  if(!arg) {
    short_desc="Swimming in small lake";
    long_desc="You're swimming in a small, beautiful lake in the\n"
            + "forest. The lake is surrounded by tall trees, but\n"
            + "to the south you notice a clearing that looks\n"
            + "extraordinary nice. The lake itself looks very deep.\n";
    set_light(1);
    dest_dir=({"players/padrone/outside/north_shore","north",
               "players/padrone/outside/nice_place","south"});
    floats="players/padrone/outside/lake_bottom";
    smell="The air is very fresh here.";
    nodanger=1;
  }
  ::reset(arg);
}

init() {
  ::init();
  this_player()->set_smell("Very fresh. "
                         + capitalize(this_player()->query_pronoun())
                         + " probably took a dive somewhere.");
  add_action("dive","dive");
}

dive() {
  this_player()->move_player("down#players/padrone/outside/lake_bottom");
  return 1;
}
