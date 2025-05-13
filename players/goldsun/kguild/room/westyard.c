inherit "room/room";

reset(arg) {
clone_list=({1,1,"gardener","obj/monster",({"set_name","gardener",
				"set_alias","dwarf",
				"set_level",13,
				"set_gender",1,
				"set_short","A gardender",
				"set_long",
	"The gardener goes about his business, pruning and digging, making sure that\n"+
        "the courtyard looks nice.\n"}),
	-1,1,0,"obj/money",({"set_money",500})});

   set_light(1);
   short_desc = "Courtyard";
   long_desc = "You stand at the west end of a beautiful courtyard. "+
               "While many flowers are still in bloom, it looks as if "+
               "the gardener has been at work recently.  To the west "+
            "is a beautiful stony passage, while the courtyard continues to "+
                "the east.\n";

   smell = "The air is sweet";

   dest_dir = ({"players/goldsun/guild/room/centeryard","east",
	        "/players/goldsun/guild/room/roundtable","west"});

   items = ({
   "courtyard","It is beautifully decorated.  In the center is a large statue",
   "statue","It is a large statue of the king....obviously not life-sized",
   "flowers","Roses, tulips, lilacs...the usual sort",
   "rose","'This a rose...and a beautiful one",
   "roses","Rows of various colores rose bushes adorn the yard",
   "tulip","A tulip!  How lovely!",
   "tulips","You've always thought that Two lips are better better than one!\n"+
                         "(Bad pun, I know...)",
   "lilac","The lilac is sweetly scented",
   "lilacs","The lilac bush is in full bloom and a nice deep lavender color",
   "castle","It's the king's palace. It is nicely decorated",
   "shrubs","lots of shrub sculputres",
   "shrub","Look! Its a shrub sculpture of a....a.....shrub!",
   "flower","A rose, how lovely!",
   "palace","It's the Carmaalot palace. It is nicely decorated"});
::reset(arg);
replace_program("room/room");}


