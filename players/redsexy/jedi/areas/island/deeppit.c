inherit "room/room"; 

reset (arg) { 
    if (arg) return; 

    set_light(1); 
    smell="The air smells of the blood of other adventurers combined with the\n" +
          "stench of the almighty Sarlacc.\n";

    short_desc="The Sarlacc's Pit"; 
    long_desc="You feel as if you are encased in a tomb of heat and blood " +
              " as you enter the Great Pit of Carkoon. Although the area is" +
              " spacious around you, the giant body of the Sarlacc blocks " +
              " the sunlight and your passageway out of here.  You could" +
              " almost suffacate from the smell, the air is so putrid and" +
              " stale, but somehow, you manage to retain conciousness.\n\n";

items = ({
            "pit","This is the Great Pit of Carkoon where the Sarlacc lives",
            "creature","The creature is the much fabled Sarlacc",              
     	      "hole","The hole is giantic, and the sarlacc lives down there",
            "sand","You're worrying about sand when you face the mighty sarlacc??!!"
            "tomb","The Sarlacc's body is so large it touches the walls either side",
            "walls","The walls have bones and fossils in them",
            "bones","The bones of other adventurers are scattered on the floor and sticking out the walls",
            "fossils","They are embedded into the walls, you think they would hold your weight",
            "blood","The blood spilled from other adventurers who faced the Sarlacc",
            "body","The Sarlacc's body is so large it touches the walls either side",
            "heat","It is sweltering hot down here, an unbearable sauna",
            "sunlight","No sunlight shines past the enermous body of the Salracc",
            "passageway","No, don't be silly, there's no passageway here",
            });


clone_list=({   1, 1, "sarlacc", "/players/redsexy/jedi/monsters/sarlacc", 0
  
              });
::reset();
}

void init() {
   ::init();
   add_action("_climb","climb");
   }

int _climb(string str) {
   if (str=="walls" || str=="fossils" || str=="bones") {
   write("You expertly scale the walls out of here. \n");
   this_player()->move_player("up the walls to freedom.#players/redsexy/jedi/areas/island/pit.c");
   return 1;
   }
}
