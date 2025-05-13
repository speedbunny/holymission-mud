inherit "players/redsexy/jedi/areas/island/inherit";

reset (arg) {     
if (arg) return;     

set_light(1);     
short_desc="A calm place on the shoreline of Carkoon";     

long_desc="Walking across the shoreline now, the sea seems calmer and more"+
	    " relaxing.  The sand here is coarser than any other you have seen"+
          " and it cuts like splinters of glass when it touches your skin."+  
          "  This is no ordinary island"+
          " though, it is more like a desert and two evil suns beat down on"+          
          " you.  Luckily the wind blows in from the sea, keeping you cool and"+
          " alert.  You feel as if you will need your wits about you should you"+              
          " venture any further\n\n";    

dest_dir=({              "/players/redsexy/jedi/areas/island/1.c", "northwest",              
                         "/players/redsexy/jedi/areas/island/3.c", "northeast",              
                         "/players/redsexy/jedi/areas/island/25.c", "south",                   
});

items = ({            "view","The sea spreads out in front of you, like a blanket of blue",            
                      "waves","The waves are still high, but the water looks calmer",            
                      "sand","The sand is white hot, and it burns you as it touches your skin.",              	    
                      "wind","Harsh and cold, the wind howls across the sea.",	    
                      "sea","The sea leaves you spellbound. Never before has nature been so powerful",	    
                      "dune sea","The sea leaves you spellbound. Never before has nature been so powerful",	    
                      "sun", "Two suns shine down, as if you were in a galaxy far away",            
                      "desert","Miles and miles of sand",            
                      "shoreline","A rugged coast which you are following",            });
}

void init() {


   ::init();


   add_action("_search","search");

   }



int _search(string str) {


   if(str!="sand") return 0;
   write("You furrow through the sand methodically, but there is no hidden treasure here. \n");
   return 1;


   }