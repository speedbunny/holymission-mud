
inherit " ";

reset ( arg) {
   ::reset ( arg );
   if ( !arg) {
      set_name("carpet");
      set_short("A flying carpet is hovering in the air");
      set_long(
"The flying carpet hovers around a bit, then tentatively moves a few"+
"inches. It seems to have forgotten where to go next. It looks at"+
"you with sad, trusting eyes (Well, not exactly eyes, because it"+
"doesn't have them, and it doesn't look exactly sad or trusting,"+
"because a magic carpet can't really be sad or especially trusting"+
"to anyone but itself, anyway, you conclude that it WOULD look sad"+
"(and a bit trusting, like a small dog) if it were somehow able to"+
"do so. Anyway, the impression's there.)"+
"The carpet has a small sign attached to it, that reads:"+
"           Personal property of Gorlin the Elephant"+
"               Don't steal me, or my master will"+
"                 certainly be upset... *smile*\n");
      set_weight(0);
      set_value(0);
   }
   return 1;
}

init()
{
   add_action("board","board");
}

board(str)
{
   if (str=="carpet") {
      write("You board the magically flying carpet.\n");
      say(capitalize(this_player()->query_name())+" climbed onto the flying carpet.\n");
      move_living(this_player(),"/players/gorlin/carpet/oncarpet");
}

