inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;    
set_light(1);     

     short_desc="The port town of Carkoon";
     long_desc="You have reached the edge of this small town now, " +
              "and there is nothing much to see here.  This area seems " +
              "to have been set aside for children to play in and your sense " +
              "of irony makes you laugh when you notice a sandpit by the shore. \n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/other/t2.c", "east", 
                         "/players/redsexy/jedi/areas/island/3.c", "south",});
items = ({                  
              "sandpit", "A pit full of sand, perhaps you could enter it?",
              "suns", "Two scorching hot suns, burning your skin as they glare upon you.",
              "sun","Two scorching hot suns, burning your skin as they glare upon you.",
              "sheets","Sheets draped over wooden poles that form a makeshift shelter",
	        "ground","The ground is hard because the sand here is so well trodden",
              "sand","Well trodden sand"
  });
}
void init() {


   ::init();


add_action("_enter","enter");
}

int _enter(string str) {
   if(str!="sandpit") return 0;
   write("Your childish playfullness has made you want to recapture your youth!\n");
   this_player()->move_player("into the sandpit!.#players/redsexy/jedi/areas/island/other/sandpit");
   return 1;
}




