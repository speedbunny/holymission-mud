inherit "room/room";
  
int counter,fcounter;

reset(arg){
  counter=0;
  fcounter=0;
   
 if(arg) return;
  set_light(1);
  short_desc="A hunting ground on the island";     

long_desc="You are now walking across the vast plains of sand that spread " +
              "across the island.  The scenery here is not even worth a mention. " +
              "Just sand, everywhere, and two scorching hot suns glaring down evilly " +
              "from the sky.  You sense danger here, there are many tracks and signs " +
              "of a struggle.  It is obvious that sand people and bounty hunters alike " +
              "scout this area for the elusive Krayt Dragon, a legendary creature of " +
              "strength and beauty to rival the most determined of opponents.\n\n";

dest_dir=({               "/players/redsexy/jedi/areas/island/29.c", "southwest",
                          "/players/redsexy/jedi/areas/island/37.c", "north",     });

items = ({    "view","Sand spreads out in front of you, behind you, everywhere.",            
              "plains","Sand spreads out in front of you, behind you, everywhere.",            
              "island","The whole island is just a sandy desert surrounded by sea.",
              "wind","No wind blows here, and the harsh sunshine burns your skin. ",	    
              "sea","You cannot see the sea from here",	    
              "scenery","Sand spreads out in front of you, behind you, everywhere.",	    
              "sand", "The sand is like cinders, burning your poor feet.",
              "suns", "Two scorching hot suns, burning your skin as they glare upon you.",
              "sun","Two scorching hot suns, burning your skin as they glare upon you.",
       	  "tracks","Many footprints and tracks make the sand hard underfoot ",
	        "footprints","Many footprints and tracks make the sand hard underfoot ",
              "sand people","There are no sandpeople here",
              "people","There is no life of any kind to be seen around here",
              "signs","Signs of a massive fight, blood stains and bones lay scattered",
              "bones","Decomposing bones and skin make you feel sick to the stomach",
              "bloodstains","The sand has brownish red patches in places which look like blood",
              "dragon","There is no sign of the Krayt Dragon here"             });

clone_list=({   1, 5, "sanperson", "/players/redsexy/jedi/monsters/sandperson", 0
         
              });
 
    ::reset();

}

init(){
 ::init();
   add_action("_search","search");
   add_action("_dig","dig");
}

_search(arg){
  object ob;
   
 if(!arg) return;
  if(arg!="sand" && arg!="for treasure") { return; }
  else if(arg=="for treasure") { arg=="sand"; }
  if (arg=="sand") {
    if(fcounter >= 10) {
 	write( "You find some sand.\n" +
               "But as you try to get it, it slips through your fingers.\n" );
         return 1;
      }
    else if (fcounter != 5) {
         write("You find some sand.\n");
         say(this_player()->query_name()+" searches the sand.\n");
         ob=clone_object("/players/redsexy/objects/sand");
         if (transfer(ob,this_player())) {
            write("But you can't carry that much.\n");
            destruct(ob);
            return 1;
         }
    fcounter++;
    return 1;
      }
      else {
         arg = "for treasure";
         fcounter++;
      }
   }
   
  if(arg=="for treasure"){
    if(counter<1){
         write("You find a treasure chest!\n");
         say(this_player()->query_name()+" searches the sand.\n");
         ob=clone_object("/players/redsexy/objects/chest");
         if (transfer(ob,this_player())) {
            write("But you can't carry that much.\n");
            destruct(ob);
            return 1;
         }
            
    counter = 1;
    return 1;
      }
   }      
   write("You search and search, but find nothing.\n");
   say(this_player()->query_name()+" searches around.\n");
   return 1;
}

int _dig(string str) {
   if(str!="sand") return 0;
   write("You don't think digging would be productive,\n" + "but maybe if you looked a little more thoroughly? \n");
   return 1;


   }
