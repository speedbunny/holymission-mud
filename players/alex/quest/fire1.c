inherit "room/room";
   reset(arg) { 
      if (arg) return;
 
    set_light(1);
  short_desc = "Fire room. ";
 long_desc = "You are in the hall of the fire elementals cavern.  The walls\n"+
             "seem alive as the fire that they are made of twists and weaves\n"+
             "you are glad of the coolness that the pearl imparts to you.\n";
 
items=({
 
        "fire",
        "It is so hot that you can not get to close to look at it however\n"+
        "one thing of which you are sure is that  IT IS VERY HOT!!!!!!",
 
        "bubble",
        "This bubble was bought into exsistance by the opal that you now carry\n"+
        "it will alow you to breath in this endless sea of flame",
 
        "ground",
        "The chunk of ground seems to fall away as you leave it behind and\n"+
        "form up ahead.",
        "air","It is all around you and you are sure that if you did not have \n"+
              "the diamond that you would fall endlessly...........",
 
        "shower",
        "The shower is cool and invigorating and is no doubt keeping you alive",
    
        "walls",
        "The fire hisses at you as you step forward to examine the wall",
         
       });
       
 
dest_dir = ({
             "players/alex/quest/fire4","north",
             "players/alex/quest/fire2","east",
             });
}
init() {
#define TP this_player()
add_action("burst","burst");
::init();
}
 
burst (str)
{
   string thing; 
 
   if(!str)
   {
      notify_fail("Burst what?\n");
      return 0;
   }
   if(sscanf(str,"%s",thing)==1);
   {
      if(str != "bubble")
      {
         notify_fail("No! I think not\n");
         return 0;
      }
      printf("As you try to burst your life giving bubble, a few smaller bubbles \n"+
             "form taking away your precious air.  ARE YOU NUTS OR WHAT??\n");
        TP->hit_player(random(4)+2);
      return 1;
    }
    return 0;   
}
 
