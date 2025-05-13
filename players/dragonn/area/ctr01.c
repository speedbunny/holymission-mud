//Dragonn-coderrrrio...'96
#define CO clone_object
#define TP this_player()

inherit "room/room";
 object guard,helmet,sword;
reset(arg){
::reset(arg);
if(arg) return;

/******************MONSIE COMING HERE *******/

     if (!guard){
          guard=CO("obj/monster");
          helmet=CO("obj/armour");
          sword=CO("obj/armour");

           guard->set_name("guard");
           guard->set_short("Guard of country Pavi");
           guard->set_long("The great guard of a country known as Pavi.\n"+
               "He is very smart, so better not attack \n"+
               "him or he might kill you.\n");
           guard->set_race("human");
           guard->set_lev(35);
           guard->set_hp(1850);
           guard->set_al(50);
           guard->add_money(random(1000)+2000);
           guard->set_wc(random(30));
           guard->set_ac(random(30));
           guard->set_aggressive(0);
           guard->set_chance(5);
           guard->set_damage(50);

           helmet->set_name("helmet");
           helmet->set_short("Guard's helmet");
       helmet->set_long("The green helmet of a country Pavi guard.\n");
           helmet->set_ac(2);
           helmet->set_value(700);
           helmet->set_weight(-2);
           helmet->set_type("helmet");

           sword->set_name("sword");
           sword->set_short("Green sword");
    sword->set_lomg("The green sword of a country Pavi guard.\n");
           sword->set_class(15);
           sword->set_value(2000);
   sword->set_weight(2);


           move_object(guard,this_object());
           move_object(helmet,guard);
           move_object(sword,guard);
}

if(arg) return;
    set_light(1);
    short_desc= "The Countryside of Pavi";
    long_desc=
"You are walking through the beautiful countryside of Pavi. "+
"From where you stand, you can see beautiful green grass "+
"growing in the sunshine, sprinkled with wild flowers "+
"and small shrubs.\n";


    dest_dir=({
         "players/dragonn/area/ctr08", "south",
     "players/dragonn/area/start", "west",
               "players/dragonn/area/ctr02", "east",
             });

    items=({ 
            "shrubs","You notice many small shrubs"+
                     " growing from the ground in the distance",
            "grass","You notice beautiful green grass growing everywhere"+
                    " except for the trail you are standing on",
            "pavi","You are standing in the beautiful countryside located "+
                   "in Pavi",
          });
}
