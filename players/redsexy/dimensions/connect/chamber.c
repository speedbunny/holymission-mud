inherit "room/room";

reset(arg) {     
       
       set_light(1);
       short_desc="The chamber of Sophillicus.";     
       long_desc="\
This quiet room lies at the heart of the dimensions.  Very simply \
decorated, with just a chair and table, you realise that the man \
who sits here must be a great master of some kind.  He looks deep \
in thought, contemplating the direction and come to take tests and improving of his students. \n\n";

  dest_dir=({"/players/redsexy/dimensions/connect/1","north",
             "/players/redsexy/dimensions/connect/2","northeast",
             "/players/redsexy/dimensions/connect/3","east",
             "/players/redsexy/dimensions/connect/4","southeast",
             "/players/redsexy/dimensions/connect/5","south",
             "/players/redsexy/dimensions/connect/6","southwest",
             "/players/redsexy/dimensions/connect/7","west",
             "/players/redsexy/dimensions/connect/8","northwest",


          });


  items=({"room","The chamber of Sophillicus",
          "chamber","The chamber of Sophillicus",
          "note","You can read the note on the table...",
          "chair","A black chair",
          "table","There is a note on the table",
          "light","A dim light shines in from the corridors",
         });
   
   clone_list=({
          1, 1, "sophillicus", "/players/redsexy/dimensions/monsters/sophillicus", 0,
  });

::reset(arg);

}

void init(){
   add_action("_read","read"),
   ::init();
}


int _read(string str) {


   if(str!="note") return 0;
   write("The note reads as follows:\n\n");
   write("I seek someone to replace me as the Master of the Dimensions.\n");
   write("Whoever so taketh over my position must possess a great knowledge\n");
   write("and understanding of the creatures who come to take tests and improve here.  They must first\n");
   write("approach each domain keeper and prove themselves worthy.  Once they\n");
   write("have completed this task they must come to me and take my test.\n");
   write("Then if they can solve the puzzle of the dimensions, I will have no\n");
   write("qualms about handing over my title.\n");

   return 1;
}


