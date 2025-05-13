inherit "room/room";

object gal,last_warned;
status is_warning;

reset(arg) {
 if (!gal){
  gal=clone_object("/players/goldsun/guild/monster/gal_perceval");
  tell_room(this_object(),"Knight Gal Perceval arrives.\n");
  transfer(gal,this_object());
  }

 if (!arg){
   is_warning=0;
   set_light(1);
   short_desc = "Courtyard";
   long_desc = 

  "You stand in the center of a beautiful courtyard.\n"+
  "While many flowers are still in bloom, it looks as if\n"+
  "the gardener has been at work recently. The courtyard\n"+
  "continues to the west and east. To the north and south\n"+
  "you noticed passages. The knights can fight in tournament here.\n";

   smell = "The air is sweet";

   dest_dir = ({"players/goldsun/guild/room/westyard","west",
	        "players/goldsun/guild/room/eastyard","east",
	        "players/goldsun/guild/room/conference","south",
	        "players/goldsun/guild/room/traininghall","north"
		});

   items = ({
    "passage","It is small",
    "courtyard","It is beautifully decorated.  In the center is a large statue",
    "flowers","Roses, tulips, lilacs...the usual sort",
    "rose","'Tis a rose...and a beautiful one",
    "roses","Rows of various colores rose bushes adorn the yard",
    "tulip","A tulip!  How lovely!",
   "tulips","You've always thought that Two lips are better better than one!\n"+
                           "(Bad pun, I know...)",
   "lilac","The lilac is sweetly scented",
   "lilacs","The lilac bush is in full bloom and a nice deep lavender color",
   "castle","It's the Carmaalot castle.  Large and nicely\n"+
                               "decorated",         
   "shrubs","lots of shrub sculputres",
   "shrub","Look! Its a shrub sculpture of a....a.....shrub!",
   "flower","A rose, how lovely!"});
 }
::reset(arg);

}

init(){
 ::init();
add_action("go_s","south");
}

go_s(){

 if (this_player()->query_level()<25){  /* ADD here: && is_knight !!! */
   
if (!is_warning) last_warned=this_player();   /* is_warning sets to 1 in */
                                              /*   next lines           */
   if (!gal){
     gal=clone_object("/players/goldsun/guild/monster/gal_perceval");
     tell_room(this_object(),"Knight Gal Perceval arrives.\n");
     transfer(gal,this_object());
   }
   
  if ((is_warning) && (last_warned==this_player())) gal->bar_way_2(this_player());
   else{
     gal->bar_way_1(this_player());
     last_warned=this_player();
     is_warning=1;
    }

  return 1;
 }

 return ::move("south");

}
 
