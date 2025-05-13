inherit "/room/room";
#define PATH "/players/goldsun/green_island/room/"
#define TP this_player()
#define TO this_object()

void clean_player(object pl){
 object *all;
 int i;

 all=all_inventory(pl);
 for(i=0;i<sizeof(all);i++){
   if ( all[i]->id("goldsun_pass_over_abyss")) destruct(all[i]);
 }
}

reset(arg){
if (!arg){
 clone_list=({1,15,"stones","/players/goldsun/green_island/obj/stones",0});
 set_light(1);
 short_desc=("On a plain");
 long_desc=
   ("You are standing on the high, beautiful green plain. The grass is\n"+
    "waving in the wind and the drops of dew are shining in the sunbeams.\n"+
    "The small white rocks lie somewhere on grass. The plain continues\n"+
    "to the east, southeast and northwest. You can see a great castle\n"+
    "to the west, but there is a deep abyss between you and castle.\n"+
    "From the abyss you can hear a crackle of sea waves. You can't see\n"+
    "any connection from here to  castle.\n" );

 smell="You smell fresh sea air.";
 
 dest_dir=({ PATH + "hill4",   "northeast",
             PATH + "hill3",   "east",
	     PATH + "hill1",   "southeast"});
 
 items=({"grass","A very nice grass with drops of dew",
	 "drops","The drops of dew. They looks like diamonds"
	 "rock","A white rock. It lies on the grass",
	 "rocks","Several rocks. They lie on the grass" 
	 "abyss","It looks very deep and deadly",
         "sea","The sea rustles deep under you",
         "plain",long_desc,
	 "castle","Who can live in it? It looks impregnable"
         });
 }
 ::reset(arg);

}

 init(){
  ::init();
  add_action("lsten","listen");
  add_action("g_west","west");
  }

int g_west(){

 if (present("goldsun_pass_over_abyss",TP)){
    TP->move_player("west#/players/goldsun/green_island/room/outside_gates");
    clean_player(TP);
    return 1;
 } 
 write("You make a step to the west.\nYou step in nowhere.\n\n\nAAAaaaaaaa\n"+
     "\nYou are falling.\n\nAAAaaaaaaaaaaaaa\n\nOUCH\nIt hurts you.\n");
 TP->move_player("west#/players/goldsun/green_island/room/sea12");
 TP->hit_player(60+random(30));  /* deadly is deadly */
 return 1;
}

	
int lsten(){
      write("You can hear a crackle of sea waves from the abyss.\n"); 
      say(TP->query_name()+" listens.\n");
  return 1;
}              

