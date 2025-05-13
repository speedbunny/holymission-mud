inherit "/players/patience/GenObj/tree";


reset( arg )
{
   if ( arg )
      return;
  
   set_light(1);
   set_tree();
   set_door_state(1);
   set_short_desc();
   set_long_desc();
   /*
   short_desc = "On a path";
   long_desc = "You're wandering along a fast flowing river.\n" +
                "There are some stones lying on the ground.\n" +
                "To the south you see the mill of the old hobbit Hobbe.\n";
   
   items = ({ "stones","Some heavy grey stones",
              "ground","You see some heavy stones lying in the grass",
              "grass","The grass is dew-drenched",
              "sky","You see the blue sky",
              "mill","You see a large watermill",
              "river","You see a big blue river which seems too deep to enter",
              "water","You see yourself !!!!",
           });
   
   dest_dir = ({ PPATH + "path4","northeast",
                 PPATH + "path2","south",
              });*/
}


init( )
{
   ::init( );
}


