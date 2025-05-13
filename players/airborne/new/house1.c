inherit "room/room";

reset(arg){
int i;

 if(!arg){

   set_light(1);
   short_desc = "Toldok household";
   long_desc = 
"You have entered the home of the Toldok family. The house is not very big "+
"but then again, neither are the Trogs. Only the barest necessities can be "+
"seen here; a table, chairs, a fireplace, and of course, the Toldok family.\n";

    dest_dir = ({"players/airborne/new/town3", "south", });

    items = ({"house", "The house of the Toldok family",
	"table", "A very old looking stone table",
	"chairs", "Six fine chairs",
        "fireplace", "The warm fireplace is keeping the house lit", });

    property = ({"has_fire"});


i = 0;
if(!present("kid", this_object())){
object kid;

   while(i < 4){
   i+= 1;
   	kid = clone_object("players/airborne/new/monsters/trogkid");
	move_object(kid, this_object());
	}
	}
if(!present("mommy trog", this_object())){
object mom;

    mom = clone_object("obj/monster");
    mom-> set_name("mommy trog");
    mom-> set_alt_name("mommy");
    mom-> set_alias("trog");
    mom-> set_race("trog");
    mom-> set_gender(2);
    mom-> set_short("Mommy Toldok");
    mom-> set_long("Mommy Toldok.\n");  
    mom-> set_level(10);
 	move_object(mom, this_object());
	}

if(!present("daddy trog", this_object())){
object dad;

    dad = clone_object("obj/monster");
    dad-> set_name("parent");
    dad-> set_alt_name("daddy");
    dad-> set_alias("trog");
    dad-> set_race("trog");
    dad-> set_gender(1);
    dad-> set_level(10);
    dad-> set_short("Daddy Toldok");
    dad-> set_long("Daddy Toldok.\n");
	move_object(dad, this_object());

	}
    }
}
