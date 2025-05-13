inherit "room/room";

reset(arg){
 if(!arg){

   set_light(1);
   short_desc = "Beslik house";
   long_desc = 
"This is the Home of Mr. and Mrs. Beslik. They are still young Trogs and do "+
"not have any children yet. The house is of simple furnishings, like so many "+
"Trog dwellings.\n";

   dest_dir = ({"players/airborne/new/town4", "south" });
 
   items = ({"furnishings", "Simple, modest furnishings", });

if(!present("mr. beslik", this_object())){
object mr;

	mr = clone_object("obj/monster");
	mr-> set_name("mr. beslik");
	mr-> set_alt_name("beslik");
	mr-> set_alias("mr");
	mr-> set_short("Mr. Beslik");
	mr-> set_long("Mr. Beslik.\n");
	mr-> set_gender(1);
	mr-> set_level(7);
	mr-> set_dex(20);
	mr-> add_money(100);
	mr-> set_ac(8);
	mr-> set_wc(7);
        	move_object(mr, this_object());
	}

if(!present("mrs. beslik", this_object())){
object mrs;

	mrs = clone_object("obj/monster");
	mrs-> set_name("mrs. beslik");
	mrs-> set_alt_name("beslik");
	mrs-> set_alias("mrs");
	mrs-> set_short("Mrs. Beslik");
	mrs-> set_long("Mrs. Beslik.\n");
	mrs-> set_gender(2);
	mrs-> set_level(7);
	mrs-> set_ac(5);
	mrs-> set_wc(5);
		move_object(mrs, this_object());
		}

	}
}

